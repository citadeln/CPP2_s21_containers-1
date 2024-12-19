#define IFDEBUG 0
#if IFDEBUG == 1

// #include <algorithm>
#include <iostream>
#include <list>
#include "../s21_containers.h"

// #include "../tests/test.h"

int main() {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  s21.reverse();
  orig.reverse();

  // EXPECT_EQ(s21.front(), orig.front());
  // EXPECT_EQ(s21.back(), orig.back());
  // EXPECT_EQ(s21.size(), orig.size());

  std::cout << s21.front() << '\t' << orig.front() << std::endl;

  return 0;

}


//   std::cout << "Well done!" << std::endl;


// // push back
//   for(size_t i = 0; i < 32; ++i)
//     traits::construct(newarr+i, arr[i]);


//   template <typename U>
//   using rebind = allocator<U>

// }

#endif
/*
template<class Key, class T>
class Map {

}

map<int, T::int>
*/