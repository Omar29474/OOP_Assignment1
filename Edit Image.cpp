#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include "bmplib.cpp"
#include <bmplib.h>
using namespace std;

const int SIZE = 256;
const int RGB = 3;

void displayMenu() {
    std::cout << "Please select a filter to apply or 0 to exit:\n";
    std::cout << "1- Black & White Filter\n";
    std::cout << "2- Invert Filter\n";
    std::cout << "3- Merge Filter\n";
    std::cout << "4- Flip Image\n";
    std::cout << "5- Darken and Lighten Image\n";
    std::cout << "6- Rotate Image\n";
}

void applyBlackAndWhiteFilter(unsigned char image[][SIZE])

     {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Convert pixel to black and white
            int pixel = image[i][j];
            int blackAndWhitePixel = (pixel <= 127) ? 0 : 255;

            // Update the pixel value in the image
            image[i][j] = blackAndWhitePixel;
        }
    }
}

void applyInvertFilter(unsigned char image[][SIZE])

     {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Invert the pixel value
            image[i][j] = 255 - image[i][j];
        }
    }
}

void applyMergeFilter(unsigned char image1[][SIZE][RGB], unsigned char image2[][SIZE][RGB], unsigned char outputImage[][SIZE][RGB])

    {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            outputImage[i][j][0] = (image1[i][j][0] + image2[i][j][0]) / 2; // Red
            outputImage[i][j][1] = (image1[i][j][1] + image2[i][j][1]) / 2; // Green
            outputImage[i][j][2] = (image1[i][j][2] + image2[i][j][2]) / 2; // Blue
        }
    }
}

void applyFlipImage(unsigned char image[][SIZE])
    {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[i][SIZE - 1 - j];
            image[i][SIZE - 1 - j] = temp;
        }
    }
}


void applyDarkenAndLightenImage(unsigned char image[][SIZE])

 {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Darken or lighten the pixel intensity
            int pixel = image[i][j];
            int darkenedPixel = pixel - 50; // Decrease intensity by 50
            int lightenedPixel = pixel + 50; // Increase intensity by 50

            // Ensure the pixel intensity stays within the valid range [0, 255]
            if (darkenedPixel < 0)
                darkenedPixel = 0;
            if (darkenedPixel > 255)
                darkenedPixel = 255;
            if (lightenedPixel < 0)
                lightenedPixel = 0;
            if (lightenedPixel > 255)
                lightenedPixel = 255;

            // Update the pixel intensity in the image
            image[i][j] = darkenedPixel; // or image[i][j] = lightenedPixel;
        }
    }
}

void applyRotateImage(unsigned char image[][SIZE])

     {

    unsigned char tempImage[SIZE][SIZE];

    // Copy the original image to a temporary image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tempImage[i][j] = image[i][j];
        }
    }

    // Rotate the image by 90 degrees clockwise
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = tempImage[SIZE - 1 - j][i];
        }
    }
}

int main() {
    char filename[100];
    unsigned char image[SIZE][SIZE];
    unsigned char coloredImage[SIZE][SIZE][RGB];
    unsigned char mergedImage[SIZE][SIZE][RGB];
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the filename of the grayscale image: ";
                std::cin >> filename;
                readGSBMP(filename, image);
                applyBlackAndWhiteFilter(image);
                std::cout << "Enter the filename to save the filtered image: ";
                std::cin >> filename;
                writeGSBMP(filename, image);
                break;

            case 2:
                std::cout << "Enter the filename of the grayscale image: ";
                std::cin >> filename;
                readGSBMP(filename, image);
                applyInvertFilter(image);
                std::cout << "Enter the filename to save the filtered image: ";
                std::cin >> filename;
                writeGSBMP(filename, image);
                break;

            case 3:
                std::cout << "Enter the filename of the first colored image: ";
                std::cin >> filename;
                readRGBBMP(filename, coloredImage);
                std::cout << "Enter the filename of the second colored image: ";
                std::cin >> filename;
                readRGBBMP(filename, mergedImage);
                applyMergeFilter(coloredImage, mergedImage, coloredImage);
                std::cout << "Enter the filename to save the merged image: ";
                std::cin >> filename;
                writeRGBBMP(filename, coloredImage);
                break;

            case 4:
                std::cout << "Enter the filename of the grayscale image: ";
                std::cin >> filename;
                readGSBMP(filename, image);
                applyFlipImage(image);
                std::cout << "Enter the filename to save the flipped image: ";
                std::cin >> filename;
                writeGSBMP(filename, image);
                break;

            case 5:
                std::cout << "Enter the filename of the grayscale image: ";
                std::cin >> filename;
                readGSBMP(filename, image);
                applyDarkenAndLightenImage(image);
                std::cout << "Enter the filename to save the modified image: ";
                std::cin >> filename;
                writeGSBMP(filename, image);
                break;

            case 6:
                std::cout << "Enter the filename of the grayscale image: ";
                std::cin >> filename;
                readGSBMP(filename, image);
                applyRotateImage(image);
                std::cout << "Enter the filename to save the rotated image: ";
                std::cin >> filename;
                writeGSBMP(filename, image);
                break;

            case 0:
                std::cout << "Exiting the program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        std::cout << "\n";
    } while (choice != 0);

    return 0;
}

