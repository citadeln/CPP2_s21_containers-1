#ifndef S21_DEQUEUE_H_
#define S21_DEQUEUE_H_

#include <cstddef>
#include <stdexcept>

namespace s21 {
template <typename T>
struct Node {
  T data;
  Node<T> *prev, *next;
  static Node<T> *get_node(T data) {
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->prev = newNode->next = nullptr;
    return newNode;
  }
};
template <typename T>
class dequeue {
 protected:
  Node<T> *front_ = NULL;
  Node<T> *rear_ = NULL;
  size_t size_ = 0;

 public:
  dequeue() {
    front_ = rear_ = NULL;
    size_ = 0;
  }
  dequeue(std::initializer_list<T> const &items) {
    for (T i : items) insertRear(i);
  }
  dequeue(const dequeue<T> &s) { *this = s; }
  ~dequeue() {
    while (front_ != NULL) {
      deleteFront();
    }
  }
  void insertFront(T data);
  void insertRear(T data);
  void deleteFront();
  void deleteRear();
  T getFront();
  T getRear();
  virtual size_t size();
  bool isEmpty();
  void erase();
  dequeue<T> &operator=(const dequeue<T> &s);
  bool operator!=(const dequeue<T> &s);
  template <typename... Args>
  void insert_many_back_base(Args... args);
};

template <typename T>
bool s21::dequeue<T>::operator!=(const dequeue<T> &s) {
  bool status = true;
  if (this->size_ != s.size_)
    return true;
  else {
    Node<T> *temp1 = front_;
    Node<T> *temp2 = s.front_;
    while (temp1 != nullptr && temp2 != nullptr && status) {
      if (temp1->data == temp2->data) status = false;
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
  }
  return status;
}

template <typename T>
dequeue<T> &s21::dequeue<T>::operator=(const dequeue<T> &s) {
  if (this != &s) {
    erase();
    Node<T> *temp = s.front_;
    while (temp != nullptr) {
      insertRear(temp->data);
      temp = temp->next;
    }
  }
  return *this;
}

template <typename T>
bool s21::dequeue<T>::isEmpty() {
  return front_ == nullptr;
}

template <typename T>
size_t s21::dequeue<T>::size() {
  return size_;
}

template <typename T>
void s21::dequeue<T>::insertFront(T data) {
  Node<T> *newNode = Node<T>::get_node(data);
  if (newNode == nullptr) {
    throw std::overflow_error("Overflow error");
  } else {
    if (front_ == nullptr) {
      rear_ = front_ = newNode;
    } else {
      newNode->next = front_;
      front_->prev = newNode;
      front_ = newNode;
    }
    size_++;
  }
}

template <typename T>
void s21::dequeue<T>::insertRear(T data) {
  Node<T> *newNode = Node<T>::get_node(data);
  if (newNode == nullptr) {
    throw std::overflow_error("Overflow error");
  } else {
    if (front_ == nullptr) {
      rear_ = front_ = newNode;
    } else {
      newNode->prev = rear_;
      rear_->next = newNode;
      rear_ = newNode;
    }
    size_++;
  }
}

template <typename T>
void s21::dequeue<T>::deleteFront() {
  if (front_ == NULL) {
    throw std::underflow_error("Underflow error");
  } else {
    Node<T> *temp = front_;
    front_ = front_->next;
    if (front_ == NULL) {
      rear_ = NULL;
    } else {
      front_->prev = NULL;
    }
    delete temp;
    size_--;
  }
}

template <typename T>
void s21::dequeue<T>::deleteRear() {
  if (rear_ == NULL) {
    throw std::underflow_error("Underflow error");
  } else {
    Node<T> *temp = rear_;
    rear_ = rear_->prev;
    if (rear_ == NULL) {
      front_ = NULL;
    } else {
      rear_->next = NULL;
    }
    delete temp;
    size_--;
  }
}

template <typename T>
T s21::dequeue<T>::getFront() {
  if (front_ == NULL) {
    throw std::underflow_error("Underflow error");
  }

  return front_->data;
}

template <typename T>
T s21::dequeue<T>::getRear() {
  if (rear_ == NULL) {
    throw std::underflow_error("Underflow error");
  }

  return rear_->data;
}

template <typename T>
void s21::dequeue<T>::erase() {
  rear_ = NULL;
  while (front_ != NULL) {
    Node<T> *temp = front_;
    front_ = front_->next;
    delete temp;
  }
  size_ = 0;
}

template <typename T>
template <typename... Args>
void s21::dequeue<T>::insert_many_back_base(Args... args) {
  for (auto i : {args...}) insertRear(i);
}
}  // namespace s21

#endif  // S21_DEQUEUE_H_
