#include"sequence_container.h"
#include "base_iter.h"
namespace s21{
    template <typename T>
    class Vector : public bsc<T>{
        private:
        using iterator = VectorIterator<T>;
    };
}