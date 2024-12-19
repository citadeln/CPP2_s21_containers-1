#pragma once

#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class list {
 public:
  class ListIterator;
  class ListConstIterator;
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

 protected:
  struct node {
    value_type value_;
    node *next;
    node *prev;
    node(value_type value) : value_(value), next(nullptr), prev(nullptr) {}
  };

 public:
  class ListIterator {
    friend class list<T>;

   private:
    node *cur_node;
    node *first;
    node *last;

   public:
    ListIterator();
    ListIterator(list<T>::node *node, list<T>::node *first_node,
                 list<T>::node *last_node);
    ListIterator &operator++(int);
    ListIterator &operator--(int);
    ListIterator &operator++();
    ListIterator &operator--();
    reference operator*();
    bool operator==(const ListIterator &other) const;
    bool operator!=(const ListIterator &other) const;
  };

  class ListConstIterator : public ListIterator {
    friend class list<T>;

   private:
    node *cur_node;
    node *first;
    node *last;

   public:
    ListConstIterator();
    ListConstIterator(const ListIterator &node);
    const_reference operator*() const;
    bool operator==(const ListIterator &other) const;
  };

  list();
  list(size_type n);
  list(const std::initializer_list<value_type> &items);
  list(const list &other);
  list(list &&other);
  ~list();

  list<value_type> &operator=(list &other);
  list<value_type> &operator=(list &&other);
  bool operator==(const list &other) const;

  const_reference front() const;
  const_reference back() const;

  iterator begin() noexcept;
  iterator end() noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <class... Args>
  void insert_many_back(Args &&...args);

  template <class... Args>
  void insert_many_front(Args &&...args);

 protected:
  void list_init();
  void copy_list(const list &other);
  void push_node(const_reference value, bool mode);
  void delete_node(bool mode);

 private:
  node *first_;
  node *last_;
};
}  // namespace s21

namespace s21 {

template <typename T>
list<T>::ListIterator ::ListIterator() {}

template <typename T>
list<T>::ListIterator ::ListIterator(list<T>::node *node,
                                     list<T>::node *first_node,
                                     list<T>::node *last_node)
    : cur_node(node), first(first_node), last(last_node) {}

template <typename T>
typename list<T>::ListIterator &list<T>::iterator ::operator++(int) {
  cur_node = (cur_node) ? cur_node->next : first;
  return *this;
}

template <typename T>
typename list<T>::ListIterator &list<T>::iterator ::operator--(int) {
  cur_node = (cur_node) ? cur_node->prev : last;
  return *this;
}

template <typename T>
typename list<T>::ListIterator &list<T>::iterator ::operator++() {
  cur_node = (cur_node) ? cur_node->next : first;
  return *this;
}

template <typename T>
typename list<T>::ListIterator &list<T>::iterator ::operator--() {
  cur_node = (cur_node) ? cur_node->prev : last;
  return *this;
}

template <typename T>
typename list<T>::reference list<T>::iterator ::operator*() {
  return (cur_node) ? cur_node->value_ : last->value_;
}

template <typename T>
bool list<T>::ListIterator ::operator==(const ListIterator &other) const {
  return cur_node == other.cur_node;
}

template <typename T>
bool list<T>::ListIterator ::operator!=(const ListIterator &other) const {
  return cur_node != other.cur_node;
}

template <typename T>
list<T>::ListConstIterator ::ListConstIterator() {}

template <typename T>
list<T>::ListConstIterator ::ListConstIterator(const ListIterator &it)
    : cur_node(it.cur_node), first(it.first), last(it.last) {}

template <typename T>
typename list<T>::const_reference list<T>::const_iterator ::operator*() const {
  return (cur_node) ? cur_node->value_ : last->value_;
}

template <typename T>
bool list<T>::ListConstIterator ::operator==(const ListIterator &other) const {
  return cur_node == other.cur_node;
}

template <typename T>
list<T>::list() {
  list_init();
}

template <typename T>
list<T>::list(size_type n) {
  if (n >= this->max_size()) {
    throw std::out_of_range("Size is out of range.");
  }

  list_init();

  if (n) {
    for (size_t i = 0; i < n; i++) push_back(0);
  }
}

template <typename T>
list<T>::list(const std::initializer_list<value_type> &items) {
  list_init();

  for (auto &value : items) {
    push_back(value);
  }
}

template <typename T>
list<T>::list(const list &other) {
  copy_list(other);
}

template <typename T>
list<T>::list(list &&other) {
  first_ = other.first_;
  last_ = other.last_;

  other.list_init();
}

template <typename T>
list<T>::~list() {
  if (first_) {
    while (first_) {
      node *next = first_->next;
      delete first_;
      first_ = next;
    }
    list_init();
  }
}

template <typename T>
list<T> &list<T>::operator=(list &other) {
  this->~list();

  copy_list(other);

  return *this;
}

template <typename T>
list<T> &list<T>::operator=(list &&other) {
  this->~list();

  first_ = other.first_;
  last_ = other.last_;

  other.list_init();

  return *this;
}

template <typename T>
bool list<T>::operator==(const list &other) const {
  if (size() != other.size()) return false;

  node *p1 = first_;
  node *p2 = other.first_;

  while (p1) {
    if (p1->value_ != p2->value_) return false;
    p1 = p1->next;
    p2 = p2->next;
  }

  return true;
}

// ------------------------------------------------

template <typename T>
typename list<T>::const_reference list<T>::front() const {
  if (empty()) throw std::out_of_range("List is empty");

  return first_->value_;
}

template <typename T>
typename list<T>::const_reference list<T>::back() const {
  if (empty()) throw std::out_of_range("List is empty");

  return last_->value_;
}

// ------------------------------------------------

template <typename T>
typename list<T>::iterator list<T>::begin() noexcept {
  return iterator(this->first_, first_, last_);
}

template <typename T>
typename list<T>::iterator list<T>::end() noexcept {
  return iterator(nullptr, first_, last_);
}

// ------------------------------------------------

template <typename T>
bool list<T>::empty() const noexcept {
  return first_ == nullptr && last_ == nullptr;
};

template <typename T>
typename list<T>::size_type list<T>::size() const noexcept {
  size_type n = 0;
  node *p = first_;

  while (p) {
    n++;
    p = p->next;
  }

  return n;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / (sizeof(node) * 2);
}

// ------------------------------------------------

template <typename T>
void list<T>::clear() noexcept {
  this->~list();
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if (pos == begin()) {
    push_front(value);
    pos.cur_node = first_;
  } else if (pos == end()) {
    push_back(value);
    pos.cur_node = last_;
  } else {
    node *new_node = new node(value);
    new_node->next = pos.cur_node;
    new_node->prev = pos.cur_node->prev;
    pos.cur_node->prev->next = new_node;
    pos.cur_node->prev = new_node;
    pos.cur_node = new_node;
  }
  return pos;
}

template <typename T>
void list<T>::erase(iterator pos) {
  if (pos.cur_node == first_) {
    pop_front();
    pos.cur_node = first_;
  } else if (pos.cur_node == last_) {
    pop_back();
    pos = end();
  } else {
    node *del = pos.cur_node;
    pos.cur_node->next->prev = pos.cur_node->prev;
    pos.cur_node->prev->next = pos.cur_node->next;
    pos.cur_node = pos.cur_node->next;
    delete del;
  }
}

template <typename T>
void list<T>::push_back(const_reference value) {
  push_node(value, 1);
}

template <typename T>
void list<T>::pop_back() {
  delete_node(1);
}

template <typename T>
void list<T>::push_front(const_reference value) {
  push_node(value, 0);
}

template <typename T>
void list<T>::pop_front() {
  delete_node(0);
}

template <typename T>
void list<T>::swap(list &other) {
  if (first_ != other.first_ && last_ != other.last_) {
    std::swap(first_, other.first_);
    std::swap(last_, other.last_);
  }
}

template <typename T>
void list<T>::merge(list &other) {
  if (*this == other)
    return;
  else if (other.empty())
    return;
  else if (empty())
    return std::swap(*this, other);

  iterator it = end();
  splice(it, other);
  sort();
}

template <typename T>
void list<T>::splice(const_iterator pos, list &other) {
  if (other.size() == 0) return;

  if (pos == begin()) {
    first_->prev = other.last_;
    other.last_->next = first_;
    first_ = other.first_;
  } else if (pos == end()) {
    last_->next = other.first_;
    other.first_->prev = last_;
    last_ = other.last_;
  } else {
    pos.cur_node->prev->next = other.first_;
    other.first_->prev = pos.cur_node->prev;
    other.last_->next = pos.cur_node;
    pos.cur_node->prev = other.last_;
  }
  other.list_init();
}

template <typename T>
void list<T>::reverse() {
  node *p = first_;

  while (p) {
    std::swap(p->next, p->prev);
    p = p->prev;
  }
  std::swap(first_, last_);
}

template <typename T>
void list<T>::unique() {
  if (size() <= 1) return;

  value_type prev_val = first_->value_;
  node *p = first_->next;

  while (p) {
    if (prev_val == p->value_) {
      node *del = p;
      p->prev->next = p->next;
      if (p->next)
        p->next->prev = p->prev;
      else
        last_ = p->prev;
      p = p->next;
      delete del;
    } else {
      prev_val = p->value_;
      p = p->next;
    }
  }
}

template <typename T>
void list<T>::sort() {
  if (size() <= 1) return;

  node *max_node = first_;
  iterator it = begin();
  size_type max_size = size();
  size_type size = max_size;

  for (size_type j = 0; j < max_size; j++) {
    for (size_type i = 0; i < size; i++) {
      if (*it > max_node->value_) max_node = it.cur_node;
      it++;
    }
    if (max_node != last_) {
      if (max_node == first_) {
        max_node->next->prev = nullptr;
        first_ = max_node->next;
      } else {
        max_node->next->prev = max_node->prev;
        max_node->prev->next = max_node->next;
      }
      last_->next = max_node;
      max_node->prev = last_;
      max_node->next = nullptr;
      last_ = max_node;
    }
    it = begin();
    max_node = first_;
    size--;
  }
  reverse();
}

template <typename T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator it(pos.cur_node, pos.first, pos.last);
  iterator return_it;
  bool first = 1;

  for (auto &value : {args...}) {
    if (first) {
      return_it = insert(it, value);
      first = 0;
    } else
      insert(it, value);
  }

  return return_it;
}

template <typename T>
template <class... Args>
void list<T>::insert_many_back(Args &&...args) {
  for (auto &value : {args...}) push_back(value);
}

template <typename T>
template <class... Args>
void list<T>::insert_many_front(Args &&...args) {
  s21::list<T>::iterator it = begin();
  for (auto &value : {args...}) insert(it, value);
}

// ------------------------------------------------

template <typename T>
void list<T>::list_init() {
  first_ = nullptr;
  last_ = nullptr;
}

template <typename T>
void list<T>::copy_list(const list &other) {
  list_init();

  node *p = other.first_;

  while (p) {
    push_back(p->value_);
    p = p->next;
  }
}

/**
 * @brief Добавляет одну ячейку списка.
 *
 * @param switch
 *  - 0 - Добавляет ячейку в начале списка.
 *  - 1 - Добавляет ячейку в конце списка.
 */
template <typename T>
void list<T>::push_node(const_reference value, bool mode) {
  node *p = new node(value);

  if (empty()) {
    first_ = p;
    last_ = p;
  } else {
    if (mode) {
      p->prev = last_;
      last_->next = p;
      last_ = p;
    } else {
      p->next = first_;
      first_->prev = p;
      first_ = p;
    }
  }
}

/**
 * @brief Удаляет одну ячейку списка.
 *
 * @param switch
 *  - 0 - Удаляет ячейку в начале списка.
 *  - 1 - Удаляет ячейку в конце списка.
 */
template <typename T>
void list<T>::delete_node(bool mode) {
  if (empty()) return;

  if (size() == 1) {
    clear();
  } else {
    if (mode) {
      node *p = last_->prev;
      p->next = nullptr;
      delete last_;
      last_ = p;
    } else {
      node *p = first_->next;
      p->prev = nullptr;
      delete first_;
      first_ = p;
    }
  }
}
}  // namespace s21