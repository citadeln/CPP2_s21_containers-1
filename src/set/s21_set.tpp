#include "s21_set.h"

// std::less - функтор сравнения, true если a < b

// std::initializer_list — это спец. класс шаблона
// предназначенный для представления списка инициализации

// --- Реализация функций ---

// Конструктор с инициализатором

namespace s21 {

// Конструктор через initializer_list
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

template <typename T, typename Compare>
set<T, Compare>& set<T, Compare>::operator=(set&& s) noexcept {
  if (this != &s) {
    clear();

    // Перемещаем данные
    root_ = s.root_;
    size_ = s.size_;
    comp_ = std::move(s.comp_);

    s.root_ = nullptr;
    s.size_ = 0;
  }
  return *this;
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

// Реализация operator++
template <typename T, typename Compare>
typename set<T, Compare>::iterator& set<T, Compare>::iterator::operator++() {
  if (!node_) {
    throw std::out_of_range("Iterator out of range");
  }

  if (node_->right) {
    node_ = node_->right;
    while (node_->left) {
      node_ = node_->left;
    }
  } else {
    Node* parent = node_->parent;
    while (parent && node_ == parent->right) {
      node_ = parent;
      parent = parent->parent;
    }
    node_ = parent;
  }

  return *this;
}

template <typename T, typename Compare>
typename set<T, Compare>::size_type set<T, Compare>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(Node);
}

template <typename T, typename Compare>
void set<T, Compare>::erase(iterator pos) {
  if (pos == end()) {
    throw std::out_of_range("Iterator out of range");
  }

  Node* node = pos.node_;
  if (!node) return;

  // Удаление узла из дерева
  root_ = eraseNode(root_, node->value);
  --size_;
}

template <typename T, typename Compare>
typename set<T, Compare>::Node* set<T, Compare>::eraseNode(Node* root,
                                                           const T& value) {
  if (!root) return nullptr;

  if (comp_(value, root->value)) {
    // Удаляемый элемент меньше, ищем слева
    root->left = eraseNode(root->left, value);
  } else if (comp_(root->value, value)) {
    // Удаляемый элемент больше, ищем справа
    root->right = eraseNode(root->right, value);
  } else {
    // Найден узел для удаления
    if (!root->left && !root->right) {
      // Листовой узел
      delete root;
      return nullptr;
    } else if (!root->left) {
      // Один правый потомок
      Node* temp = root->right;
      temp->parent = root->parent;
      delete root;
      return temp;
    } else if (!root->right) {
      // Один левый потомок
      Node* temp = root->left;
      temp->parent = root->parent;
      delete root;
      return temp;
    } else {
      // Два потомка
      Node* successor =
          findMin(root->right);  // Минимальный узел в правом поддереве
      root->value = successor->value;
      root->right = eraseNode(root->right, successor->value);
    }
  }

  return root;
}

template <typename T, typename Compare>
typename set<T, Compare>::Node* set<T, Compare>::findMin(Node* node) const {
  while (node && node->left) {
    node = node->left;
  }
  return node;
}

template <typename T, typename Compare>
void s21::set<T, Compare>::swap(set& other) {
  std::swap(root_, other.root_);

  std::swap(size_, other.size_);

  std::swap(comp_, other.comp_);
}

template <typename T, typename Compare>
void s21::set<T, Compare>::merge(set& other) {
  if (this == &other) {
    return;
  }

  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }

  other.clear();
}

}  // namespace s21

/*  int main() {
   s21::set<int> set1;
  set1.insert(10);
  set1.insert(20);

  s21::set<int> set2;
  set2.insert(30);
  set2.insert(40);

  std::cout << "Before swap:" << std::endl;
  std::cout << "Set1 size: " << set1.size() << std::endl;
  std::cout << "Set2 size: " << set2.size() << std::endl;

  set1.swap(set2);

  std::cout << "After swap:" << std::endl;
  std::cout << "Set1 size: " << set1.size() << std::endl;
  std::cout << "Set2 size: " << set2.size() << std::endl;

  return 0;
}  */