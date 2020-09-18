#include "BMPHeader.h"

/// Read in image header file stream
bool BMPHeader::read(ifstream& fin)
{
    fin.read((char*)type, 2);
    
    // Return 0 if image is not a BMP-formatted image
    if (type[0] != 'B' || type[1] != 'M') return 0;

    fin.read((char*)&file_size, sizeof(int));
    fin.read((char*)&reserved, sizeof(int));
    fin.read((char*)&offset, sizeof(int));
    fin.read((char*)&info_header_size, sizeof(int));
    fin.read((char*)&width, sizeof(int));
    fin.read((char*)&height, sizeof(int));
    fin.read((char*)&planes, sizeof(short int));
    fin.read((char*)&bits_per_pixel, sizeof(short int));
    fin.read((char*)&compression, sizeof(int));
    fin.read((char*)&data_size, sizeof(int));
    fin.read((char*)&h_resolution, sizeof(int));
    fin.read((char*)&v_resolution, sizeof(int));
    fin.read((char*)&colours, sizeof(int));
    fin.read((char*)&important_colours, sizeof(int));

    return 1;
}

/// Write to image header file stream
void BMPHeader::write(ofstream& fout)
{
    fout.write((char*)type, 2);
    fout.write((char*)&file_size, sizeof(int));
    fout.write((char*)&reserved, sizeof(int));
    fout.write((char*)&offset, sizeof(int));
    fout.write((char*)&info_header_size, sizeof(int));
    fout.write((char*)&width, sizeof(int));
    fout.write((char*)&height, sizeof(int));
    fout.write((char*)&planes, sizeof(short int));
    fout.write((char*)&bits_per_pixel, sizeof(short int));
    fout.write((char*)&compression, sizeof(int));
    fout.write((char*)&data_size, sizeof(int));
    fout.write((char*)&h_resolution, sizeof(int));
    fout.write((char*)&v_resolution, sizeof(int));
    fout.write((char*)&colours, sizeof(int));
    fout.write((char*)&important_colours, sizeof(int));
}