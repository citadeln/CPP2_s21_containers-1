
namespace s21{
    template<typename T>
    class BaseIter{
        public:
            using iterator_ptr = T*;
            BaseIter();
            BaseIter(iterator_ptr);
        
            BaseIter operator++(){
                  this.ptr++;
                return this;
            } // Pre-increment

            BaseIter operator++(int){
                  this.ptr++;
                return this;
            } // Post-increment. "int" is a dummy signal that is a postfix operator.
            BaseIter operator==(iterator_ptr ptr){
                return this.ptr == ptr;
            }
            BaseIter operator!=(iterator_ptr ptr){
                return this.ptr != ptr;
            }
        private:
            iterator_ptr ptr;
    }

}