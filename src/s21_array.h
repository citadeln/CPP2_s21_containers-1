// #include "sequence_container.h"

// template <typename T>
// class array : public bsc<T, ArrayIterator>{
//      public:
//         using bsc<T, VectorIterator>::bsc;
//         using iterator = VectorIterator<T>;
//         typedef T value_type;
//         using const_iterator = VectorIterator<T>;
//         using reference = T&;
//         using const_reference = const T&;
//         typedef size_t size_type;
//         public:
//          vector(){
//             this->data_ = new value_type[0];
//             this->size_ = 0;
//             this->capacity_ = 0;
            
//         }
//         vector(const vector& other){
//             this->data_ = new value_type[other.capacity_];
//             this->size_ = other.size_;
//             this->capacity_ = other.capacity_;
//             for (size_type i = 0; i < this->size_; i++){
//                 this->data_[i] = other.data_[i];
//             }
//         }
//         explicit vector(size_type n){
//             this->data_ = new value_type[n];
//             this->size_ = 0;
//             this->capacity_ = n; 
//         }
//         vector(std::initializer_list<value_type> const & items){
//             this->data_ = new value_type[items.size()];
//             this->size_ = items.size();
//             this->capacity_ = items.size();
//             // for(size_type i = 0; i < this->size_; i++){
//             //     this->data_[i] = items[i];
//             // }
//             std::copy(items.begin(), items.end(), this->data_);
//         }
//         vector(vector && other){
//             this->data_ = other.data_;
//             this->size_ = other.size_;
//             this->capacity_ = other.capacity_;
//             other.clear();
//         }
//          vector& operator=(const vector& other){
//             if(!this->data_)delete [] this->data_;
//             this->data_ = new value_type[other.capacity_];
//             this->size_ = other.size_;
//             this->capacity_ = other.capacity_;
//             for (size_type i = 0; i < this->size_; i++){
//                 this->data_[i] = other.data_[i];
//             }
//             return *this;
            
//         }
// }