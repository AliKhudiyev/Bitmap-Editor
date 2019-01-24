/*
 * The header file contains basic Info structure to store necessary information to process bitmap files.
 * Although it doesn't do so much it has a function to write bytes in little endian order.
 * This function makes this structure a bit more user-friendly.
*/

#pragma once

#include<vector>
#include<cstdint>

#define FILE_SIZE 0
#define WIDTH 1
#define HEIGHT 2
#define IMAGE_SIZE 3
#define HEADER_SIZE 4
#define OFFSET_SIZE 5
#define BITS_PER_PIXEL 6

const char null=0x00;

struct BMP_Info{
    uint16_t signature_;
    uint32_t file_size_;
    uint32_t offset_size_;
    uint32_t header_size_;
    uint32_t width_, height_;
    uint16_t bits_per_pixel_;
    uint32_t image_size_;

    std::vector<unsigned char> byte_vector(unsigned char type, unsigned n_byte=4) const;
    void clear();
    void Info() const;
};
