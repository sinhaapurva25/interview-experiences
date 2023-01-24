1. In the zip file, cos426_assignment1.sln did not exist. imageprocessing.sln has been assumed to be the solution file.

2. The imageprocessing.sln is cleaned and build from Microsoft Visual Studio 2019, using the Build options in Menu Bar.

3. The imgpro.cpp is compiled from Command Line using "cl /EHsc imgpro.cpp"


Brightness: The R, G and B of each of the pixels of the image is multiplied with the given factor.

Contrast: The R, G and B of each of the pixels of the image is extrapolated using the formula:
	factor * pixel.colorChannel() + pixel.Luminance() * (1 - factor)

Blur: Convolution using kernel is done on the image. The kernel size is calculated using (ceil(3 * sigma) * 2 + 1).

	The kernel element at position i,j of the kernel matrix is calculated using the following expression:
	1 / ((sqrt(2 * 3.14 * sigma * sigma))*exp((((b + k_UL) * (b + k_UL) + (a + k_UL) * (a + k_UL))/(2*sigma*sigma)))),
	
	where, (a,b) is the position of the element of the kernel matrix,
		k_UL is half of the kernel size minus 1 (the kernel is iterated from -k_UL to k_UL)
	
	
	Please check the following link to see the mathematical formula of the above expression:
	https://en.wikipedia.org/wiki/Gaussian_blur#:~:text=The%20Gaussian%20blur%20is%20a%20type%20of%20image-blurring,of%20a%20Gaussian%20function%20in%20one%20dimension%20is

Sharpen: The image is sharpened by adding up the original image with an image formed from finding the edges of the image, using a 3*3 kernel of {{-1,-1,-1},{-1,8,-1},{-1,-1,-1}}.

Edge Detection: The image is convoluted with horizontal and vertical kernels.
		I noticed after submitting the solution that the vertical kernel has not been multiplied in the solution, and instead of using Prewitt kernel, the same kernel as sharpening has been used.

Please check the sampling.txt and composite.text uploaded on the Dropbox link explaining the algorithms of the two. The were issues in the code, hence I retorted to submitting the algorithms in .txt file.

For any questions, reach out to me at 8420979565 or sinhaapurva25@gmail.com.

		 