#ifndef BASE_ITER_H_
#define BASE_ITER_H_
#include <cstddef>
namespace s21{
    // template<bool B, class T = void>
    //     struct enable_if {};
    // template<class T>
    //     struct enable_if<true, T> { typedef T type; };
    // template < typename A, typename B >
    // struct is_same
    // {
    //     static const bool value = false;
    // };
    // template < typename A >
    // struct is_same<A, A>
    // {
    //     static const bool value = true;
    // };

    template<typename T, template<typename> class childIter>
    class BaseIter{
        public:
            using reference = T&; using const_reference = const T&;
            using iterator_ptr = T*;
            BaseIter(){
                // init(this->ptr);
            };
            BaseIter(iterator_ptr ptr_){
                this->ptr = ptr_;
            };
            // Pre-increment
            BaseIter operator++(){
                this->ptr++;
                  return this->ptr;
            } 
             // Post-increment. "int" is a dummy signal that is a postfix operator.
            bool operator++(int){
                this->ptr++;
                return this->ptr;
            }
            virtual bool operator==(iterator_ptr ptr) noexcept{
                return this->ptr == ptr;
            }
            virtual bool operator!=(iterator_ptr ptr){
                return this->ptr != ptr;
            }
            virtual bool operator==(childIter<T> &other) noexcept{
                return this->ptr == other.ptr;
            }
            virtual bool operator!=(childIter<T> &other){
                return this->ptr != other.ptr;
            }
            virtual reference operator*(){
                
                return *this->ptr;
            }
            childIter<T> operator=(childIter<T> * other){
                this->ptr = other->ptr;
                return *this;
            }

        protected:
            iterator_ptr ptr;
            // virtual childIter init(iterator_ptr){
            //     return this;
            // };
        
    };
    // class BaseIter<T, s21::enable_if< s21::list|| s21::map || s21::set || s21::vector ||s21::array>{
    template<typename T, template<typename> class childIter>
    class BaseIterMiddle : public BaseIter<T, childIter>{
        public:
        childIter<T> operator--(){
            return --this->ptr;
            return this->ptr;
        }
        childIter<T> operator--(int){
            --this->ptr;
            return this->ptr;
        }
    };
    // Block is OK
    template<typename T, template<typename> class childIter>
    class BaseIterEnd : public BaseIterMiddle<T, childIter>{
        public:
        typedef size_t  size_type;

        childIter<T> operator+=(int n){
            this->ptr += n;
            return this->ptr;
        }
        childIter<T> operator-=(int n){
            this->ptr-=n;
            return this->ptr;
        }
        // OK
        childIter<T> operator+(int n){
            this->ptr += n;
            return this->ptr;
        }
        // OK
        friend childIter<T> operator+(int n, childIter<T> thiss){
             thiss.ptr += n;
             return thiss.ptr;
        }
        childIter<T> operator-(int n){
            this->ptr -= n;
            return this->ptr;
        }
        friend size_type operator-(childIter<T> n, childIter<T> thiss){
            return int(n.ptr - thiss.ptr);
        }
        bool  operator<(childIter<T> & other){
            return this->ptr < other.ptr;
        }
        bool operator<=(childIter<T> & other){
            return this->ptr <= other.ptr;
        }
        bool operator>(childIter<T> & other){
            return this->ptr > other.ptr;
        }
        // OK
        bool operator>=(childIter<T> & other){
            return this->ptr >= other.ptr;
        }
    };
    template<typename T>
    class VectorIterator : public BaseIterEnd<T, VectorIterator>{
        public:
        using iterator_ptr = T*;
        VectorIterator(){
            // init(this->ptr);
        };
        VectorIterator(iterator_ptr ptr_){
                this->ptr = ptr_;
            };
    };
    
    // class BaseIter<T, s21::enable_if< s21::list|| s21::map || s21::set || s21::vector ||s21::array>{
    // template<typename T>
    // class ListIterator : public BaseIterMiddle<T>{};
    
//     template<typename T>
//     class MapIterator : public BaseIterMiddle<T>{};

//     template<typename T>
//     class SetIterator : public BaseIterMiddle<T>{};
// 
}
#endif //BASE_ITER_H_