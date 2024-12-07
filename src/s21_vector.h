#include"sequence_container.h"
#include "base_iter.h"
namespace s21{
    template <typename T>
    class Vector : public bsc{
        private:
        using iterator = VectorIterator<T>;
    };
}