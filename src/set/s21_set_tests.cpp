#include <gtest/gtest.h>

#include "s21_set.h"  // Предполагается, что ваш класс находится в этом файле

class SetInsertTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Инициализация перед каждым тестом, если требуется
  }

  void TearDown() override {
    // Очистка после каждого теста, если требуется
  }
};

TEST_F(SetInsertTest, Test1_InsertIntoEmptySet) {
  s21::set<int, std::less<int>> my_set;
  EXPECT_TRUE(my_set.insert(10));  // Успешная вставка
  EXPECT_EQ(my_set.size(), 1);     // Размер должен быть 1
}

TEST_F(SetInsertTest, Test2_InsertUniqueElements) {
  s21::set<int, std::less<int>> my_set;
  EXPECT_TRUE(my_set.insert(10));  // Успешная вставка
  EXPECT_TRUE(my_set.insert(20));  // Успешная вставка
  EXPECT_TRUE(my_set.insert(30));  // Успешная вставка
  EXPECT_EQ(my_set.size(), 3);     // Размер должен быть 3
}

// Тест на вставку дублирующегося элемента
TEST_F(SetInsertTest, Test3_InsertDuplicateElement) {
  s21::set<int, std::less<int>> my_set;
  EXPECT_TRUE(my_set.insert(10));  // Успешная вставка
  EXPECT_FALSE(my_set.insert(10));  // Неуспешная вставка (дубликат)
  EXPECT_EQ(my_set.size(), 1);  // Размер остается 1
}

/* // Тест с пользовательским компаратором
struct CustomComparator {
  bool operator()(const int& a, const int& b) const {
    return a > b;  // Обратный порядок
  }
};

TEST(SetInsertTest, InsertWithCustomComparator) {
  s21::set<int, CustomComparator> my_set;
  EXPECT_TRUE(my_set.insert(10));  // Успешная вставка
  EXPECT_TRUE(my_set.insert(5));   // Успешная вставка
  EXPECT_TRUE(my_set.insert(20));  // Успешная вставка
  EXPECT_FALSE(my_set.insert(10));  // Неуспешная вставка (дубликат)
  EXPECT_EQ(my_set.size(), 3);  // Размер должен быть 3
}

// Тест на корректную вставку с разными типами данных
TEST(SetInsertTest, InsertDifferentTypes) {
  s21::set<std::string, std::less<std::string>> my_set;
  EXPECT_TRUE(my_set.insert("hello"));
  EXPECT_TRUE(my_set.insert("world"));
  EXPECT_FALSE(my_set.insert("hello"));  // Дубликат
  EXPECT_EQ(my_set.size(), 2);
}
 */