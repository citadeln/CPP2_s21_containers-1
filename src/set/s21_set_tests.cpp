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
  EXPECT_TRUE(my_set.insert(10));
  EXPECT_EQ(my_set.size(), 1);
}

TEST_F(SetInsertTest, Test2_InsertUnique) {
  s21::set<int, std::less<int>> my_set;
  EXPECT_TRUE(my_set.insert(10));
  EXPECT_TRUE(my_set.insert(20));
  EXPECT_TRUE(my_set.insert(30));
  EXPECT_EQ(my_set.size(), 3);
}

// Тест на вставку дублирующегося элемента
TEST_F(SetInsertTest, Test3_InsertDuplicate) {
  s21::set<int, std::less<int>> my_set;
  EXPECT_TRUE(my_set.insert(10));
  EXPECT_FALSE(my_set.insert(10));  // (дубликат)
  EXPECT_EQ(my_set.size(), 1);
}

TEST_F(SetInsertTest, Test4_InsertDifferentTypes) {
  s21::set<std::string, std::less<std::string>> my_set;
  EXPECT_TRUE(my_set.insert("hello"));
  EXPECT_TRUE(my_set.insert("world"));
  EXPECT_FALSE(my_set.insert("hello"));  // Дубликат
  EXPECT_EQ(my_set.size(), 2);
}

TEST_F(SetInsertTest, Test5_Contains_true) {
  s21::set<int> mySet = {1, 2, 3, 4, 5};
  EXPECT_TRUE(mySet.contains(1));
}

TEST_F(SetInsertTest, Test6_Contains_false) {
  s21::set<int> mySet = {1, 2, 3, 4, 5};
  EXPECT_FALSE(mySet.contains(6));
}

TEST_F(SetInsertTest, Test7_begin_end) {
  s21::set<int> mySet = {1};
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    EXPECT_EQ(*it, 1);
  }
}

TEST_F(SetInsertTest, Test8_begin_end) {
  s21::set<int> mySet = {1, 2, 3};
  int temp = 0;
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    temp = *it;
  }
  EXPECT_EQ(temp, 3);
}

TEST_F(SetInsertTest, Test9_clear) {
  s21::set<int> mySet = {1, 2, 3};
  mySet.clear();
  EXPECT_EQ(mySet.size(), 0);
}
