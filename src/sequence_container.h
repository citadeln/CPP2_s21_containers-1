#ifndef SEQUENCE_CONTAINER_H_
#define SEQUENCE_CONTAINER_H_
#include <stdio.h>

#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <utility>

#include "base_iter.h"

namespace s21 {
template <typename T, template <typename> class IterCont>
class bsc {
 protected:
  typedef T value_type;
  using iterator = IterCont<T>;
  using const_iterator = IterCont<const T>;
  using reference = T&;
  using const_reference = const T&;
  typedef size_t size_type;

 protected:
  value_type* data_ = nullptr;
  size_type size_ = 0;
  size_type capacity_ = 0;

 public:
  // Access funcs
  reference at(size_type pos) {
    iterator p = iterator(pos + this->begin());
    iterator it_b = this->begin();
    iterator it_end = this->end();
    if (p >= it_b && p < it_end)
      return this->data_[pos];
    else
      throw std::out_of_range("Out of range");
  }
  reference operator[](size_type pos) { return this->data_[pos]; };
  const_reference front() { return this->data_[0]; }
  const_reference back() { return this->data_[this->size_ - 1]; }
  value_type* data() { return this->data_; }

  // Interacts with class functions

  bsc operator=(bsc&& other) {
    this = std::move(other);
    return *this;
  }
  bsc& operator=(const bsc& other) {
    if (!this->data_) delete[] this->data_;
    this->data_ = new value_type[other.capacity_];
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    for (size_type i = 0; i < this->size_; i++) {
      this->data_[i] = other->data_[i];
    }
    return *this;
  }
  // bsc& operator=(bsc& other){
  //     this->data_ = new value_type[other.capacity_];
  //     this->size_ = other.size_;
  //     this->capacity_ = other.capacity_;
  //     for (size_type i = 0; i < this->size_; i++){
  //         this->data_[i] = other->data_[i];
  //     }
  //     return *this;

  // }
  ~bsc() {
    delete[] this->data_;
    this->data_ = nullptr;
    this->size_ = 0;
    this->capacity_ = 0;
  }
  // Iterator funcs
  virtual iterator begin() { return this->data_; }
  virtual iterator end() { return this->data_ + this->size_; }
  // Full container info
  bool empty() { return this->size_ == 0; }
  size_type size() { return this->size_; }
  size_type max_size() { return this->capacity_; }
  bool operator==(const bsc& other) const {
    bool status = true;
    status = this->size_ == other.size_;
    if (status) {
      for (size_type i = 0; i < this->size_ && status; i++) {
        if (this->data_[i] != other.data_[i]) {
          status = false;
        }
      }
    }
    return status;
  }
  bool operator!=(const bsc& other) const { return !(*this == other); }
  // vector

  // vector

  // vector

  // JUNK ======================
  // TODO: DELETE
  // bsc(size_type, value_type & = value_type());
  // reverse_iterator rbegin();
  // reverse_iterator rend();
  // resize(size_type, T);
  // insert(iterator, size_type, T&);
  // insert<IT>(iterator, IT, IT); // So rather IT mean iterator type, it could
  // bu iterator and reverse iterator. erase(iterator, iterator); T& front(); T&
  // back();
};
}  // namespace s21
#endif  // //SEQUENCE_CONTAINER_H_