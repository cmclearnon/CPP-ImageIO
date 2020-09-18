#ifndef IMAGE_H
// #define IMAGE

#include "BMPHeader.h"

// Class Image I/O & Access
class Image {
    public:
    // Constructor
    Image();

    // Destructor
    ~Image();

    /**
     * * Read an image with given filename>
     * @param fname The filename of the image
     */
    bool read(char* fname);

    /**
     * * Save an image with given filename>
     * @param fname The filename of the image
     */
    void save(char* fname);

    /**
     * * Get dimensions of the image
     */
    int get_height() { return header.get_height(); }
    int get_width() { return header.get_width(); }

    /**
     * * Get pixel values (b, g, r) at location (i, j)
     * @param i The x position of the pixel
     * @param j The y position of the pixel
     * @param b The blue numerical colour value
     * @param g The green numerical colour value
     * @param r The red numerical colour value
     */
    void get_pixel(int i, int j, int& b, int& g, int& r);

    /**
     * * Set pixel values (b, g, r) at location (i, j)
     * @param i The x position of the pixel
     * @param j The y position of the pixel
     * @param b The blue numerical colour value
     * @param g The green numerical colour value
     * @param r The red numerical colour value
     */
    void set_pixel(int i, int j, int b, int g, int r);
    
    private:
    /**
     * * BMP Image header & data
     */
    BMPHeader header;
    unsigned int**b_data, **g_data, **r_data;
};
#endif