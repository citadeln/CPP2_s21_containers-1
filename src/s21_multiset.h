#ifndef S21_MULTISET_H_
#define S21_MULTISET_H_

#include <functional>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <stdexcept>

#include "s21_set.h"
#include "s21_vector.h"

namespace s21 {
template <typename T, typename Compare = std::less<T>>
class multiset : public s21::set<T, Compare> {
  friend class set<T, Compare>;
  using key_type = T;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;
  using super = s21::set<T, Compare>;
  using Node = typename super::Node;

 public:
  using iterator = typename super::iterator;
  multiset(){};
  multiset(std::initializer_list<value_type> values) {
    for (const auto& value : values) {
      this->insert(value);
    }
  };
  multiset(const multiset& ms);
  multiset(multiset&& ms);
  ~multiset(){};
  multiset& operator=(multiset&& ms) noexcept;

  bool insert(const T& value) override;
  size_type count(const T& key);

  iterator find(const T& key) {
    iterator it = this->begin(), end = this->end();
    // Node * p = getNode();
    std::less_equal<T> cmp;
    while (it != end && cmp(it.getNode()->value, key)) {
      if (it.getNode()->value == key) {
        return it;
      }
      ++it;
    }
    throw std::out_of_range("Element not found!");
    return end;
  }

  iterator lower_bound(const T& key) {
    iterator it = this->begin(), end = this->end();
    if (it == end) throw std::out_of_range("Out of range");
    std::less<T> cmp;
    while (it != end && cmp(key, it.getNode()->value)) {
      ++it;
    }
    if (it != this->begin()) {
      --it;
    }
    return it;
  }

  iterator upper_bound(const T& key) {
    iterator it = this->begin(), end = this->end();
    if (it == end) throw std::out_of_range("Out of range");
    std::less_equal<T> cmp;
    iterator tmp;
    while (it != end && cmp(it.getNode()->value, key)) {
      tmp = it;
      ++it;
    }
    auto t = tmp;
    if (++t != end) {
      ++tmp;
    }
    return tmp;
  }

  template <typename... Args>
  vector<std::pair<typename s21::multiset<T>::iterator, bool>> insert_many(
      Args&&... args) {
    vector<std::pair<typename s21::multiset<T>::iterator, bool>> res;

    for (auto arg : {args...}) {
      bool bl = this->insert(arg);

      std::pair<typename s21::multiset<T>::iterator, bool> p(
          typename s21::multiset<T>::iterator(this->it), bl);
      res.push_back(p);
      // vector<std::pair<typename s21::multiset<T>::iterator,bool>> res = {p};

      // return res;
      // r = res;
    }
    return res;
  }
};

template <typename T, typename Compare>
size_t multiset<T, Compare>::count(const T& key) {
  iterator it = this->begin(), end = this->end();
  size_t count = 0;
  std::less_equal<T> cmp;
  while (it != end && cmp(it.getNode()->value, key)) {
    if (it.getNode()->value == key) {
      ++count;
    }
    ++it;
  }
  return count;
}

template <typename T, typename Compare>
bool multiset<T, Compare>::insert(const T& value) {
  if (!this->root_) {
    this->it = this->root_ = new Node(value);
    ++this->size_;
    return true;
  }
  this->root_ = this->insertNode(this->root_, value);
  ++this->size_;
  return true;
}

template <typename T, typename Compare>
multiset<T, Compare>& multiset<T, Compare>::operator=(multiset&& s) noexcept {
  if (this != &s) {
    this->clear();

    // Перемещаем данные
    this->root_ = s.root_;
    this->size_ = s.size_;
    this->comp_ = std::move(s.comp_);

    s.root_ = nullptr;
    s.size_ = 0;
  }
  return *this;
}
}  // namespace s21

#endif /* S21_MULTISET_H_ */