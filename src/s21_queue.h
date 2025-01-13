#ifndef S21_QUEUE_H_
#define S21_QUEUE_H_

#include "s21_dequeue.h"

namespace s21 {
template <typename T>
class queue : private dequeue<T> {
  using super = dequeue<T>;
  using self = queue<T>;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  //  using super::size;  // Bring base class size() into scope

 public:
  queue();
  // initializer list constructor, creates queue initizialized using
  // std::initializer_list
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &other);      //	copy constructor
  queue(queue &&other) noexcept;  //	move constructor
  ~queue();                       //	destructor
  queue<T> &operator=(
      const queue<T> &other);  // assignment operator overload for copy object
  queue operator=(
      queue &&other);  //	assignment operator overload for moving object
  // queue operator=(const queue &other);
  const_reference front();           //	access the first element
  const_reference back();            // access the last element
  bool empty();                      // checks whether the container is empty
  size_type size();                  // retur
                                     // queue<T>::queue() : queue_() {}
  void push(const_reference value);  // inserts element at the end
  void pop();                        // removes the first element
  void swap(queue &other);           //	swaps the contents
  // void insert_many_back(Args&&... args); // appends new elements to the end
  // of the container

  template <typename... Args>
  void insert_many_back(Args &&...args);
};

template <typename T>
queue<T>::queue() {}

template <typename T>
queue<T>::queue(std::initializer_list<value_type> const &items) {
  for (const auto i : items) super::insertRear(i);
};

template <typename T>
queue<T>::queue(const queue &other) : super(other) {}

template <typename T>
queue<T>::queue(queue &&other) noexcept {
  if (this != &other) {
    super::erase();
    this->front_ = other.front_;
    this->rear_ = other.rear_;
    this->size_ = other.size_;

    // Сброс перемещённого объекта
    other.front_ = nullptr;
    other.rear_ = nullptr;
    other.size_ = 0;
  }
}

template <typename T>
queue<T>::~queue(){};

template <typename T>
queue<T> &queue<T>::operator=(const queue<T> &other) {
  if (this != &other) {
    super::erase();
    Node<T> *temp = other.front_;
    while (temp != nullptr) {
      super::insertRear(temp->data);
      temp = temp->next;
    }
  }
  return *this;
}

template <typename T>
queue<T> queue<T>::operator=(queue &&other) {
  if (this != &other) {
    super::erase();
    while (!other.isEmpty()) {
      super::insertRear(other.getFront());
      other.deleteFront();
    }
  }
  return *this;
}

template <typename T>
typename queue<T>::const_reference queue<T>::front() {
  if (super::isEmpty()) {
    throw std::underflow_error("Queue is empty");
  }
  return this->front_->data;
}

template <typename T>
typename queue<T>::const_reference queue<T>::back() {
  if (super::isEmpty()) {
    throw std::underflow_error("Queue is empty");
  }
  return this->rear_->data;
}

template <typename T>
bool queue<T>::empty() {
  return super::isEmpty();
}

template <typename T>
typename queue<T>::size_type queue<T>::size() {
  return super::size();
}

template <typename T>
void queue<T>::push(const_reference value) {
  super::insertRear(value);
}

template <typename T>
void queue<T>::pop() {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  super::deleteFront();
}

template <typename T>
void queue<T>::swap(queue &other) {
  queue temp = *this;
  *this = other;
  other = temp;
}

template <typename T>
template <typename... Args>
void queue<T>::insert_many_back(Args &&...args) {
  (push(args), ...);
}
}  // namespace s21

#endif  // S21_QUEUE_H_
