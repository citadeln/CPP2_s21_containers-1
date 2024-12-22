#ifndef S21_ARRAY_H_
#define S21_ARRAY_H_
#include "sequence_container.h"
#include "base_iter.h"
namespace s21{
template <typename T>
class array : public bsc<T, ArrayIterator>{
     public:
        using bsc<T, ArrayIterator>::bsc;
        using iterator = ArrayIterator<T>;
        typedef T value_type;
        using const_iterator = ArrayIterator<T>;
        using reference = T&;
        using const_reference = const T&;
        typedef size_t size_type;
        public:
         array(){
            this->data_ = new value_type[0];
            
        }
        array(const array& other){
            this->data_ = new value_type[other.size_];
            this->size_ = other.size_;
            for (size_type i = 0; i < this->size_; i++){
                this->data_[i] = other.data_[i];
            }
        }
        explicit array(size_type n){
            this->data_ = new value_type[n];
            this->size_ = n;
        }
        array(std::initializer_list<value_type> const & items){
            this->data_ = new value_type[items.size()];
            this->size_ = items.size();
            // for(size_type i = 0; i < this->size_; i++){
            //     this->data_[i] = items[i];
            // }
            std::copy(items.begin(), items.end(), this->data_);
        }
        array(array && other){
            this->data_ = other.data_;
            this->size_ = other.size_;
            other.size_ = 0;
            other.capacity_ = 0;
            other.data_ = nullptr;
        }
         array& operator=(const array& other){
            if(!this->data_)delete [] this->data_;
            this->data_ = new value_type[other.size_];
            this->size_ = other.size_;
            for (size_type i = 0; i < this->size_; i++){
                this->data_[i] = other.data_[i];
            }
            return *this;
            
        }
        size_type max_size(){
            return this->size_;
        }
        void swap(array& other){
            if(*this!= other){
            array temp(std::move(*this));
            *this = std::move(other);
            other = std::move(temp);
            }
            
        }
        void fill(const_reference value){
            for(size_type i = 0; i < this->size_; i++){
                this->data_[i] = value;
            }
    
        }
        
};
}
#endif // S21_ARRAY_H_