#ifndef SEQUENCE_CONTAINER_H_
#define SEQUENCE_CONTAINER_H_
#include <stdio.h>
#include "base_iter.h"
#include <initializer_list>
#include <utility>


namespace s21{
    template<typename T>
    class bsc {
        typedef T value_type;
        using iterator = BaseIter<T>;    
        using const_iterator = BaseIter<const T>;
        using reference = T&;
        using const_reference = const T&;
        typedef size_t size_type;
        private:
            value_type *data_;
            size_type size_;
            size_type capacity_;
                
        public:
        // Access funcs
        reference at(size_type pos){
            if (pos >= 0 && pos < this->data_ + this->size_)
            return this->data_[pos];
        }
        reference operator[](size_type pos){
            return this->data_[pos];
        };
        const_reference front(){
            return this->data_[0];
        }
        const_reference back(){
            return this->data_[this->size_ - 1];
        }
        value_type* data(){
            return this->data_;
        }

        
        // Interacts with class functions
        bsc(){
            this->data_ = new value_type[0];
            this->size_ = 0;
            this->capacity_ = 0;
            
        }
        bsc(const bsc& other){
            this->data_ = new value_type[other.capacity_];
            this->size_ = other.size_;
            this->capacity_ = other.capacity_;
            for (size_type i = 0; i < this->size_; i++){
                this->data_[i] = other.data_[i];
            }
        }
        bsc(size_type n){
            this->data_ = new value_type[n*2];
            this->size_ = n;
            this->capacity_ = n*2; 
        }
        bsc(std::initializer_list<value_type> const & items){
            this->data_ = new value_type[items.size()];
            this->size_ = items.size();
            this->capacity_ = items.size();
            for(size_type i = 0; i < this->size_; i++){
                this->data_[i] = items[i];
            }
        }
        bsc(bsc && other){
            this->data_ = other.data_;
            this->size_ = other.size_;
            this->capacity_ = other.capacity_;
            other.~bsc();
        }
        bsc operator=(bsc&& other){
            this = std::move(other);
            return *this;
        }
        bsc& operator=(const bsc& other){
            this->data_ = new value_type[other.capacity_];
            this->size_ = other.size_;
            this->capacity_ = other.capacity_;
            for (size_type i = 0; i < this->size_; i++){
                this->data_[i] = other.data_[i];
            }
            return *this;
            
        }
        ~bsc(){
            delete[] this->data_;
            this.data_ = nullptr;
            this.size = 0;
            this.capacity_ = 0;
        }
        // Iterator funcs
        iterator begin(){
            return iterator(this->data_);
        }
        iterator end(){
            return iterator(this->data_ + this->size_);
        }
        // Full container info
        bool empty(){
            return this->size_ == 0;
        }
        size_type size(){
            return this->size_;
        }
        size_type max_size(){
            return this->capacity_;
        }
        size_type capacity(){
            return this->capacity_;
        }
        void shrink_to_fit(){
            if(this->size < this->capacity_){
                value_type *temp = new value_type[this->size_];
                for(size_type i = 0; i < this->size_; i++){
                    temp[i] = this->data_[i];
                }
                delete[] this->data_;
                this->data_ = temp;
                this->capacity_ = this->size_;
                
            }
        }
        void reverse(size_type size){
            value_type *temp = new value_type[size];
            for(size_type i = 0; i < size; i++){
                temp[i] = this->data_[i];
            }
        }

        // Modifiers
        void clear(){
            this->size_ = 0;
            this->capacity_ = 0;
            delete[] this->data_;
            this->data_ = nullptr;
        }
        void increase_capacity(){
            value_type *temp = new value_type[this->capacity_*2];
                for(size_type i = 0; i < this->size_; i++){
                    temp[i] = this->data_[i];
                }
                this->data_ = temp;
            
        }
        iterator insert(iterator pos, const_reference value){
            if(this->capacity_<=this->size_){
            increase_capacity();
            }    
            for(size_type i = this->size_; i > pos; i--){
                this->data_[i] = this->data_[i-1];
            }
            this->data_[pos] = value;
        }
        void erase(iterator pos){
            for(size_type i = pos; i < this->size_; i++){
                this->data_[i] = this->data_[i+1];
            }
            this->size_--;

        }
        void push_back(const_reference value){
            if(this->capacity_<=this->size_){
                increase_capacity();
            }
            this->data_[this->size_] = value;
        }
        void pop_back(){
            this->size_--;
        }
        void swap(bsc& other){
            bsc temp = other;
            other = *this;
            *this = temp;
            
        }
        // JUNK ====================== 
        // TODO: DELETE 
        // bsc(size_type, value_type & = value_type());
        // reverse_iterator rbegin();
        // reverse_iterator rend();
        // resize(size_type, T);
        // insert(iterator, size_type, T&);
        // insert<IT>(iterator, IT, IT); // So rather IT mean iterator type, it could bu iterator and reverse iterator.
        // erase(iterator, iterator);
        // T& front();
        // T& back();
    };
}
#endif // //SEQUENCE_CONTAINER_H_