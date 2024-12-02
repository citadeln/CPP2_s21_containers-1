#include "s21_set.h"

// --- Реализация функций ---

// Конструктор с инициализатором
namespace s21 {

template <typename T, typename Compare>
set<T, Compare>::set(std::initializer_list<T> init) : set() {
  for (const auto& value : init) {
    insert(value);
  }
}

// Деструктор
template <typename T, typename Compare>
set<T, Compare>::~set() {
  clear();
}

// Очистка дерева
template <typename T, typename Compare>
void set<T, Compare>::clear() {
  clearNode(root_);
  root_ = nullptr;
  size_ = 0;
}

template <typename T, typename Compare>
void set<T, Compare>::clearNode(Node* node) {
  if (node) {
    clearNode(node->left);
    clearNode(node->right);
    delete node;
  }
}

// Вставка элемента
template <typename T, typename Compare>
bool set<T, Compare>::insert(const T& value) {
  if (!root_) {
    root_ = new Node(value);
    ++size_;
    return true;
  }
  if (findNode(root_, value)) {
    return false;  // Элемент уже существует
  }
  root_ = insertNode(root_, value);
  ++size_;
  return true;
}

template <typename T, typename Compare>
typename set<T, Compare>::Node* set<T, Compare>::insertNode(Node* node,
                                                            const T& value) {
  if (!node) {
    return new Node(value);
  }
  if (comp_(value, node->value)) {
    Node* leftChild = insertNode(node->left, value);
    node->left = leftChild;
    leftChild->parent = node;
  } else if (comp_(node->value, value)) {
    Node* rightChild = insertNode(node->right, value);
    node->right = rightChild;
    rightChild->parent = node;
  }
  return node;
}

// Поиск элемента
template <typename T, typename Compare>
bool set<T, Compare>::contains(const T& value) const {
  return findNode(root_, value) != nullptr;
}

template <typename T, typename Compare>
typename set<T, Compare>::Node* set<T, Compare>::findNode(
    Node* node, const T& value) const {
  if (!node) {
    return nullptr;
  }
  if (value == node->value) {
    return node;
  }
  if (comp_(value, node->value)) {
    return findNode(node->left, value);
  } else {
    return findNode(node->right, value);
  }
}

// Итераторы
template <typename T, typename Compare>
typename set<T, Compare>::iterator set<T, Compare>::begin() const {
  Node* current = root_;
  while (current && current->left) {
    current = current->left;
  }
  return iterator(current);
}

template <typename T, typename Compare>
typename set<T, Compare>::iterator set<T, Compare>::end() const {
  return iterator(nullptr);
}
}  // namespace s21
// --- Пример использования ---

int main() {
  s21::set<int> mySet = {5, 2, 8, 1, 3};

  // Вставка элементов
  mySet.insert(6);
  mySet.insert(4);

  // Поиск
  std::cout << "Contains 3: " << mySet.contains(3) << "\n";
  std::cout << "Contains 10: " << mySet.contains(10) << "\n";

  // Итерация
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  return 0;
}