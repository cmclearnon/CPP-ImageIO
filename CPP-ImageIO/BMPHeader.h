//
// Created by Chris McLearnon on 15/09/2020.
//

#ifndef CPP_IMAGEIO_BMPHEADER_H
#define CPP_IMAGEIO_BMPHEADER_H
#include <fstream>

using std::ifstream;
using std::ofstream;

// BMP Format Image Header
class BMPHeader {
public:
    // Read & wrute the header with given file stream
    bool read(ifstream& fin);
    void write(ofstream& fin);

    // Get information of the image
    int get_height() const { return height; }
    int get_width() const { return width; }
    short int get_bits_per_pixel() const { return get_bits_per_pixel; }

private:
    // BMP Image Header parameters
    char type[2];
    int file_size;
    int reserved;
    int offset;
    int info_header_size;
    int width;
    int height;
    short int planes;
    short int bits_per_pixel;
    int compression;
    int data_size;
    int h_resolution;
    int v_resolution;
    int colours;
    int important_colours;
};
#endif //CPP_IMAGEIO_BMPHEADER_H
