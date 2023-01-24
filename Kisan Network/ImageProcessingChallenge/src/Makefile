#
# Makefile for Kisan Network Image Processing Challenge
#

#
# Compile and link options.  You can change the -g to -O to get
# an optimized, rather than debug, build.
#

CXX=c++
CXXFLAGS=-Wall -I. -g -DUSE_JPEG


#
# Machine dependent settings
#
UNAME := $(shell uname)
ifneq (,$(findstring Darwin,$(UNAME)))
	GLLIBS = -framework GLUT -framework OpenGL 
        CXXFLAGS := $(CXXFLAGS) -mmacosx-version-min=10.8
else
  ifneq (,$(findstring CYGWIN,$(UNAME)))
	GLLIBS = -lglu32 -lopengl32 -lwinmm -lgdi32
  else
	GLLIBS = -lGLU -lGL
  endif
endif


#
# Rules encoding targets and dependencies.  By default, the first of
# these is built, but you can also build any individual target by
# passing it to make - e.g., "make imgpro" or "make clean"
#
# Notice that many of the dependencies are implicit (e.g. a .o depends
# on its corresponding .cpp), as are many of the compilation rules.
#

all: imgpro morphlines

R2/libR2.a: 
	$(MAKE) -C R2

jpeg/libjpeg.a: 
	$(MAKE) -C jpeg

fglut/libfglut.a: 
	$(MAKE) -C fglut

imgpro: imgpro.o R2Image.o R2Pixel.o R2/libR2.a jpeg/libjpeg.a 
	rm -f $@
	$(CXX) $(CXXFLAGS) $^  -lm -o $@

morphlines: morphlines.o R2Image.o R2Pixel.o R2/libR2.a jpeg/libjpeg.a fglut/libfglut.a
	rm -f $@
	$(CXX) $(CXXFLAGS) $^ $(GLLIBS) -lm -o $@

R2Image.o: R2Image.cpp R2Image.h

R2Pixel.o: R2Pixel.cpp R2Pixel.h

clean:
	rm -f *.o imgpro morphlines
	$(MAKE) -C R2 clean
	$(MAKE) -C jpeg clean
	$(MAKE) -C fglut clean