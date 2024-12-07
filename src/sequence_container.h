#include <stdio.h>

namespace s21{
    template<typename T>
    class bsc {
        private:
            typedef T value_type;
            using iterator = base_iter<T>;    
            using const_iterator = base_iter<const T>;
            using reference = T&;
            typedef size_t size_type;
                
        public:
        reference at(size_type pos);
        reference operator[](size_type pos);
        const_reference front();
        const_reference back();
        value_type* data();


        bsc();
        bsc(bsc&);
        bsc(size_type, value_type & = value_type());
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