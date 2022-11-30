This directory contains skeleton code as a starting point for the challenge.

FILE STRUCTURE
==============

COMPILER.txt - notes on installing a C++ compiler and development environment.

input/ - Contains input images.  You can add your own input images (for additional testing) to this folder but there is no need to.

output/ - Empty to start.  You should write the output images produced by your program into this folder. Makefile/NMakefile does this automatically.

Makefile - script for the "make" tool (used on Linux, Mac, and Cygwin) to execute your program on the input images to produce the output images.

NMakefile - script for the "nmake" tool (used with Visual Studio) to execute your program on the input images to produce the output images.

writeup.html - Skeleton HTML file for you to use as a basis for your writeup. Basics have been written already. Only modify if you have done anything extra and please do highlight that in your submission.

src/ - Directory with source code.
    Makefile - Unix/Mac/Cygwin makefile for building your code with "make".
    cos426_assignment1.sln - Project file for Visual Studio.
    imgpro.cpp - Main program: parses the command line arguments, and calls the appropriate image functions.
    R2Image.[cpp/h] - Image class with processing functions. ** This is the only file that you need to edit. **
    R2Pixel.[cpp/h] - Pixel class.
    morphlines.cpp - A program for specifying line correspondences between two images, which you will use for morphing.  
    R2/ - A library of useful 2D geometric primitives.  Built automatically.
    jpeg/ - A library for reading/writing JPEG files.  Built automatically.
    fglut/ - A library for creating windows for OpenGL rendering (used by morphlines).

HOW TO PROCEED
==============

1. Read COMPILER.txt and install a C++ compiler on your development machine.

2. If you are using Visual Studio, open the .sln file, and build the solution.
Otherwise, cd into the "src" directory, and type "make".

3. Implement the R2Image methods in R2Image.cpp.  You will need to
read the R2Image.h and R2Pixel.h files to find out about the methods
implemented for these classes.  

4. Recompile the code.

5. Run your code. On Unix/Mac/Cygwin, change into the main assignment
directory (not the src/ subdirectory), alter the Makefile file (already done) to
generate intended output, and run "make". With Visual Studio, alter the 
NMakefile file to generate the intended output, open the "Visual Studio 
Command Prompt", change into the main assignment directory 
(not the src/ subdirectory) and run "nmake /f NMakefile".

		**IMPORTANT**
You don't need to edit the Makefile / NMakefile in either the src or root directory unless you want to test anything extra.
		**IMPORTANT**

Look for the output files in the output/ subdirectory.

6. Edit writeup.html (if you want to add anything extra) to add a description of, and links to, the images
you just created.  Open writeup.html in a web browser to see the webpage.

7. Create a .zip file containing the contents of this directory.

8. Submit it at the Dropbox link - https://www.dropbox.com/request/40ndMMef2wwavrZwgEfm

