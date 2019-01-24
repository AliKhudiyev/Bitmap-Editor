#include"buffer.hpp"

// void BUFFER::push(const std::vector<Pixel>& undo, const std::vector<Pixel>& redo){
//     BUFFER::undo_[BUFFER::u_index]=undo;
//     BUFFER::redo_[BUFFER::r_index]=redo;
// }

// void BUFFER::push(bool type, const std::vector<Pixel>& buffer){
//     if(type==UNDO) BUFFER::undo_[BUFFER::u_index]=buffer;
//     else if(type==REDO) BUFFER::redo_[BUFFER::r_index]=buffer;    
// }

// void BUFFER::push(const std::vector<Pixel>& unre_do){
//     BUFFER::undo_[BUFFER::u_index]=unre_do;
//     BUFFER::redo_[BUFFER::r_index]=unre_do;
// }

// void BUFFER::pop(bool type){
//     if(type==UNDO) undo_[u_index].clear();
//     else if(type==REDO) redo_[r_index].clear();
// }
