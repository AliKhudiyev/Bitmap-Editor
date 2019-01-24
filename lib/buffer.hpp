/*
 * Buffer to hold logs or recent events in order to remove or back up.
 * Has maximum size of 10 undo and 10 redo operations.
*/

#pragma once

#include<vector>
#include"pixel.hpp"

#define UNDO 0
#define REDO 1

struct BUFFER{
    private:
    static std::vector<Pixel> undo_[10];
    static std::vector<Pixel> redo_[10];
    static unsigned u_index, r_index;

    public:
    static void push(const std::vector<Pixel>& undo, const std::vector<Pixel>& redo);
    static void push(bool type, const std::vector<Pixel>& buffer);
    static void push(const std::vector<Pixel>& unre_do);
    static void pop(bool type);
};
