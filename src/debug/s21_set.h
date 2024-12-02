#include <functional>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

namespace s21 {

template <typename T, typename Compare = std::less<T>>
class set {
 private:
  struct Node {
    T value;
    Node* left;
    Node* right;
    Node* parent;

    Node(const T& val)
        : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
  };

  Node* root_;
  size_t size_;
  Compare comp_;

  // Вспомогательные функции
  Node* insertNode(Node* node, const T& value);
  void clearNode(Node* node);
  Node* findNode(Node* node, const T& value) const;

 public:
  // Конструкторы и деструктор
  set() : root_(nullptr), size_(0), comp_(Compare()) {}
  set(std::initializer_list<T> init);
  ~set();

  // Основные методы
  bool insert(const T& value);
  bool contains(const T& value) const;
  size_t size() const { return size_; }
  void clear();

  // Итератор (упрощенный для примера)
  class iterator {
   private:
    Node* current_;

   public:
    explicit iterator(Node* node) : current_(node) {}

    const T& operator*() const { return current_->value; }
    iterator& operator++();  // Реализовать переход к следующему элементу
    bool operator!=(const iterator& other) const {
      return current_ != other.current_;
    }
  };

  iterator begin() const;
  iterator end() const;
};
}