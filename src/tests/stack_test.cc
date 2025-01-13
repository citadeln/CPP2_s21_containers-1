#include "../s21_containers.h"
#include "test.h"

TEST(t_stack, constructor_stack) {
  s21::stack<int> s;
  EXPECT_EQ(s.size(), 0);
  EXPECT_TRUE(s.empty());
}
TEST(t_stack, push) {
  s21::stack<int> s;
  s.push(1);
  EXPECT_EQ(s.size(), 1);
  EXPECT_FALSE(s.empty());
  EXPECT_EQ(s.top(), 1);
}
TEST(t_stack, pop) {
  s21::stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.pop();
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(s.top(), 2);
  s.pop();
  EXPECT_EQ(s.size(), 1);
  EXPECT_EQ(s.top(), 1);
  s.pop();
  EXPECT_EQ(s.size(), 0);
  EXPECT_TRUE(s.empty());
}
TEST(t_stack, init) {
  s21::stack<int> s{32, 22, 11};
  EXPECT_EQ(s.size(), 3);
  EXPECT_EQ(s.top(), 11);
  s.pop();
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(s.top(), 22);
  s.pop();
  EXPECT_EQ(s.top(), 32);
  s.pop();
  EXPECT_TRUE(s.empty());
}

TEST(t_stack, insert_many_back) {
  s21::stack<int> s{1, 2, 3};
  s.insert_many_back(44, 55, 66);
  EXPECT_EQ(s.size(), 6);
  EXPECT_EQ(s.top(), 66);
  s.pop();
  EXPECT_EQ(s.top(), 55);
  s.pop();
  EXPECT_EQ(s.top(), 44);
  s.pop();
  EXPECT_EQ(s.top(), 3);
}