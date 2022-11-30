 // Source file for image class



// Include files 
#include "R2/R2.h"
#include "R2Pixel.h"
#include "R2Image.h"




////////////////////////////////////////////////////////////////////////
// Constructors/Destructors
////////////////////////////////////////////////////////////////////////


R2Image::
R2Image(void)
  : pixels(NULL),
    npixels(0),
    width(0), 
    height(0)
{
}



R2Image::
R2Image(const char *filename)
  : pixels(NULL),
    npixels(0),
    width(0), 
    height(0)
{
  // Read image
  Read(filename);
}



R2Image::
R2Image(int width, int height)
  : pixels(NULL),
    npixels(width * height),
    width(width), 
    height(height)
{
  // Allocate pixels
  pixels = new R2Pixel [ npixels ];
  assert(pixels);
}



R2Image::
R2Image(int width, int height, const R2Pixel *p)
  : pixels(NULL),
    npixels(width * height),
    width(width), 
    height(height)
{
  // Allocate pixels
  pixels = new R2Pixel [ npixels ];
  assert(pixels);

  // Copy pixels 
  for (int i = 0; i < npixels; i++) 
    pixels[i] = p[i];
}



R2Image::
R2Image(const R2Image& image)
  : pixels(NULL),
    npixels(image.npixels),
    width(image.width), 
    height(image.height)
    
{
  // Allocate pixels
  pixels = new R2Pixel [ npixels ];
  assert(pixels);

  // Copy pixels 
  for (int i = 0; i < npixels; i++) 
    pixels[i] = image.pixels[i];
}



R2Image::
~R2Image(void)
{
  // Free image pixels
  if (pixels) delete [] pixels;
}



R2Image& R2Image::
operator=(const R2Image& image)
{
  // Delete previous pixels
  if (pixels) { delete [] pixels; pixels = NULL; }

  // Reset width and height
  npixels = image.npixels;
  width = image.width;
  height = image.height;

  // Allocate new pixels
  pixels = new R2Pixel [ npixels ];
  assert(pixels);

  // Copy pixels 
  for (int i = 0; i < npixels; i++) 
    pixels[i] = image.pixels[i];

  // Return image
  return *this;
}



////////////////////////////////////////////////////////////////////////
// Utility functions
////////////////////////////////////////////////////////////////////////

static double 
RandomNumber(void) 
{
#if defined(_WIN32)
  int r1 = rand();
  double r2 = ((double) rand()) / ((double) (RAND_MAX + 1));
  return (r1 + r2) / ((double) (RAND_MAX + 1));
#else
  return drand48();
#endif
}



////////////////////////////////////////////////////////////////////////
// Image processing functions
// YOU IMPLEMENT THE FUNCTIONS IN THIS SECTION
////////////////////////////////////////////////////////////////////////

// Luminance Operations ////////////////////////////////////////////////

void R2Image::
AddNoise(double magnitude)
{
  // Add noise to an image.  The amount of noise is given by the magnitude
  // in the range [0.0..1.0].  0.0 adds no noise.  1.0 adds a lot of noise.

#if 1
  // This implementation is provided as an example of one way to manipulate pixels
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      R2Pixel& pixel = Pixel(i, j);
      pixel[0] += magnitude * (RandomNumber() - 0.5);
      pixel[1] += magnitude * (RandomNumber() - 0.5);
      pixel[2] += magnitude * (RandomNumber() - 0.5);
      pixel.Clamp();
    }
  }
#else
  // This implementation is provided as an example of another way to manipulate pixels
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      R2Pixel pixel = Pixel(i, j);
      pixel.SetRed(pixel.Red() + magnitude * (RandomNumber() - 0.5));
      pixel.SetGreen(pixel.Green() + magnitude * (RandomNumber() - 0.5));
      pixel.SetBlue(pixel.Blue() + magnitude * (RandomNumber() - 0.5));
      pixel.Clamp();
      SetPixel(i, j, pixel);
    }
  }
#endif
}



void R2Image::
Brighten(double factor)
{
    // Brighten the image by multiplying each pixel component by the factor,
    // then clamping the result to a valid range.

    // FILL IN IMPLEMENTATION HERE (REMOVE PRINT STATEMENT WHEN DONE)
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            R2Pixel& pixel = Pixel(i, j);
            pixel.SetRed(pixel.Red() * factor);
            pixel.SetGreen(pixel.Green() * factor);
            pixel.SetBlue(pixel.Blue() * factor);
            pixel.Clamp();
            SetPixel(i, j, pixel);
        }
    }
}



void R2Image::
ChangeContrast(double factor)
{
    // Change the contrast of an image by interpolating between the image
    // and a constant gray image with the average luminance.
    // Interpolation reduces constrast, extrapolation boosts constrast,
    // and negative factors generate inverted images.
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            R2Pixel& pixel = Pixel(i, j);

            pixel.SetRed(factor * pixel.Red() + pixel.Luminance() * (1 - factor));
            pixel.SetGreen(factor * pixel.Green() + pixel.Luminance() * (1 - factor));
            pixel.SetBlue(factor * pixel.Blue() + pixel.Luminance() * (1 - factor));

            /*
            pixel.SetRed(pixel.Luminance() * factor);
            pixel.SetGreen(pixel.Luminance() * factor);
            pixel.SetBlue(pixel.Luminance() * factor);

            pixel.SetRed(pixel.Luminance() * (1 - factor));
            pixel.SetGreen(pixel.Luminance() * (1 - factor));
            pixel.SetBlue(pixel.Luminance() * (1 - factor));
            */
            SetPixel(i, j, pixel);
        }
    }
}


// Linear filtering ////////////////////////////////////////////////

void R2Image::
Blur(double sigma)
{
    // Blur an image with a Gaussian filter with a given sigma.
    /*
            int numerator;
            double denominator, num_by_den, exponential, gf;

            numerator = pixel.Red() * pixel.Red();
            denominator = 2 * sigma * sigma;
            num_by_den = numerator / denominator;
            exponential = exp(num_by_den);
            gf = 1 / exponential;
            pixel.SetRed(pixel.Red() * gf);
            */

            /*
            int kernelsize = ceil(3 * sigma) * 2 + 1;
            int K[5][5] = { {0.0001,0.0006,0.0004,0.0006,0.0001},{0.0004,0.0016,0.0024,0.0016,0.0004},{0.0006,0.0024,0.0036,0.0024,0.0006},{0.0004,0.0016,0.0024,0.0016,0.0004},{0.0001,0.0006,0.0004,0.0006,0.0001} };
            //int K[5][5] = { {1,6,4,6,1},{4,16,24,16,4},{6,24,36,24,6},{4,16,24,16,4},{1,6,4,6,1} };
            //int K[3][3] = {{0,1,0},{1,2,1},{0,1,0}};
            for (int j = 0; j < height; j++)
            {
                for (int i = 0; i < width; i++)
                {
                    R2Pixel& pixell = Pixel(i, j);
                    int red = 0, blue = 0, green = 0;
                    int Ip = 0;
                    for (int b = -2 ; b <=2 ; b++)
                    {
                        int Iq = 0;
                        for (int a = -2 ; a <=2 ; a++)
                        {
                            R2Pixel& pixel = Pixel(i+a, j+b);
                            if ((j <= height-3) && (j>=2) && (i <= width - 3) && (i >= 2))
                            {
                                red += pixel.Red() * (1 / exp(K[Ip][Iq]));
                                blue += pixel.Blue() * (1 / exp(K[Ip][Iq]));
                                green += pixel.Green() * (1 / exp(K[Ip][Iq]));
                            }
                            Iq++;
                        }
                        Ip++;
                    }
                    pixell.SetRed(red/0.0256);
                    pixell.SetBlue(blue/ 0.0256);
                    pixell.SetGreen(green/0.0256);
                }
            }
            */
    int k_UL = (((ceil(3 * sigma) * 2 + 1) + 1) / 2) - 1;
    int k_LL = -1 * k_UL;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            R2Pixel& pixell = Pixel(i, j);
            unsigned int red = 0, blue = 0, green = 0;
            
            for (int b = k_LL; b <= k_UL; b++)
            {
                
                for (int a = k_LL; a <= k_UL; a++)
                {
                    R2Pixel& pixel = Pixel(i + a, j + b);
                    if ((j <= height - (k_UL + 1)) && (j >= k_UL) && (i <= width - (k_UL + 1)) && (i >= k_UL))
                    {
                        double gf = 1 / ((sqrt(2 * 3.14 * sigma * sigma))*exp((((b + k_UL) * (b + k_UL) + (a + k_UL) * (a + k_UL))/(2*sigma*sigma))));
                        red += (pixel.Red()*gf);
                        blue += (pixel.Blue()*gf);
                        green += (pixel.Green()*gf);
                    }
                    
                }
                
            pixell.SetRed(red * sigma);
            pixell.SetBlue(blue * sigma);
            pixell.SetGreen(green * sigma);
            }
        SetPixel(i, j, pixell);
        }
    }
}



void R2Image::
Sharpen()
{
  // Sharpen an image using a linear filter

  // FILL IN IMPLEMENTATION HERE (REMOVE PRINT STATEMENT WHEN DONE)
  //fprintf(stderr, "Sharpen() not implemented\n");
    int K[3][3] = {{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            R2Pixel& pixell = Pixel(i, j);
            int red = 0, blue = 0, green = 0;
            int Ip = 0;
            for (int b = -1; b <= 1; b++)
            {
                int Iq = 0;
                for (int a = -1; a <= 1; a++)
                {
                    R2Pixel& pixel = Pixel(i + a, j + b);
                    if ((j <= height - 3) && (j >= 2) && (i <= width - 3) && (i >= 2))
                    {
                        red += pixel.Red() * K[Ip][Iq];
                        blue += pixel.Blue() * K[Ip][Iq];
                        green += pixel.Green() * K[Ip][Iq];
                    }
                    Iq++;
                }
                Ip++;
            }
            pixell.SetRed(red + pixell.Red());
            pixell.SetBlue(blue + pixell.Blue());
            pixell.SetGreen(green + pixell.Green());

            SetPixel(i, j, pixell);
        }
    }
}



void R2Image::
EdgeDetect(void)
{
    // Detect edges in an image.

  // FILL IN IMPLEMENTATION HERE (REMOVE PRINT STATEMENT WHEN DONE)
  //fprintf(stderr, "EdgeDetect() not implemented\n");
    //int K[3][3] = { {-1,-1,-1},{-1,8,-1},{-1,-1,-1} };
    //int L[3][3] = { {-1,0,1},{-2,0,2},{-1,0,1} };
    int K[3][3] = { {-1,-1,-1,},{0,0,0},{1,1,1} };
    int L[3][3] = { {-1,0,1},{-1,0,1},{-1,0,1} };
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            R2Pixel& pixell = Pixel(i, j);
            int red = 0, blue = 0, green = 0;
            int Ip = 0;
            for (int b = -1; b <= 1; b++)
            {
                int Iq = 0;
                for (int a = -1; a <= 1; a++)
                {
                    R2Pixel& pixel = Pixel(i + a, j + b);
                    if ((j <= height - 3) && (j >= 2) && (i <= width - 3) && (i >= 2))
                    {
                        red += pixel.Red() * (K[Ip][Iq]+L[Ip][Iq]);
                        blue += pixel.Blue() * (K[Ip][Iq] + L[Ip][Iq]);
                        green += pixel.Green() * (K[Ip][Iq] + L[Ip][Iq]);
                    }
                    Iq++;
                }
                Ip++;
            }
            pixell.SetRed(red);
            pixell.SetBlue(blue);
            pixell.SetGreen(green);

            SetPixel(i, j, pixell);
        }
    }
}

// Resampling operations  ////////////////////////////////////////////////


void R2Image::
Scale(double sx, double sy, int sampling_method)
{
  // Scale an image in x by sx, and y by sy.

  // FILL IN IMPLEMENTATION HERE (REMOVE PRINT STATEMENT WHEN DONE)
  //fprintf(stderr, "Scale(%g, %g, %d) not implemented\n", sx, sy, sampling_method);
    
    for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; i++)
            {
                R2Pixel& pixell = Pixel(i, j);
                for (int b = j; b <= j + sy; b++)
                {
                    for (int a = i; a <= i + sx; a++)
                    {
                        R2Pixel& pixel = Pixel(a, b);

                        pixel.SetRed(pixell.Red());
                        pixel.SetBlue(pixell.Blue());
                        pixel.SetGreen(pixell.Green());

                        SetPixel(a, b, pixel);
                    }
                }
            }
        }
    
    
    /*
    R2Image* scaled_image = new R2Image(width * sx, height * sy);
    pixels = new R2Pixel[(width * sx) * (height * sy)];
    int b = 0;
    for (int j = 0; j < height*sy; j++)
    {   
        int a = 0;
        for (int i = 0; i < width*sx; i++)
        {
            if (a < width)
            {
                R2Pixel& pixell = Pixel(i, j);
                R2Pixel& pixel = Pixel(((3*a)+1), b);

                pixell.SetRed(pixel.Red());
                pixell.SetGreen(pixel.Green());
                pixell.SetBlue(pixel.Blue());

                SetPixel(a, b, pixell);
                a++;
            }
            else
                break;
        }
        if (b < height)
        {
            b++;
        }
        else
            break;
    }
    */
    
}


void R2Image::
Composite(const R2Image& top, int operation)
{
  // Composite passed image on top of this one using operation (e.g., OVER)

  // FILL IN IMPLEMENTATION HERE (REMOVE PRINT STATEMENT WHEN DONE)
    //R2Image& top
        //R2Image& base = new R2Image();
        //R2Image& alpha
  //fprintf(stderr, "Composite not implemented\n");
}


// Miscellaneous operations ////////////////////////////////////////////////

void R2Image::
ExtractChannel(int channel)
{
  // Extracts a channel of an image (e.g., R2_IMAGE_RED_CHANNEL).  
  // Leaves the specified channel intact, 
  // and sets all the other ones to zero.

  // Extract channel
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      R2Pixel& pixel = Pixel(i, j);
      for (int c = 0; c < R2_IMAGE_NUM_CHANNELS; c++) {
        if (c != channel) pixel[c] = 0.0;
      }
    }
  }
}



void R2Image::
CopyChannel(const R2Image& from_image, int from_channel, int to_channel)
{
  // Copies one channel of an image (e.g., R2_IMAGE_RED_CHANNEL).  
  // to another channel

  // Check consistency of image dimensions
  if ((from_image.Width() != Width()) || (from_image.Height() != Height())) {
    fprintf(stderr, "Invalid image dimensions in R2Image::CopyChannel\n");
    abort();
  }

  // Copy channel
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      R2Pixel& to_pixel = Pixel(i, j);
      const R2Pixel& from_pixel = from_image.Pixel(i, j);
      to_pixel[to_channel] = from_pixel[from_channel];
    }
  }
}


////////////////////////////////////////////////////////////////////////
// I/O Functions
////////////////////////////////////////////////////////////////////////

int R2Image::
Read(const char *filename)
{
  // Initialize everything
  if (pixels) { delete [] pixels; pixels = NULL; }
  npixels = width = height = 0;

  // Parse input filename extension
  char *input_extension;
  if (!(input_extension = (char*)strrchr(filename, '.'))) {
    fprintf(stderr, "Input file has no extension (e.g., .jpg).\n");
    return 0;
  }
  
  // Read file of appropriate type
  if (!strncmp(input_extension, ".bmp", 4)) return ReadBMP(filename);
  else if (!strncmp(input_extension, ".ppm", 4)) return ReadPPM(filename);
  else if (!strncmp(input_extension, ".jpg", 4)) return ReadJPEG(filename);
  else if (!strncmp(input_extension, ".jpeg", 5)) return ReadJPEG(filename);
  else if (!strncmp(input_extension, ".txt", 4)) return ReadTXT(filename);
  
  // Should never get here
  fprintf(stderr, "Unrecognized image file extension");
  return 0;
}



int R2Image::
Write(const char *filename) const
{
  // Parse input filename extension
  char *input_extension;
  if (!(input_extension = (char*)strrchr(filename, '.'))) {
    fprintf(stderr, "Input file has no extension (e.g., .jpg).\n");
    return 0;
  }
  
  // Write file of appropriate type
  if (!strncmp(input_extension, ".bmp", 4)) return WriteBMP(filename);
  else if (!strncmp(input_extension, ".ppm", 4)) return WritePPM(filename, 1);
  else if (!strncmp(input_extension, ".jpg", 4)) return WriteJPEG(filename);
  else if (!strncmp(input_extension, ".jpeg", 5)) return WriteJPEG(filename);
  else if (!strncmp(input_extension, ".txt", 4)) return WriteTXT(filename);

  // Should never get here
  fprintf(stderr, "Unrecognized image file extension");
  return 0;
}



////////////////////////////////////////////////////////////////////////
// BMP I/O
////////////////////////////////////////////////////////////////////////

#if !defined(_WIN32)

typedef struct tagBITMAPFILEHEADER {
  unsigned short int bfType;
  unsigned int bfSize;
  unsigned short int bfReserved1;
  unsigned short int bfReserved2;
  unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
  unsigned int biSize;
  int biWidth;
  int biHeight;
  unsigned short int biPlanes;
  unsigned short int biBitCount;
  unsigned int biCompression;
  unsigned int biSizeImage;
  int biXPelsPerMeter;
  int biYPelsPerMeter;
  unsigned int biClrUsed;
  unsigned int biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagRGBTRIPLE {
  unsigned char rgbtBlue;
  unsigned char rgbtGreen;
  unsigned char rgbtRed;
} RGBTRIPLE;

typedef struct tagRGBQUAD {
  unsigned char rgbBlue;
  unsigned char rgbGreen;
  unsigned char rgbRed;
  unsigned char rgbReserved;
} RGBQUAD;

#endif

#define BI_RGB        0L
#define BI_RLE8       1L
#define BI_RLE4       2L
#define BI_BITFIELDS  3L

#define BMP_BF_TYPE 0x4D42 /* word BM */
#define BMP_BF_OFF_BITS 54 /* 14 for file header + 40 for info header (not sizeof(), but packed size) */
#define BMP_BI_SIZE 40 /* packed size of info header */


static unsigned short int WordReadLE(FILE *fp)
{
  // Read a unsigned short int from a file in little endian format 
  unsigned short int lsb, msb;
  lsb = getc(fp);
  msb = getc(fp);
  return (msb << 8) | lsb;
}



static void WordWriteLE(unsigned short int x, FILE *fp)
{
  // Write a unsigned short int to a file in little endian format
  unsigned char lsb = (unsigned char) (x & 0x00FF); putc(lsb, fp); 
  unsigned char msb = (unsigned char) (x >> 8); putc(msb, fp);
}



static unsigned int DWordReadLE(FILE *fp)
{
  // Read a unsigned int word from a file in little endian format 
  unsigned int b1 = getc(fp);
  unsigned int b2 = getc(fp);
  unsigned int b3 = getc(fp);
  unsigned int b4 = getc(fp);
  return (b4 << 24) | (b3 << 16) | (b2 << 8) | b1;
}



static void DWordWriteLE(unsigned int x, FILE *fp)
{
  // Write a unsigned int to a file in little endian format 
  unsigned char b1 = (x & 0x000000FF); putc(b1, fp);
  unsigned char b2 = ((x >> 8) & 0x000000FF); putc(b2, fp);
  unsigned char b3 = ((x >> 16) & 0x000000FF); putc(b3, fp);
  unsigned char b4 = ((x >> 24) & 0x000000FF); putc(b4, fp);
}



static int LongReadLE(FILE *fp)
{
  // Read a int word from a file in little endian format 
  int b1 = getc(fp);
  int b2 = getc(fp);
  int b3 = getc(fp);
  int b4 = getc(fp);
  return (b4 << 24) | (b3 << 16) | (b2 << 8) | b1;
}



static void LongWriteLE(int x, FILE *fp)
{
  // Write a int to a file in little endian format 
  char b1 = (x & 0x000000FF); putc(b1, fp);
  char b2 = ((x >> 8) & 0x000000FF); putc(b2, fp);
  char b3 = ((x >> 16) & 0x000000FF); putc(b3, fp);
  char b4 = ((x >> 24) & 0x000000FF); putc(b4, fp);
}



int R2Image::
ReadBMP(const char *filename)
{
  // Open file
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Unable to open image file: %s\n", filename);
    return 0;
  }

  /* Read file header */
  BITMAPFILEHEADER bmfh;
  bmfh.bfType = WordReadLE(fp);
  bmfh.bfSize = DWordReadLE(fp);
  bmfh.bfReserved1 = WordReadLE(fp);
  bmfh.bfReserved2 = WordReadLE(fp);
  bmfh.bfOffBits = DWordReadLE(fp);
  
  /* Check file header */
  assert(bmfh.bfType == BMP_BF_TYPE);
  /* ignore bmfh.bfSize */
  /* ignore bmfh.bfReserved1 */
  /* ignore bmfh.bfReserved2 */
  assert(bmfh.bfOffBits == BMP_BF_OFF_BITS);
  
  /* Read info header */
  BITMAPINFOHEADER bmih;
  bmih.biSize = DWordReadLE(fp);
  bmih.biWidth = LongReadLE(fp);
  bmih.biHeight = LongReadLE(fp);
  bmih.biPlanes = WordReadLE(fp);
  bmih.biBitCount = WordReadLE(fp);
  bmih.biCompression = DWordReadLE(fp);
  bmih.biSizeImage = DWordReadLE(fp);
  bmih.biXPelsPerMeter = LongReadLE(fp);
  bmih.biYPelsPerMeter = LongReadLE(fp);
  bmih.biClrUsed = DWordReadLE(fp);
  bmih.biClrImportant = DWordReadLE(fp);
  
  // Check info header 
  assert(bmih.biSize == BMP_BI_SIZE);
  assert(bmih.biWidth > 0);
  assert(bmih.biHeight > 0);
  assert(bmih.biPlanes == 1);
  assert(bmih.biBitCount == 24);  /* RGB */
  assert(bmih.biCompression == BI_RGB);   /* RGB */
  int lineLength = bmih.biWidth * 3;  /* RGB */
  if ((lineLength % 4) != 0) lineLength = (lineLength / 4 + 1) * 4;
  assert(bmih.biSizeImage == (unsigned int) lineLength * (unsigned int) bmih.biHeight);

  // Assign width, height, and number of pixels
  width = bmih.biWidth;
  height = bmih.biHeight;
  npixels = width * height;

  // Allocate unsigned char buffer for reading pixels
  int rowsize = 3 * width;
  if ((rowsize % 4) != 0) rowsize = (rowsize / 4 + 1) * 4;
  int nbytes = bmih.biSizeImage;
  unsigned char *buffer = new unsigned char [nbytes];
  if (!buffer) {
    fprintf(stderr, "Unable to allocate temporary memory for BMP file");
    fclose(fp);
    return 0;
  }

  // Read buffer 
  fseek(fp, (long) bmfh.bfOffBits, SEEK_SET);
  if (fread(buffer, 1, bmih.biSizeImage, fp) != bmih.biSizeImage) {
    fprintf(stderr, "Error while reading BMP file %s", filename);
    return 0;
  }

  // Close file
  fclose(fp);

  // Allocate pixels for image
  pixels = new R2Pixel [ width * height ];
  if (!pixels) {
    fprintf(stderr, "Unable to allocate memory for BMP file");
    fclose(fp);
    return 0;
  }

  // Assign pixels
  for (int j = 0; j < height; j++) {
    unsigned char *p = &buffer[j * rowsize];
    for (int i = 0; i < width; i++) {
      double b = (double) *(p++) / 255;
      double g = (double) *(p++) / 255;
      double r = (double) *(p++) / 255;
      R2Pixel pixel(r, g, b, 1);
      SetPixel(i, j, pixel);
    }
  }

  // Free unsigned char buffer for reading pixels
  delete [] buffer;

  // Return success
  return 1;
}



int R2Image::
WriteBMP(const char *filename) const
{
  // Open file
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    fprintf(stderr, "Unable to open image file: %s\n", filename);
    return 0;
  }

  // Compute number of bytes in row
  int rowsize = 3 * width;
  if ((rowsize % 4) != 0) rowsize = (rowsize / 4 + 1) * 4;

  // Write file header 
  BITMAPFILEHEADER bmfh;
  bmfh.bfType = BMP_BF_TYPE;
  bmfh.bfSize = BMP_BF_OFF_BITS + rowsize * height;
  bmfh.bfReserved1 = 0;
  bmfh.bfReserved2 = 0;
  bmfh.bfOffBits = BMP_BF_OFF_BITS;
  WordWriteLE(bmfh.bfType, fp);
  DWordWriteLE(bmfh.bfSize, fp);
  WordWriteLE(bmfh.bfReserved1, fp);
  WordWriteLE(bmfh.bfReserved2, fp);
  DWordWriteLE(bmfh.bfOffBits, fp);

  // Write info header 
  BITMAPINFOHEADER bmih;
  bmih.biSize = BMP_BI_SIZE;
  bmih.biWidth = width;
  bmih.biHeight = height;
  bmih.biPlanes = 1;
  bmih.biBitCount = 24;       /* RGB */
  bmih.biCompression = BI_RGB;    /* RGB */
  bmih.biSizeImage = rowsize * (unsigned int) bmih.biHeight;  /* RGB */
  bmih.biXPelsPerMeter = 2925;
  bmih.biYPelsPerMeter = 2925;
  bmih.biClrUsed = 0;
  bmih.biClrImportant = 0;
  DWordWriteLE(bmih.biSize, fp);
  LongWriteLE(bmih.biWidth, fp);
  LongWriteLE(bmih.biHeight, fp);
  WordWriteLE(bmih.biPlanes, fp);
  WordWriteLE(bmih.biBitCount, fp);
  DWordWriteLE(bmih.biCompression, fp);
  DWordWriteLE(bmih.biSizeImage, fp);
  LongWriteLE(bmih.biXPelsPerMeter, fp);
  LongWriteLE(bmih.biYPelsPerMeter, fp);
  DWordWriteLE(bmih.biClrUsed, fp);
  DWordWriteLE(bmih.biClrImportant, fp);

  // Write image, swapping blue and red in each pixel
  int pad = rowsize - width * 3;
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      const R2Pixel& pixel = (*this)[i][j];
      double r = 255.0 * pixel.Red();
      double g = 255.0 * pixel.Green();
      double b = 255.0 * pixel.Blue();
      if (r >= 255) r = 255;
      if (g >= 255) g = 255;
      if (b >= 255) b = 255;
      fputc((unsigned char) b, fp);
      fputc((unsigned char) g, fp);
      fputc((unsigned char) r, fp);
    }

    // Pad row
    for (int i = 0; i < pad; i++) fputc(0, fp);
  }
  
  // Close file
  fclose(fp);

  // Return success
  return 1;  
}



////////////////////////////////////////////////////////////////////////
// PPM I/O
////////////////////////////////////////////////////////////////////////

int R2Image::
ReadPPM(const char *filename)
{
  // Open file
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Unable to open image file: %s\n", filename);
    return 0;
  }

  // Read PPM file magic identifier
  char buffer[128];
  if (!fgets(buffer, 128, fp)) {
    fprintf(stderr, "Unable to read magic id in PPM file");
    fclose(fp);
    return 0;
  }

  // skip comments
  int c = getc(fp);
  while (c == '#') {
    while (c != '\n') c = getc(fp);
    c = getc(fp);
  }
  ungetc(c, fp);

  // Read width and height
  if (fscanf(fp, "%d%d", &width, &height) != 2) {
    fprintf(stderr, "Unable to read width and height in PPM file");
    fclose(fp);
    return 0;
  }

  npixels = width * height;
	
  // Read max value
  double max_value;
  if (fscanf(fp, "%lf", &max_value) != 1) {
    fprintf(stderr, "Unable to read max_value in PPM file");
    fclose(fp);
    return 0;
  }
	
  // Allocate image pixels
  pixels = new R2Pixel [ width * height ];
  if (!pixels) {
    fprintf(stderr, "Unable to allocate memory for PPM file");
    fclose(fp);
    return 0;
  }

  // Check if raw or ascii file
  if (!strcmp(buffer, "P6\n")) {
    // Read up to one character of whitespace (\n) after max_value
    int c = getc(fp);
    if (!isspace(c)) putc(c, fp);

    // Read raw image data 
    // First ppm pixel is top-left, so read in opposite scan-line order
    for (int j = height-1; j >= 0; j--) {
      for (int i = 0; i < width; i++) {
        double r = (double) getc(fp) / max_value;
        double g = (double) getc(fp) / max_value;
        double b = (double) getc(fp) / max_value;
        R2Pixel pixel(r, g, b, 1);
        SetPixel(i, j, pixel);
      }
    }
  }
  else {
    // Read asci image data 
    // First ppm pixel is top-left, so read in opposite scan-line order
    for (int j = height-1; j >= 0; j--) {
      for (int i = 0; i < width; i++) {
	// Read pixel values
	int red, green, blue;
	if (fscanf(fp, "%d%d%d", &red, &green, &blue) != 3) {
	  fprintf(stderr, "Unable to read data at (%d,%d) in PPM file", i, j);
	  fclose(fp);
	  return 0;
	}

	// Assign pixel values
	double r = (double) red / max_value;
	double g = (double) green / max_value;
	double b = (double) blue / max_value;
        R2Pixel pixel(r, g, b, 1);
        SetPixel(i, j, pixel);
      }
    }
  }

  // Close file
  fclose(fp);

  // Return success
  return 1;
}



int R2Image::
WritePPM(const char *filename, int ascii) const
{
  // Check type
  if (ascii) {
    // Open file
    FILE *fp = fopen(filename, "w");
    if (!fp) {
      fprintf(stderr, "Unable to open image file: %s\n", filename);
      return 0;
    }

    // Print PPM image file 
    // First ppm pixel is top-left, so write in opposite scan-line order
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "255\n");
    for (int j = height-1; j >= 0 ; j--) {
      for (int i = 0; i < width; i++) {
        const R2Pixel& p = (*this)[i][j];
        int r = (int) (255 * p.Red());
        int g = (int) (255 * p.Green());
        int b = (int) (255 * p.Blue());
        fprintf(fp, "%-3d %-3d %-3d  ", r, g, b);
        if (((i+1) % 4) == 0) fprintf(fp, "\n");
      }
      if ((width % 4) != 0) fprintf(fp, "\n");
    }
    fprintf(fp, "\n");

    // Close file
    fclose(fp);
  }
  else {
    // Open file
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
      fprintf(stderr, "Unable to open image file: %s\n", filename);
      return 0;
    }
    
    // Print PPM image file 
    // First ppm pixel is top-left, so write in opposite scan-line order
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "255\n");
    for (int j = height-1; j >= 0 ; j--) {
      for (int i = 0; i < width; i++) {
        const R2Pixel& p = (*this)[i][j];
        int r = (int) (255 * p.Red());
        int g = (int) (255 * p.Green());
        int b = (int) (255 * p.Blue());
        fprintf(fp, "%c%c%c", r, g, b);
      }
    }
    
    // Close file
    fclose(fp);
  }

  // Return success
  return 1;  
}



////////////////////////////////////////////////////////////////////////
// JPEG I/O
////////////////////////////////////////////////////////////////////////


extern "C" { 
#   define XMD_H // Otherwise, a conflict with INT32
#   undef FAR // Otherwise, a conflict with windows.h
#   include "jpeg/jpeglib.h"
};



int R2Image::
ReadJPEG(const char *filename)
{
  // Open file
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Unable to open image file: %s\n", filename);
    return 0;
  }

  // Initialize decompression info
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_decompress(&cinfo);
  jpeg_stdio_src(&cinfo, fp);
  jpeg_read_header(&cinfo, TRUE);
  jpeg_start_decompress(&cinfo);

  // Remember image attributes
  width = cinfo.output_width;
  height = cinfo.output_height;
  npixels = width * height;
  int ncomponents = cinfo.output_components;

  // Allocate pixels for image
  pixels = new R2Pixel [ npixels ];
  if (!pixels) {
    fprintf(stderr, "Unable to allocate memory for BMP file");
    fclose(fp);
    return 0;
  }

  // Allocate unsigned char buffer for reading image
  int rowsize = ncomponents * width;
  if ((rowsize % 4) != 0) rowsize = (rowsize / 4 + 1) * 4;
  int nbytes = rowsize * height;
  unsigned char *buffer = new unsigned char [nbytes];
  if (!buffer) {
    fprintf(stderr, "Unable to allocate temporary memory for JPEG file");
    fclose(fp);
    return 0;
  }

  // Read scan lines 
  // First jpeg pixel is top-left, so read pixels in opposite scan-line order
  while (cinfo.output_scanline < cinfo.output_height) {
    int scanline = cinfo.output_height - cinfo.output_scanline - 1;
    unsigned char *row_pointer = &buffer[scanline * rowsize];
    jpeg_read_scanlines(&cinfo, &row_pointer, 1);
  }

  // Free everything
  jpeg_finish_decompress(&cinfo);
  jpeg_destroy_decompress(&cinfo);

  // Close file
  fclose(fp);

  // Assign pixels
  for (int j = 0; j < height; j++) {
    unsigned char *p = &buffer[j * rowsize];
    for (int i = 0; i < width; i++) {
      double r, g, b, a;
      if (ncomponents == 1) {
        r = g = b = (double) *(p++) / 255;
        a = 1;
      }
      else if (ncomponents == 1) {
        r = g = b = (double) *(p++) / 255;
        a = 1;
        p++;
      }
      else if (ncomponents == 3) {
        r = (double) *(p++) / 255;
        g = (double) *(p++) / 255;
        b = (double) *(p++) / 255;
        a = 1;
      }
      else if (ncomponents == 4) {
        r = (double) *(p++) / 255;
        g = (double) *(p++) / 255;
        b = (double) *(p++) / 255;
        a = (double) *(p++) / 255;
      }
      else {
        fprintf(stderr, "Unrecognized number of components in jpeg image: %d\n", ncomponents);
        return 0;
      }
      R2Pixel pixel(r, g, b, a);
      SetPixel(i, j, pixel);
    }
  }

  // Free unsigned char buffer for reading pixels
  delete [] buffer;

  // Return success
  return 1;
}


	

int R2Image::
WriteJPEG(const char *filename) const
{
  // Open file
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    fprintf(stderr, "Unable to open image file: %s\n", filename);
    return 0;
  }

  // Initialize compression info
  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
  cinfo.err = jpeg_std_error(&jerr);
  jpeg_create_compress(&cinfo);
  jpeg_stdio_dest(&cinfo, fp);
  cinfo.image_width = width; 	/* image width and height, in pixels */
  cinfo.image_height = height;
  cinfo.input_components = 3;		/* # of color components per pixel */
  cinfo.in_color_space = JCS_RGB; 	/* colorspace of input image */
  cinfo.dct_method = JDCT_ISLOW;
  jpeg_set_defaults(&cinfo);
  cinfo.optimize_coding = TRUE;
  jpeg_set_quality(&cinfo, 75, TRUE);
  jpeg_start_compress(&cinfo, TRUE);
	
  // Allocate unsigned char buffer for reading image
  int rowsize = 3 * width;
  if ((rowsize % 4) != 0) rowsize = (rowsize / 4 + 1) * 4;
  int nbytes = rowsize * height;
  unsigned char *buffer = new unsigned char [nbytes];
  if (!buffer) {
    fprintf(stderr, "Unable to allocate temporary memory for JPEG file");
    fclose(fp);
    return 0;
  }

  // Fill buffer with pixels
  for (int j = 0; j < height; j++) {
    unsigned char *p = &buffer[j * rowsize];
    for (int i = 0; i < width; i++) {
      const R2Pixel& pixel = (*this)[i][j];
      int r = (int) (255 * pixel.Red());
      int g = (int) (255 * pixel.Green());
      int b = (int) (255 * pixel.Blue());
      if (r > 255) r = 255;
      if (g > 255) g = 255;
      if (b > 255) b = 255;
      *(p++) = r;
      *(p++) = g;
      *(p++) = b;
    }
  }



  // Output scan lines
  // First jpeg pixel is top-left, so write in opposite scan-line order
  while (cinfo.next_scanline < cinfo.image_height) {
    int scanline = cinfo.image_height - cinfo.next_scanline - 1;
    unsigned char *row_pointer = &buffer[scanline * rowsize];
    jpeg_write_scanlines(&cinfo, &row_pointer, 1);
  }

  // Free everything
  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);

  // Close file
  fclose(fp);

  // Free unsigned char buffer for reading pixels
  delete [] buffer;

  // Return number of bytes written
  return 1;
}



////////////////////////////////////////////////////////////////////////
// TXT I/O
////////////////////////////////////////////////////////////////////////

int R2Image::
ReadTXT(const char *filename)
{
  // Open file
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    fprintf(stderr, "Unable to open image file: %s\n", filename);
    return 0;
  }

  // Read width, height, and nchannels
  int nchannels;
  if (fscanf(fp, "%d%d%d", &width, &height, &nchannels) != 3) {
    fprintf(stderr, "Unable to read width and height and nchannels in TXT file");
    fclose(fp);
    return 0;
  }

  // Check number of channels
  if ((nchannels == 0) || (nchannels > 4)) {
    fprintf(stderr, "Invalid number of channels (%d) in TXT image %s\n", nchannels, filename);
    fclose(fp);
    return 0;
  }
    
  // Compute number of pixels
  npixels = width * height;
	
  // Allocate image pixels
  pixels = new R2Pixel [ width * height ];
  if (!pixels) {
    fprintf(stderr, "Unable to allocate memory for TXT file");
    fclose(fp);
    return 0;
  }

  // Read asci image data 
  // First pixel is top-left, so read in opposite scan-line order
  for (int j = height-1; j >= 0; j--) {
    for (int i = 0; i < width; i++) {
      // Read pixel values
      double rgba[4];
      for (int k = 0; k < nchannels; k++) {
        if (fscanf(fp, "%lf\n", &rgba[k]) != 1) {
          fprintf(stderr, "Unable to read data at (%d,%d) in TXT file", i, j);
          fclose(fp);
          return 0;
        }
      }

      // Rectify channels
      if (nchannels == 1) { rgba[3] = 1.0; rgba[1] = rgba[2] = rgba[0]; }
      else if (nchannels == 2) { rgba[3] = rgba[2]; rgba[1] = rgba[2] = rgba[0]; } 
      else if (nchannels == 3) { rgba[3] = 1.0; } 

      // Set pixel
      SetPixel(i, j, R2Pixel(rgba));
    }
  }

  // Close file
  fclose(fp);

  // Return success
  return 1;
}



int R2Image::
WriteTXT(const char *filename) const
{
  // Open file
  FILE *fp = fopen(filename, "w");
  if (!fp) {
    fprintf(stderr, "Unable to open image file: %s\n", filename);
    return 0;
  }

  // Print width, height, and nchannels
  fprintf(fp, "%d %d %d\n", width, height, 4);

  // Print pixel values
  // First pixel is top-left, so write in opposite scan-line order
  for (int j = height-1; j >= 0 ; j--) {
    for (int i = 0; i < width; i++) {
      R2Pixel pixel = Pixel(i, j);
      fprintf(fp, "%g %g %g %g\n", pixel[0], pixel[1], pixel[2], pixel[3]);
    }
  }

  // Close file
  fclose(fp);

  // Return success
  return 1;  
}