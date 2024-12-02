
namespace s21{
    template<bool B, class T = void>
        struct enable_if {};
    template<class T>
        struct enable_if<true, T> { typedef T type; };
    template < typename A, typename B >
    struct is_same
    {
        static const bool value = false;
    };
    template < typename A >
    struct is_same<A, A>
    {
        static const bool value = true;
    };

    template<typename T>
    class BaseIter{
        public:
            using iterator_ptr = T*;
            BaseIter<T>();
            BaseIter<T>(iterator_ptr);
            // Pre-increment
            BaseIter<T> operator++(){
                  this.ptr++;
                return this;
            } 
             // Post-increment. "int" is a dummy signal that is a postfix operator.
            BaseIter<T> operator++(int){
                  this.ptr++;
                return this;
            }
            bool operator==(iterator_ptr ptr){
                return this.ptr == ptr;
            }
            bool operator!=(iterator_ptr ptr){
                return this.ptr != ptr;
            }
      

        private:
            iterator_ptr ptr;
        
    };
    template<typename T>
    // class BaseIter<T, s21::enable_if< s21::list|| s21::map || s21::set || s21::vector ||s21::array>{
    class BaseIterMiddle : public BaseIter<T>{
        public:
        BaseIter<T> operator--(){
            this.ptr--;
            return this;
        }
        BaseIter<T> operator--(int){
            this.ptr--;
            return this;
        }
    };
    template<typename T>
    // class BaseIter<T, typename enable_if_t<s21::vector<T> || s21::array<T>>>{
    class BaseIterEnd : public BaseIterMiddle<T>{
        public:
        BaseIter<T> operator+=(int n){
            return this;
        }
        BaseIter<T> operator-=(int n){
            return this;
        }
        BaseIter<T> operator+(int n){
            return this;
        }
        BaseIter<T> operator-(int n){
            return this;
        }
        BaseIter<T> operator<(BaseIter<T> & other){
            return this.ptr < other.ptr;
        }
        BaseIter<T> operator<=(BaseIter<T> & other){
            return this.ptr <= other.ptr;
        }
        BaseIter<T> operator>(BaseIter<T> & other){
            return this.ptr > other.ptr;
        }
        BaseIter<T> operator>=(BaseIter<T> & other){
            return this.ptr >= other.ptr;
        }
    };
    template<typename T>
    class VectorIterator : public BaseIterEnd<T>{};
    
    // class BaseIter<T, s21::enable_if< s21::list|| s21::map || s21::set || s21::vector ||s21::array>{
    template<typename T>
    class ListIterator : public BaseIterMiddle<T>{};
    
    template<typename T>
    class MapIterator : public BaseIterMiddle<T>{};

    template<typename T>
    class SetIterator : public BaseIterMiddle<T>{};
}