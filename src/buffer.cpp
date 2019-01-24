#include"buffer.hpp"

void Stack::push(const Buffer& buffer){
    buffer_[index_].undo_=buffer.undo_;
    buffer_[index_].redo_=buffer.redo_;
    if((++index_)>10) index_=0;
}

void Stack::push(const std::vector<Pixel>& undo, const std::vector<Pixel>& redo){
    buffer_[index_].undo_=undo;
    buffer_[index_].redo_=redo;
    if((++index_)>10) index_=0;
}

void Stack::push(const std::vector<Pixel>& unre_do){
    buffer_[index_].undo_=unre_do;
    buffer_[index_].redo_=unre_do;
    if((++index_)>10) index_=0;
}

void Stack::pop(){
    buffer_[index_].undo_.clear();
    --index_;
}
