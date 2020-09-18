#include "Image.h"
#include <iostream>
#include <string>

#define FILE_NAME_LEN 100

int main()
{
    char fname[FILE_NAME_LEN];

    std::cout << "Give the file name for reading the image: ";
    std::cin >> fname;

    // Read image
    Image image;
    if (!image.read(fname)) return 1;
    std::cout << "Size of the image:  " << image.get_height() << " x " << image.get_width() << std::endl;

    // Modify the image (to simulate somekind of image processing)
    for (int i = 0; i < image.get_height(); i++) {
        for (int j = 0; j < image.get_width(); j++) {
            // Get the pixel value at (i, j)
            int b, g, r;
            image.get_pixel(i, j, b, g, r);

            // Modify the value (for example)
            b *= 2; g *= 1.5; r *= 3;
            image.set_pixel(i, j, b, g, r);
        }
    }

    std::cout << "Give the file name for saving the image: ";
    std::cin >> fname;

    // Save modified image
    image.save(fname);
    return 0;
}