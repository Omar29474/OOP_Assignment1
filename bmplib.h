//Name = omar ahmed abdelhamied
//id = 20190653
//Name = samia reda mohamdy
//samiareda2004@gmail.com
//oa4983812@gmail.com

#ifndef BMPLIB_H
#define BMPLIB_H

const int SIZE = 256;
const int RGB = 3;

void applyBlackAndWhiteFilter(unsigned char image[][SIZE]);
//In the applyBlackAndWhiteFilter function, the logic iterates over each pixel in the image
//and converts the pixel to black and white.
//The threshold value of 127 is used to determine whether the pixel should be set to
//black (0) or white (255). If the pixel value is less than or equal to 127, it is set to black; otherwise, it is set to white.

void applyInvertFilter(unsigned char image[][SIZE]);
//In the applyInvertFilter function, the logic iterates over each pixel in the image and inverts its value.
//Since grayscale images have pixel values ranging from 0 to 255,
//subtracting the original pixel value from 255 gives the inverted value.

void applyMergeFilter(unsigned char image1[][SIZE][RGB], unsigned char image2[][SIZE][RGB], unsigned char outputImage[][SIZE][RGB]);
//In the applyMergeFilter function, the logic iterates over each pixel in the images image1 and image2.
//It then calculates the average of the color values (Red, Green, Blue) for each corresponding pixel
//in both images and stores the result in the outputImage array.

void applyFlipImage(unsigned char image[][SIZE]);
//In the applyFlipImage function, the logic iterates over each row of the image and swaps the pixels horizontally.
//It performs the swap using a temporary variable temp to store the value of the pixel at the current position,
//swaps it with the pixel at the corresponding position on the opposite side, and repeats this process until reaching the middle of the row.

void applyDarkenAndLightenImage(unsigned char image[][SIZE]);
//In the applyDarkenAndLightenImage function, the logic iterates over each pixel
//in the image and adjusts its intensity based on whether you want to darken or lighten the image.
//We subtract 50 from the pixel value to darken the image or add 50 to lighten it.
//The resulting pixel intensity is then clamped to the valid range of [0, 255] to ensure it doesn't exceed the limits.

void applyRotateImage(unsigned char image[][SIZE]);
//In the applyRotateImage function, a temporary image tempImage is created to store the original pixel values.
 //The original image is then rotated by 90 degrees clockwise by assigning the pixel values from the temporary image
 //to the rotated positions in the original image.
