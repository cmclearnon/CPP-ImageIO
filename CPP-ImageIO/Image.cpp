#include "Image.h"
#include <iostream>
#include <fstream>

Image::Image(): b_data(0), g_data(0), r_data(0)
{
}

Image::~Image()
{
    /**
     * * Free spaces for image data
     */
    if (b_data) {
        for (int i = 0; i < header.get_height(); i++) {
            delete[] b_data[i];
            delete[] g_data[i];
            delete[] r_data[i];
        }
        delete[] b_data;
        delete[] g_data;
        delete[] r_data;
    }
}

bool Image::read(char* fname)
{
    /**
     * * Open the image file for input
     * * ifsteam opens the file in binary mode
     */
    ifstream fin(fname, std::ios::binary);
    if (!fin) {
        std::cout << "Can't find file: " << fname << std::endl;
        return 0;
    }

    // Read BMP image header
    if (!header.read(fin)) return 0;

    // Allocate spaces for image data
    b_data = new unsigned int*[get_height()];
    g_data = new unsigned int*[get_height()];
    r_data = new unsigned int*[get_height()];
    for (int i = 0; i < get_height(); i++) {
        b_data[i] = new unsigned int[header.get_width()];
        g_data[i] = new unsigned int[header.get_width()];
        r_data[i] = new unsigned int[header.get_width()];
    }

    // Pad zeros at the end of each row so that each row is multiples of 4 bytes long
    int num_zeros = 4 - (header.get_width() * (header.get_bits_per_pixel() / 8) % 4);
    if (num_zeros == 4) num_zeros = 0;

    // Read the image data row by row
    for (int i = get_height() - 1; i >= 0; i--) {
        unsigned char b, g, r;
        for (int j = 0; j < header.get_width(); j++) {
            // Read pixel values at (i, j)
            fin.read((char*)&b, 1);
            fin.read((char*)&g, 1);
            fin.read((char*)&r, 1);

            b_data[i][j] = b;
            g_data[i][j] = g;
            r_data[i][j] = r;
        }
        // Read padded zeros at end of the row if any
        for (int j = 0; j < num_zeros; j++) {
            fin.read((char*)&b, 1);
        }
    }
    fin.close();
    return 1;
}

void Image::save(char* fname)
{
    // Open the image file for output
    ofstream fout(fname, std::ios::binary);

    // Write header
    header.write(fout);

    // Pad zeros at the end of each row so that each row is multiples of 4 bytes long
    int num_zeros = 4 - (header.get_width() * (header.get_bits_per_pixel() / 8) % 4);
    if (num_zeros == 4) num_zeros = 0;

    // Write image data row by row
    for (int i = header.get_height() - 1; i >= 0; i--) {
        unsigned char b, g, r;
        for (int j = 0; j < header.get_width(); j++) {
            b = b_data[i][j];
            g = g_data[i][j];
            r = r_data[i][j];
            fout.write((char*)&b, 1);
            fout.write((char*)&g, 1);
            fout.write((char*)&r, 1);
        }
        // Write padded zeros at end of the row if any
        b = 0;
        for (int j = 0; j < num_zeros; j++) {
            fout.write((char*)&b, 1);
        }
    }
    fout.close();
}

void Image::get_pixel(int i, int j, int&b, int& g, int& r)
{
    b = b_data[i][j];
    g = g_data[i][j];
    r = r_data[i][j];
}

void Image::set_pixel(int i, int j, int b, int g, int r)
{
    if (i >= 0 && i < header.get_height() && j >= 0 && j < header.get_width()) {
        // Pixel is coded by one byte and so value must be within [0, 255]
        if (b < 0) b = 0; if (b > 255) b = 255;
        if (g < 0) g = 0; if (g > 255) g = 255;
        if (r < 0) r = 0; if (r > 255) r = 255;

        b_data[i][j] = b;
        g_data[i][j] = g;
        r_data[i][j] = r;
    }
}