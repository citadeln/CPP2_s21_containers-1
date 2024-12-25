#include "../s21_array.h"
#include "test.h"
using namespace s21;
TEST(t_array, constructors_1) {
  array<int> v;
  EXPECT_EQ(0, v.size());
  EXPECT_TRUE(v.empty());
}
TEST(t_array, constructors_2) {
  array<int> v(10);
  EXPECT_EQ(10, v.size());
}
TEST(t_array, constructors_3) {
  array<int> v{1, 2, 3, 4, 5};
  EXPECT_EQ(5, v.size());
  EXPECT_FALSE(v.empty());
}
TEST(t_array, constructors_4) {
  array<char> v1{1, 2, 3, 4, 5};
  array<char> v2(v1);
  EXPECT_EQ(5, v2.size());
}
TEST(t_array, constructors_5) {
  array<int> v1{1, 2, 3, 4, 5};
  array<int> v2 = v1;
  EXPECT_EQ(5, v2.size());
}
TEST(t_array, constructors_6) {
  array<int> v1{1, 2, 3, 4, 5};
  array<int> v2 = std::move(v1);
  EXPECT_EQ(5, v2.size());
  EXPECT_EQ(0, v1.size());
}
TEST(t_array, funcs_1) {
  array<int> v1{1, 2, 3, 4, 5, 6};
  ArrayIterator<int> it_bg = v1.begin();
  EXPECT_EQ(1, *it_bg);
  ArrayIterator<int> it_end = v1.end() - 1;
  EXPECT_EQ(6, *it_end);
  v1.at(0) = 0;
  EXPECT_EQ(0, v1.data()[0]);
}

TEST(t_array, funcs_2) {
  array<int> v1{1, 2, 3, 4, 5, 6};
  EXPECT_ANY_THROW(v1.at(7));
  EXPECT_ANY_THROW(v1.at(-1));
}

TEST(t_array, funcs_5) {
  array<double> v(11);
  EXPECT_EQ(v.max_size(), 11);
}

TEST(t_array, funcs_9) {
  array<int> v{1, 2, 3, 4, 5, 6};
  array<int> v2{23, 11, 22};
  v.swap(v2);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v2.size(), 6);
  EXPECT_EQ(v[0], 23);
  EXPECT_EQ(v[1], 11);
  EXPECT_EQ(v[2], 22);
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
  EXPECT_EQ(v2[2], 3);
  EXPECT_EQ(v2[3], 4);
  EXPECT_EQ(v2[4], 5);
  EXPECT_EQ(v2[5], 6);
}

TEST(t_array, t_iterator_1) {
  array<int> v{1, 2, 3, 4, 5};
  ArrayIterator<int> it = v.begin();
  ArrayIterator<int> it_end = v.end();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  it++;
  EXPECT_EQ(*it, 3);
  it_end--;
  EXPECT_EQ(*it_end, 5);
  --it_end;
  EXPECT_EQ(*it_end, 4);
  EXPECT_TRUE(it != it_end);
}

TEST(t_array, t_iterator_2) {
  array<int> v{1, 2, 3, 4, 5};
  ArrayIterator<int> it = v.begin();
  ArrayIterator<int> it_end = v.end();
  EXPECT_EQ(*it, 1);
  it += 1;
  EXPECT_EQ(*it, 2);
  it += 2;
  EXPECT_EQ(*it, 4);
  it_end -= 1;
  EXPECT_EQ(*it_end, 5);
  it_end -= 2;
  EXPECT_EQ(*it_end, 3);
  it -= 1;
  EXPECT_EQ(*it, 3);
  EXPECT_TRUE(it == it_end);
}
TEST(t_array, t_iterator_3) {
  array<int> v{1, 2, 3, 4, 5};
  ArrayIterator<int> it = v.begin();
  ArrayIterator<int> it_c(it);
  ArrayIterator<int> it_end = v.end();
  EXPECT_TRUE(it < it_end);
  EXPECT_TRUE(it <= it_end);
  EXPECT_TRUE(it <= it_c);
  EXPECT_TRUE(it >= it_c);
  EXPECT_TRUE(it_end > it);
}
TEST(t_array, t_fill) {
  array<int> a(10);
  a.fill(4);
  EXPECT_EQ(a.size(), 10);
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(a[i], 4);
  }
}