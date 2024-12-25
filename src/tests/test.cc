#include "test.h"

#include <gtest/gtest.h>

#include "../s21_set.h"

class SetInsertTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Инициализация перед каждым тестом, если требуется
  }

  void TearDown() override {
    // Очистка после каждого теста, если требуется
  }
};

TEST(SetInsertTest, Test1_InsertIntoEmptySet) {
  s21::set<int, std::less<int>> my_set;
  EXPECT_TRUE(my_set.insert(10));
  EXPECT_EQ(my_set.size(), 1);
}

TEST(SetInsertTest, Test2_InsertUnique) {
  s21::set<int, std::less<int>> my_set;
  EXPECT_TRUE(my_set.insert(10));
  EXPECT_TRUE(my_set.insert(20));
  EXPECT_TRUE(my_set.insert(30));
  EXPECT_EQ(my_set.size(), 3);
}

// Тест на вставку дублирующегося элемента
TEST(SetInsertTest, Test3_InsertDuplicate) {
  s21::set<int, std::less<int>> my_set;
  EXPECT_TRUE(my_set.insert(10));
  EXPECT_FALSE(my_set.insert(10));  // (дубликат)
  EXPECT_EQ(my_set.size(), 1);
}

TEST(SetInsertTest, Test4_InsertDifferentTypes) {
  s21::set<std::string, std::less<std::string>> my_set;
  EXPECT_TRUE(my_set.insert("hello"));
  EXPECT_TRUE(my_set.insert("world"));
  EXPECT_FALSE(my_set.insert("hello"));  // Дубликат
  EXPECT_EQ(my_set.size(), 2);
}

TEST(SetInsertTest, Test5_Contains_true) {
  s21::set<int> mySet = {1, 2, 3, 4, 5};
  EXPECT_TRUE(mySet.contains(1));
}

TEST(SetInsertTest, Test6_Contains_false) {
  s21::set<int> mySet = {1, 2, 3, 4, 5};
  EXPECT_FALSE(mySet.contains(6));
}

TEST(SetInsertTest, Test7_begin_end) {
  s21::set<int> mySet = {1};
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    EXPECT_EQ(*it, 1);
  }
}

TEST(SetInsertTest, Test8_begin_end) {
  s21::set<int> mySet = {1, 2, 3};
  int temp = 0;
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    temp = *it;
  }
  EXPECT_EQ(temp, 3);
}

TEST(SetInsertTest, Test9_clear) {
  s21::set<int> mySet = {1, 2, 3};
  mySet.clear();
  EXPECT_EQ(mySet.size(), 0);
}

TEST(SetInsertTest, Test10_empty) {
  s21::set<int> mySet = {1, 2, 3};
  EXPECT_FALSE(mySet.empty());
}

TEST(SetInsertTest, Test11_empty) {
  s21::set<int> mySet = {1, 2, 3};
  mySet.clear();
  EXPECT_TRUE(mySet.empty());
}

TEST(SetInsertTest, Test12_PositiveMaxSize) {
  s21::set<int> my_set;
  EXPECT_GT(my_set.max_size(), 0);
}

TEST(SetInsertTest, Test13_MaxSizeGreaterThanSize) {
  s21::set<int> my_set = {1, 2, 3, 4, 5};
  EXPECT_GT(my_set.max_size(), my_set.size());
}

TEST(SetInsertTest, Test14_EraseExistingElement) {
  s21::set<int> s;
  s.insert(10);
  s.insert(20);
  s.insert(30);

  auto it = s.begin();

  s.erase(it);

  EXPECT_EQ(s.size(), 2);
}

TEST(SetInsertTest, Test15_swap) {
  s21::set<int> s1;
  s1.insert(10);
  s1.insert(20);
  s1.insert(30);

  s21::set<int> s2;
  s2.insert(1);
  s2.insert(2);

  EXPECT_EQ(s1.size(), 3);
  EXPECT_EQ(s2.size(), 2);

  s1.swap(s2);

  EXPECT_EQ(s1.size(), 2);
  EXPECT_EQ(s2.size(), 3);

  auto it = s1.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(SetInsertTest, Test16_merge) {
  s21::set<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(3);

  s21::set<int> s2;
  s2.insert(4);
  s2.insert(5);
  EXPECT_EQ(s1.size(), 3);

  s1.merge(s2);
  int temp = 1;

  for (auto it = s1.begin(); it != s1.end(); ++it, temp++) {
    EXPECT_EQ(*it, temp);
  }
  EXPECT_EQ(s1.size(), 5);
}
