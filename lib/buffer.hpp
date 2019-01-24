
#pragma once

#include<vector>
#include"pixel.hpp"

struct Buffer{
    std::vector<Pixel> undo_;
    std::vector<Pixel> redo_;
};

struct Stack{
    Buffer buffer_[10];
    unsigned index_;

    void push(const Buffer& buffer);
    void push(const std::vector<Pixel>& undo, const std::vector<Pixel>& redo);
    void push(const std::vector<Pixel>& unre_do);
    void pop();
};
