#ifndef S21_STACK_H_
#define S21_STACK_H_

#include "s21_dequeue.h"

namespace s21 {
template <typename T>
class stack : private dequeue<T> {
  using super = dequeue<T>;
  using self = stack<T>;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  stack() {}
  stack(const stack &s) { this = s; }
  stack(std::initializer_list<value_type> const &items) {
    for (auto i : items) super::insertRear(i);
  }
  stack(stack &&s) {
    this = s;
    super::s.erase();
  }
  ~stack() {}
  stack operator=(const stack &&s) {
    if (this != &s) {
      super::erase();
      Node<T> *temp = s.front_;
      while (temp != NULL) {
        insertRear(temp->data);
        temp = temp->next;
      }
    }
    return *this;
  }

  stack operator=(const stack &s) {
    if (this != &s) {
      Node<T> *temp = s.front_;
      while (temp != NULL) {
        super::insertRear(temp->data);
        temp = temp->next;
      }
    }
    return *this;
  }

  bool operator!=(const stack &s) {
    bool status = true;
    if (this.size_ != s.size())
      return true;
    else {
      Node<T> *temp1 = this->front_;
      Node<T> *temp2 = s.front_;
      while (temp1 != NULL && temp2 != NULL && status) {
        if (temp1->data == temp2->data) status = false;
        temp1 = temp1->next;
        temp2 = temp2->next;
      }
      return status;
    }
  }

  // Access functions
  const_reference top() {
    if (empty()) throw std::out_of_range("Stack is empty");
    return this->rear_->data;
  }
  size_type size() { return super::size(); }
  bool empty() { return super::isEmpty(); }

  // Modifiers
  void push(const_reference value) { super::insertRear(value); }
  void pop() {
    if (empty()) throw std::out_of_range("Stack is empty");
    super::deleteRear();
  }
  void swap(stack &s) {
    stack temp = *this;
    *this = s;
    s = temp;
  }
  template <typename... Args>
  void insert_many_back(Args &&...args) {
    this->insert_many_back_base(args...);
  }
};
}  // namespace s21

#endif  // S21_STACK_H_