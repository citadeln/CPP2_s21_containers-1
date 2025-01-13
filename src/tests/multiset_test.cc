#include "../s21_containers.h"
#include "test.h"

class multisetInsertTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Инициализация перед каждым тестом, если требуется
  }

  void TearDown() override {
    // Очистка после каждого теста, если требуется
  }
};
TEST(MultiSet_t, t1) {
  s21::multiset<int> mymultiset = {1, 2, 3, 4, 5};
  EXPECT_EQ(mymultiset.size(), 5);
}

TEST(multisetInsertTest, Test1_InsertIntoEmptymultiset) {
  s21::multiset<int, std::less<int>> my_multiset;
  EXPECT_TRUE(my_multiset.insert(10));
  EXPECT_EQ(my_multiset.size(), 1);
}

TEST(multisetInsertTest, Test2_InsertUnique) {
  s21::multiset<int, std::less<int>> my_multiset;
  EXPECT_TRUE(my_multiset.insert(10));
  EXPECT_TRUE(my_multiset.insert(20));
  EXPECT_TRUE(my_multiset.insert(30));
  EXPECT_EQ(my_multiset.size(), 3);
}

// Тест на вставку дублирующегося элемента
TEST(multisetInsertTest, Test3_InsertDuplicate) {
  s21::multiset<int, std::less<int>> my_multiset;
  EXPECT_TRUE(my_multiset.insert(10));
  EXPECT_TRUE(my_multiset.insert(10));  // (дубликат)
  EXPECT_EQ(my_multiset.size(), 2);
}

TEST(multisetInsertTest, Test4_InsertDifferentTypes) {
  s21::multiset<std::string, std::less<std::string>> my_multiset;
  EXPECT_TRUE(my_multiset.insert("hello"));
  EXPECT_TRUE(my_multiset.insert("world"));
  EXPECT_TRUE(my_multiset.insert("hello"));  // Дубликат
  EXPECT_EQ(my_multiset.size(), 3);
}

TEST(multisetInsertTest, Test5_Contains_true) {
  s21::multiset<int> mymultiset = {1, 2, 3, 4, 5};
  EXPECT_TRUE(mymultiset.contains(1));
}

TEST(multisetInsertTest, Test6_Contains_false) {
  s21::multiset<int> mymultiset = {1, 2, 3, 4, 5};
  EXPECT_FALSE(mymultiset.contains(6));
}

TEST(multisetInsertTest, Test7_begin_end) {
  s21::multiset<int> mymultiset = {1};
  for (auto it = mymultiset.begin(); it != mymultiset.end(); ++it) {
    EXPECT_EQ(*it, 1);
  }
}

TEST(multisetInsertTest, Test8_begin_end) {
  s21::multiset<int> mymultiset = {1, 2, 3};
  int temp = 0;
  for (auto it = mymultiset.begin(); it != mymultiset.end(); ++it) {
    temp = *it;
  }
  EXPECT_EQ(temp, 3);
}

TEST(multisetInsertTest, Test9_clear) {
  s21::multiset<int> mymultiset = {1, 2, 3};
  mymultiset.clear();
  EXPECT_EQ(mymultiset.size(), 0);
}

TEST(multisetInsertTest, Test10_empty) {
  s21::multiset<int> mymultiset = {1, 2, 3};
  EXPECT_FALSE(mymultiset.empty());
}

TEST(multisetInsertTest, Test11_empty) {
  s21::multiset<int> mymultiset = {1, 2, 3};
  mymultiset.clear();
  EXPECT_TRUE(mymultiset.empty());
}

TEST(multisetInsertTest, Test12_PositiveMaxSize) {
  s21::multiset<int> my_multiset;
  EXPECT_GT(my_multiset.max_size(), 0);
}

TEST(multisetInsertTest, Test13_MaxSizeGreaterThanSize) {
  s21::multiset<int> my_multiset = {1, 2, 3, 4, 5};
  EXPECT_GT(my_multiset.max_size(), my_multiset.size());
}

TEST(multisetInsertTest, Test14_EraseExistingElement) {
  s21::multiset<int> s;
  s.insert(10);
  s.insert(20);
  s.insert(30);

  auto it = s.begin();

  s.erase(it);

  EXPECT_EQ(s.size(), 2);
}

TEST(multisetInsertTest, Test15_swap) {
  s21::multiset<int> s1;
  s1.insert(10);
  s1.insert(20);
  s1.insert(30);

  s21::multiset<int> s2;
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

TEST(multisetInsertTest, Test16_merge) {
  s21::multiset<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(3);

  s21::multiset<int> s2;
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

TEST(multisetInsertTest, Test17_count) {
  s21::multiset<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(3);
  EXPECT_EQ(s1.count(2), 1);
}
TEST(multisetInsertTest, Test18_count) {
  s21::multiset<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(2);
  EXPECT_EQ(s1.size(), 3);
  EXPECT_EQ(s1.count(2), 2);
}
TEST(multisetInsertTest, Test18_1_count) {
  s21::multiset<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(2);
  s1.insert(3);
  EXPECT_EQ(s1.size(), 4);
  EXPECT_EQ(s1.count(2), 2);
}
TEST(multisetInsertTest, Test18_2_count) {
  s21::multiset<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(2);
  s1.insert(2);
  s1.insert(3);
  EXPECT_EQ(s1.size(), 5);
  EXPECT_EQ(s1.count(2), 3);
}
TEST(multisetInsertTest, Test19_find) {
  s21::multiset<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(2);
  EXPECT_EQ(*s1.find(2), 2);
}
TEST(multisetInsertTest, Test20_find) {
  s21::multiset<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(2);
  EXPECT_ANY_THROW(s1.find(10));
}
TEST(multisetInsertTest, Test21_lower_bound) {
  s21::multiset<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(2);
  EXPECT_EQ(*s1.lower_bound(2), 1);
}
TEST(multisetInsertTest, Test22_lower_bound) {
  s21::multiset<int> s1;
  s1.insert(20);
  s1.insert(2);
  s1.insert(2);
  EXPECT_EQ(*s1.lower_bound(10), 2);
}
TEST(multisetInsertTest, Test23_upper_bound) {
  s21::multiset<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(2);
  EXPECT_EQ(*s1.upper_bound(2), 2);
}
TEST(multisetInsertTest, Test24_upper_bound) {
  s21::multiset<int> s1;
  s1.insert(20);
  s1.insert(2);
  s1.insert(2);
  EXPECT_EQ(*s1.upper_bound(10), 20);
}
TEST(multisetInsertTest, Test26_insert_many) {
  s21::multiset<int> s1{1, 2, 3, 3};
  EXPECT_EQ(s1.size(), 4);
  s21::vector<std::pair<s21::multiset<int>::iterator, bool>> v =
      s1.insert_many(3, 22, 33);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(s1.size(), 7);
  EXPECT_EQ(v[0].second, true);
  s21::multiset<int>::iterator it = v[0].first;
  EXPECT_EQ(*it, 3);
  EXPECT_EQ(v[0].second, true);
  it = v[1].first;
  EXPECT_EQ(*it, 22);
  EXPECT_EQ(v[0].second, true);
  it = v[2].first;
  EXPECT_EQ(*it, 33);
}
TEST(multisetInsertTest, Test27_insert_many) {
  s21::multiset<int> s1{11, 2, 3, 3};
  EXPECT_EQ(s1.size(), 4);
  s21::vector<std::pair<s21::multiset<int>::iterator, bool>> v =
      s1.insert_many(3);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(s1.size(), 5);
  EXPECT_EQ(v[0].second, true);
  s21::multiset<int>::iterator it = v[0].first;
  EXPECT_EQ(*it, 3);
}
TEST(multisetInsertTest, Test28_contains) {
  s21::multiset<int> s1{11, 2, 3, 3};
  EXPECT_EQ(s1.contains(11), true);
  EXPECT_EQ(s1.contains(22), false);
  EXPECT_EQ(s1.contains(2), true);
  EXPECT_EQ(s1.contains(3), true);
  s1.insert(21);
  EXPECT_EQ(s1.contains(11), true);
  EXPECT_EQ(s1.contains(22), false);
  EXPECT_EQ(s1.contains(2), true);
  EXPECT_EQ(s1.contains(3), true);
  EXPECT_EQ(s1.contains(21), true);
  s1.insert(12);
  s1.insert(9);
  EXPECT_EQ(s1.contains(11), true);
  EXPECT_EQ(s1.contains(22), false);
  EXPECT_EQ(s1.contains(2), true);
  EXPECT_EQ(s1.contains(3), true);
  EXPECT_EQ(s1.contains(21), true);
  EXPECT_EQ(s1.contains(12), true);
  EXPECT_EQ(s1.contains(9), true);
}