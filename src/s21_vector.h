#ifndef VECTOR_H_
#define VECTOR_H_
#include"sequence_container.h"
#include "base_iter.h"
#include <algorithm>
namespace s21{
    template <typename T>
    class vector : public bsc<T, VectorIterator>{
        public:
        using bsc<T, VectorIterator>::bsc;
        using iterator = VectorIterator<T>;
        typedef T value_type;
        using const_iterator = VectorIterator<T>;
        using reference = T&;
        using const_reference = const T&;
        typedef size_t size_type;
        public:
         vector(){
            this->data_ = new value_type[0];
            this->size_ = 0;
            this->capacity_ = 0;
            
        }
        vector(const vector& other){
            this->data_ = new value_type[other.capacity_];
            this->size_ = other.size_;
            this->capacity_ = other.capacity_;
            for (size_type i = 0; i < this->size_; i++){
                this->data_[i] = other.data_[i];
            }
        }
        explicit vector(size_type n){
            this->data_ = new value_type[n];
            this->size_ = 0;
            this->capacity_ = n; 
        }
        vector(std::initializer_list<value_type> const & items){
            this->data_ = new value_type[items.size()];
            this->size_ = items.size();
            this->capacity_ = items.size();
            // for(size_type i = 0; i < this->size_; i++){
            //     this->data_[i] = items[i];
            // }
            std::copy(items.begin(), items.end(), this->data_);
        }
        vector(vector && other){
            this->data_ = other.data_;
            this->size_ = other.size_;
            this->capacity_ = other.capacity_;
            other.clear();
        }
         vector& operator=(const vector& other){
            if(!this->data_)delete [] this->data_;
            this->data_ = new value_type[other.capacity_];
            this->size_ = other.size_;
            this->capacity_ = other.capacity_;
            for (size_type i = 0; i < this->size_; i++){
                this->data_[i] = other.data_[i];
            }
            return *this;
            
        }

        void swap(vector& other){
            vector temp(std::move(*this));
            *this = std::move(other);
            other = std::move(temp);

            
        }
         void increase_capacity(){
            value_type *temp = new value_type[this->capacity_*2];
                for(size_type i = 0; i < this->size_; i++){
                    temp[i] = this->data_[i];
                }
                this->data_ = temp;
                this->capacity_ *= 2;
            
        }
        void shrink_to_fit(){
            if(this->size_ < this->capacity_){
                value_type *temp = new value_type[this->size_];
                for(size_type i = 0; i < this->size_; i++){
                    temp[i] = this->data_[i];
                }
                delete[] this->data_;
                this->data_ = temp;
                this->capacity_ = this->size_;
                
            }
        }
        // vector
        void reverse(size_type size){
            value_type *temp = new value_type[size];
            for(size_type i = 0; i < size; i++){
                temp[i] = this->data_[i];
            }
        }

        iterator insert(iterator pos, const_reference value){
            size_type posn = pos - this->begin();
            if(posn>this->size())
            throw std::out_of_range("Out of range");
            if(this->capacity_<=this->size_){
            increase_capacity();
            }    
            for(size_type i = this->size(); i > posn; i--){
                this->data_[i] = this->data_[i-1];
            }
            this->data_[posn] = value;
            this->size_++;
            return pos;
        }
        void erase(iterator pos){
            for(size_type i = pos - this->begin(); i < this->size(); i++){
                this->data_[i] = this->data_[i+1];
            }
            this->size_--;

        }
        // vector
        void push_back(const_reference value){
            if(this->capacity_<=this->size_){
                increase_capacity();
            }
            this->data_[this->size_] = value;
            this->size_++;
        }
        void pop_back(){
            this->size_--;
        }
        
    };
}
#endif // VECTOR_H_