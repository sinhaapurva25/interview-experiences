// Source file for the image viewer program



// Include files 

#include "R2/R2.h"
#include "R2Pixel.h"
#include "R2Image.h"
#include "fglut/fglut.h"
#include <vector>
using namespace std;


// Command-line program arguments

static char *input_source_image_name = NULL;
static char *input_target_image_name = NULL;
static char *input_correspondence_name = NULL;
static char *output_correspondence_name = NULL;
static int print_verbose = 0;



// Data variables

static R2Image *source_image = NULL;
static R2Image *target_image = NULL;
static float *source_pixels = NULL;
static float *target_pixels = NULL;
static vector<R2Segment *> segments;
static R2Segment current_segment;


// GLUT interface variables 

static int GLUTwindow = 0;
static int GLUTwindow_height = 640;
static int GLUTwindow_width = 640;
static int GLUTmouse[2] = { 0, 0 };
static int GLUTbutton[3] = { 0, 0, 0 };
static int GLUTmodifiers = 0;
static int GLUTncolors = 24;
static GLfloat GLUTcolors[24][3] = {
  {1,0,0}, {0,1,0}, {0,0,1}, {1,0,1}, {0,1,1}, {1,1,0}, 
  {1,.3,.7}, {1,.7,.3}, {.7,1,.3}, {.3,1,.7}, {.7,.3,1}, {.3,.7,1}, 
  {1,.5,.5}, {.5,1,.5}, {.5,.5,1}, {1,.5,1}, {.5,1,1}, {1,1,.5}, 
  {.5,0,0}, {0,.5,0}, {0,0,.5}, {.5,0,.5}, {0,.5,.5}, {.5,.5,0} 
};



////////////////////////////////////////////////////////////////////////
// Input/Output Functions
////////////////////////////////////////////////////////////////////////

static R2Image *
ReadImage(const char *filename)
{
  // Allocate image
  R2Image *image = new R2Image();
  if (!image) {
    fprintf(stderr, "Unable to allocate image\n");
    return NULL;
  }

  // Read image
  if (!image->Read(filename)) {
    fprintf(stderr, "Unable to read image\n");
    return NULL;
  }

  // Return image
  return image;
}



static float *
CopyPixelsIntoFloatArray(R2Image *image)
{
  // Allocate array of floats
  float *pixels = new float [ 4 * image->NPixels() ];
  if (!pixels) {
    fprintf(stderr, "Unable to allocate array of pixels\n");
    return NULL;
  }

  // Copy pixels
  float *pixelsp = pixels;
  for (int j = 0; j < image->Height(); j++) {
    for (int i = 0; i < image->Width(); i++) {
      const R2Pixel& pixel = image->Pixel(i, j);
      for (int k = 0; k < 4; k++) {
        *(pixelsp++) = pixel[k];
      }
    }
  }

  // Return array of floats
  return pixels;
}



static int 
ReadCorrespondences(char *filename, 
  const R2Image *source_image, const R2Image *target_image,
  vector<R2Segment *>& segments) 
{
  // Open file
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    fprintf(stderr, "Unable to open correspondences file %s\n", filename);
    exit(-1);
  }

  // Read number of segments
  int num_segments;
  if (fscanf(fp, "%d", &num_segments) != 1) {
    fprintf(stderr, "Unable to read correspondences file %s\n", filename);
    exit(-1);
  }

  // Read segments
  for (int i = 0; i <  num_segments; i++) {
    // Read source segment
    double sx1, sy1, sx2, sy2;
    if (fscanf(fp, "%lf%lf%lf%lf", &sx1, &sy1, &sx2, &sy2) != 4) { 
      fprintf(stderr, "Error reading correspondence %d out of %d\n", i, num_segments);
      exit(-1);
    }

    // Create source segment
    R2Segment *source_segment = new R2Segment(sx1, sy1, sx2, sy2);
    if (!source_segment) {
      fprintf(stderr, "Unable to create segment\n");
      exit(-1);
    }

    // Add segment to list
    segments.push_back(source_segment);

    // Read target segment
    double tx1, ty1, tx2, ty2;
    if (fscanf(fp, "%lf%lf%lf%lf", &tx1, &ty1, &tx2, &ty2) != 4) { 
      fprintf(stderr, "Error reading correspondence %d out of %d\n", i, num_segments);
      exit(-1);
    }

    // Increment X coordinate of target segment (because target is shown on right)
    tx1 += source_image->Width();
    tx2 += source_image->Width();

    // Create target segment
    R2Segment *target_segment = new R2Segment(tx1, ty1, tx2, ty2);
    if (!target_segment) {
      fprintf(stderr, "Unable to create segment\n");
      exit(-1);
    }

    // Add segment to list
    segments.push_back(target_segment);
  }

  // Close file
  fclose(fp);

  // Return success
  return 1;
}



static int 
WriteCorrespondences(char *filename, 
  const R2Image *source_image, const R2Image *target_image,
  const vector<R2Segment *>& segments) 
{
  // Open file
  FILE *fp = fopen(filename, "w");
  if (!fp) {
    fprintf(stderr, "Unable to open correspondences file %s\n", filename);
    exit(-1);
  }

  // Separate source and target segments
  vector<R2Segment *> source_segments;
  vector<R2Segment *> target_segments;
  for (unsigned int i = 0; i < segments.size(); i++) {
    R2Segment *segment = segments[i];
    if (segment->Start().X() < source_image->Width()) source_segments.push_back(segment);
    else target_segments.push_back(segment);
  }

  // Partition segments
  unsigned int num_segments = source_segments.size();
  if (num_segments > target_segments.size()) {
    num_segments = target_segments.size();
  }

  // Write number of segments
  fprintf(fp, "%d\n", num_segments);

  // Write segments
  for (unsigned int i = 0; i < num_segments; i++) {
    R2Segment *source_segment = source_segments[i];
    R2Segment *target_segment = target_segments[i];
    int sx1 = (int) (source_segment->Start().X() + 0.5);
    int sy1 = (int) (source_segment->Start().Y() + 0.5);
    int sx2 = (int) (source_segment->End().X() + 0.5);
    int sy2 = (int) (source_segment->End().Y() + 0.5);
    int tx1 = (int) (target_segment->Start().X() + 0.5) - source_image->Width();
    int ty1 = (int) (target_segment->Start().Y() + 0.5);
    int tx2 = (int) (target_segment->End().X() + 0.5) - source_image->Width();
    int ty2 = (int) (target_segment->End().Y() + 0.5);
    fprintf(fp, "%6d %6d  %6d %6d   ", sx1, sy1, sx2, sy2);
    fprintf(fp, "%6d %6d  %6d %6d\n", tx1, ty1, tx2, ty2);
  }

  // Close file
  fclose(fp);

  // Return success
  return 1;
}



////////////////////////////////////////////////////////////////////////
// GLUT Interface Functions
////////////////////////////////////////////////////////////////////////

static void 
GLUTRedraw(void)
{
  // Clear window 
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw source image
  glRasterPos2i(0, 0);
  glDrawPixels(source_image->Width(), source_image->Height(), GL_RGBA, GL_FLOAT, source_pixels); 

  // Draw target image
  glRasterPos2i(source_image->Width(), 0);
  glDrawPixels(target_image->Width(), target_image->Height(), GL_RGBA, GL_FLOAT, target_pixels);

  // Draw segments 
  int source_count = 0;
  int target_count = 0;
  for (unsigned int i = 0; i < segments.size(); i++) {
    R2Segment *segment = segments[i];

    // Set color
    int color_index = 0;
    if (segment->Start().X() < source_image->Width()) color_index = source_count++; 
    else color_index = target_count++; 
    glColor3fv(GLUTcolors[color_index % GLUTncolors]);

    // Draw start point
    glBegin(GL_POLYGON);
    glVertex2d(segment->Start().X()-3, segment->Start().Y()-3);
    glVertex2d(segment->Start().X()+3, segment->Start().Y()-3);
    glVertex2d(segment->Start().X()+3, segment->Start().Y()+3);
    glVertex2d(segment->Start().X()-3, segment->Start().Y()+3);
    glEnd();

    // Draw line
    glBegin(GL_LINES);
    glVertex2d(segment->Start().X(), segment->Start().Y());
    glVertex2d(segment->End().X(), segment->End().Y());
    glEnd();
  }

  // Draw current segment
  if (GLUTbutton[0]) {
    // Set color
    glColor3d(0.5, 0.5, 0.5);

    // Draw start point
    glBegin(GL_POLYGON);
    glVertex2d(current_segment.Start().X()-3, current_segment.Start().Y()-3);
    glVertex2d(current_segment.Start().X()+3, current_segment.Start().Y()-3);
    glVertex2d(current_segment.Start().X()+3, current_segment.Start().Y()+3);
    glVertex2d(current_segment.Start().X()-3, current_segment.Start().Y()+3);
    glEnd();

    // Draw line
    glBegin(GL_LINES);
    glVertex2d(current_segment.Start().X(), current_segment.Start().Y());
    glVertex2d(current_segment.End().X(), current_segment.End().Y());
    glEnd();
  }

  // Swap buffers 
  glutSwapBuffers();
}    



static void 
GLUTMotion(int x, int y)
{
  // Invert y coordinate
  y = GLUTwindow_height - y;

  // Process mouse motion event 
  if (GLUTbutton[0]) {
    // Keep segment in it's half
    if (current_segment.Start().X() < source_image->Width()) {
      if (x >= source_image->Width()) x = source_image->Width()-1;
    }
    else {
      if (x < source_image->Width()) x = source_image->Width();
    }
      
    // Adjust segment endpoint
    R2Point cursor(x,y);
    current_segment.SetEnd(cursor);
  }

  // Remember mouse position 
  GLUTmouse[0] = x;
  GLUTmouse[1] = y;

  // Redraw
  glutPostRedisplay();
}



static void 
GLUTMouse(int button, int state, int x, int y)
{
  // Invert y coordinate
  y = GLUTwindow_height - y;  
  
  // Process mouse button event
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      // Start tracking segment
      R2Point cursor(x,y);
      current_segment.Reset(cursor, cursor);
    }
    else {
      // Stop tracking segment and add it to list
      R2Segment *segment = new R2Segment(current_segment);
      current_segment = R2Segment(0,0,0,0);
      segments.push_back(segment);
    }
  }

  // Remember button state 
  int b = (button == GLUT_LEFT_BUTTON) ? 0 : ((button == GLUT_MIDDLE_BUTTON) ? 1 : 2);
  GLUTbutton[b] = (state == GLUT_DOWN) ? 1 : 0;

  // Remember modifiers 
  GLUTmodifiers = glutGetModifiers();

   // Remember mouse position 
  GLUTmouse[0] = x;
  GLUTmouse[1] = y;

  // Redraw
  glutPostRedisplay();
}



static void 
GLUTKeyboard(unsigned char key, int x, int y)
{
  // Process keyboard button event 
  switch (key) {
  case 'D': 
  case 'd': 
  case 127: // DELETE
    // Delete last segment
    if (segments.size() > 0) segments.erase(segments.end()-1);
    break;

  case 'S': 
  case 's': 
    // Write file
    WriteCorrespondences(output_correspondence_name, source_image, target_image, segments);
    break;

  case 'Q': 
  case 'q': 
  case 27: // ESCAPE
    // Write file and exit
    WriteCorrespondences(output_correspondence_name, source_image, target_image, segments);
    glutDestroyWindow(GLUTwindow);
    exit(0);
    break;
  }

  // Remember mouse position 
  GLUTmouse[0] = x;
  GLUTmouse[1] = GLUTwindow_height - y;

  // Remember modifiers 
  GLUTmodifiers = glutGetModifiers();

  // Redraw
  glutPostRedisplay();  
}



static void 
GLUTInterface(int argc, char **argv)
{
  // Initialize glut
  glutInit(&argc,argv);

  // Determine window dimensions
  GLUTwindow_width = source_image->Width() + target_image->Width();
  GLUTwindow_height = source_image->Height();
  if (GLUTwindow_height < target_image->Height()) {
    GLUTwindow_height = target_image->Height();
  }

  // Open window 
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(GLUTwindow_width, GLUTwindow_height);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  GLUTwindow = glutCreateWindow("COS 426 Morph Lines");

  // Initialize GLUT callback functions 
  glutDisplayFunc(GLUTRedraw);
  glutKeyboardFunc(GLUTKeyboard);
  glutMouseFunc(GLUTMouse);
  glutMotionFunc(GLUTMotion);

  // Initialize transformation
  glViewport(0, 0, GLUTwindow_width, GLUTwindow_height);
  glMatrixMode(GL_PROJECTION);  
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, GLUTwindow_width, 0, GLUTwindow_height);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  // Initialize drawing modes
  glLineWidth(3);
  glDisable(GL_LIGHTING);

  // Run GLUT interface
  glutMainLoop();
}



////////////////////////////////////////////////////////////////////////
// Program Argument Parsing
////////////////////////////////////////////////////////////////////////

static int 
ParseArgs(int argc, char **argv)
{
  // Parse arguments
  argc--; argv++;
  while (argc > 0) {
    if ((*argv)[0] == '-') {
      if (!strcmp(*argv, "-v")) { print_verbose = 1; }
      else if (!strcmp(*argv, "-input_correspondences")) { argc--; argv++; input_correspondence_name = *argv; }
      else { fprintf(stderr, "Invalid program argument: %s", *argv); exit(1); }
      argv++; argc--;
    }
    else {
      if (!input_source_image_name) input_source_image_name = *argv;
      else if (!input_target_image_name) input_target_image_name = *argv;
      else if (!output_correspondence_name) output_correspondence_name = *argv;
      else { fprintf(stderr, "Invalid program argument: %s", *argv); exit(1); }
      argv++; argc--;
    }
  }

  // Check mesh filename
  if (!input_source_image_name || !input_target_image_name || !output_correspondence_name) {
    fprintf(stderr, "Usage: morphlines input_source_image input_target_image output_correpondence_image [-input_correspondences filename]\n");
    return 0;
  }

  // Return OK status 
  return 1;
}



////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  // Parse program arguments
  if (!ParseArgs(argc, argv)) exit(-1);

  // Read source image
  source_image = ReadImage(input_source_image_name);
  if (!source_image) exit(-1);
  source_pixels = CopyPixelsIntoFloatArray(source_image);
  if (!source_pixels) exit(-1);

  // Read target image
  target_image = ReadImage(input_target_image_name);
  if (!target_image) exit(-1);
  target_pixels = CopyPixelsIntoFloatArray(target_image);
  if (!target_pixels) exit(-1);

  // Read segments
  if (input_correspondence_name) {
    int status = ReadCorrespondences(input_correspondence_name, source_image, target_image, segments);
    if (!status) exit(-1);
  }

  // Run interactive interface
  GLUTInterface(argc, argv);
}

