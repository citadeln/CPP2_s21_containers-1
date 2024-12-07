#include <stdio.h>

namespace s21{
    template<typename T>
    class bsc {
        private:
            using iterator = base_iter<T>;    
            typedef size_t size_type;
                
        public:
        bsc();
        bsc(bsc&);
        bsc(size_type, T & = T());
        operator=(bsc&);
        iterator begin();
        iterator end();
        reverse_iterator rbegin();
        reverse_iterator rend();
        size_type size();
        resize(size_type, T);
        bool empty();
        insert(iterator, T&);
        insert(iterator, size_type, T&);
        insert<IT>(iterator, IT, IT); // So rather IT mean iterator type, it could bu iterator and reverse iterator.
        erase(iterator);
        erase(iterator, iterator);
        push_back(T&);
        pop_back();
        T& front();
        T& back();
    }
}