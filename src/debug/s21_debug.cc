#define IFDEBUG 0
#if IFDEBUG == 1

#include <algorithm>
#include <iostream>
#include "../s21_vector.h"
#include <iostream>
// #include "../s21_containers.h"

// #include "../tests/test.h"
using namespace s21;
int main() {
 s21::vector<int> v (10);
 v.push_back(234);
 v.push_back(214);
 for(size_t i = 0; i < v.size(); i++) {
  std::cout << v[i] << std::endl;
 }
    v.shrink_to_fit();
    v.clear();
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    if(v.data() == nullptr){
      std::cout << "empty" << std::endl;
    }
}

#endif