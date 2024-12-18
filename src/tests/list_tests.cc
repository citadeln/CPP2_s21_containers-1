#include <list>

#include "test.h"

TEST(test_list, test_default_constructor) {
  s21::list<int> s21;
  std::list<int> orig;

  EXPECT_EQ(s21.empty(), orig.empty());
}

TEST(test_list, test_basic_constructor) {
  s21::list<int> s21(3);
  std::list<int> orig(3);

  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_basic_constructor_error) {
  EXPECT_ANY_THROW(s21::list<int> l(-2));
}

TEST(test_list, test_initializer_list_constructor) {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  EXPECT_EQ(s21.size(), orig.size());
  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
}

TEST(test_list, test_copy_constructor) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2(s21);
  std::list<int> orig{1, 2, 3};
  std::list<int> orig_2(orig);

  EXPECT_EQ(s21_2.size(), orig_2.size());
  EXPECT_EQ(s21_2.front(), orig_2.front());
  EXPECT_EQ(s21_2.back(), orig_2.back());
}

TEST(test_list, test_move_constructor) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2(std::move(s21));
  std::list<int> orig{1, 2, 3};
  std::list<int> orig_2(std::move(orig));

  EXPECT_EQ(s21_2.size(), orig_2.size());
  EXPECT_EQ(s21_2.front(), orig_2.front());
  EXPECT_EQ(s21_2.back(), orig_2.back());
  EXPECT_EQ(s21.empty(), orig.empty());
}

TEST(test_list, test_operator_assignment) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2 = s21;
  std::list<int> orig{1, 2, 3};
  std::list<int> orig_2 = orig;

  EXPECT_EQ(s21_2.size(), orig_2.size());
  EXPECT_EQ(s21_2.front(), orig_2.front());
  EXPECT_EQ(s21_2.back(), orig_2.back());
}

TEST(test_list, test_front) {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  EXPECT_EQ(s21.front(), orig.front());
}

TEST(test_list, test_back) {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  EXPECT_EQ(s21.back(), orig.back());
}

TEST(test_list, test_iterator_begin) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.begin();
  std::list<int> orig{1, 2, 3};
  std::list<int>::iterator orig_it = orig.begin();

  EXPECT_EQ(*s21_it, *orig_it);
  --s21_it;
  --orig_it;
  EXPECT_EQ(*s21_it, *orig_it);
  ++s21_it;
  ++orig_it;
  ++s21_it;
  ++orig_it;
  EXPECT_EQ(*s21_it, *orig_it);
}

TEST(test_list, test_iterator_end) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.end();
  std::list<int> orig{1, 2, 3};
  std::list<int>::iterator orig_it = orig.end();

  EXPECT_EQ(*s21_it, *orig_it);
  s21_it++;
  orig_it++;
  EXPECT_EQ(*s21_it, *orig_it);
  s21_it--;
  orig_it--;
  s21_it--;
  orig_it--;
  EXPECT_EQ(*s21_it, *orig_it);
}

TEST(test_list, test_empty) {
  s21::list<int> s21;
  std::list<int> orig;

  EXPECT_EQ(s21.empty(), orig.empty());
}

TEST(test_list, test_size) {
  s21::list<int> s21(10);
  std::list<int> orig(10);

  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_maxsize) {
  s21::list<int> s21;
  std::list<int> orig;

  EXPECT_EQ(s21.max_size(), orig.max_size());
}

TEST(test_list, test_clear) {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  s21.clear();
  orig.clear();

  EXPECT_EQ(s21.empty(), orig.empty());
}

TEST(test_list, test_insert_end) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.end();
  std::list<int> orig{1, 2, 3};
  std::list<int>::iterator orig_it = orig.end();

  s21_it = s21.insert(s21_it, -1);
  orig_it = orig.insert(orig_it, -1);

  EXPECT_EQ(*s21_it, *orig_it);
}

TEST(test_list, test_insert_begin) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.begin();
  std::list<int> orig{1, 2, 3};
  std::list<int>::iterator orig_it = orig.begin();

  s21_it = s21.insert(s21_it, -1);
  orig_it = orig.insert(orig_it, -1);

  EXPECT_EQ(*s21_it, *orig_it);
}

TEST(test_list, test_insert) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.begin();
  std::list<int> orig{1, 2, 3};
  std::list<int>::iterator orig_it = orig.begin();

  s21_it++;
  orig_it++;

  s21_it = s21.insert(s21_it, -1);
  orig_it = orig.insert(orig_it, -1);

  EXPECT_EQ(*s21_it, *orig_it);
}

TEST(test_list, test_erase_last) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.end();
  std::list<int> orig{1, 2, 3};
  std::list<int>::iterator orig_it = orig.end();

  s21_it--;
  orig_it--;

  s21.erase(s21_it);
  orig.erase(orig_it);

  EXPECT_EQ(s21.back(), orig.back());
}

TEST(test_list, test_erase_first) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.begin();
  std::list<int> orig{1, 2, 3};
  std::list<int>::iterator orig_it = orig.begin();

  s21.erase(s21_it);
  orig.erase(orig_it);

  EXPECT_EQ(s21.front(), orig.front());
}

TEST(test_list, test_erase_middle) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.begin();
  std::list<int> orig{1, 2, 3};
  std::list<int>::iterator orig_it = orig.begin();

  s21_it++;
  orig_it++;

  s21.erase(s21_it);
  orig.erase(orig_it);

  s21_it = s21.begin();
  orig_it = orig.begin();

  s21_it++;
  orig_it++;

  EXPECT_EQ(*s21_it, *orig_it);
}

TEST(test_list, test_push_back) {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  s21.push_back(-1);
  orig.push_back(-1);

  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_pop_back) {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  s21.pop_back();
  orig.pop_back();

  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_pop_back_empty) {
  s21::list<int> s21;
  std::list<int> orig;

  s21.pop_back();

  EXPECT_EQ(s21.size(), 0);
  EXPECT_TRUE(s21.empty());
}

TEST(test_list, test_pop_back_single) {
  s21::list<int> s21(1);
  std::list<int> orig(1);

  s21.pop_back();
  orig.pop_back();

  EXPECT_EQ(s21.size(), orig.size());
  EXPECT_EQ(s21.empty(), orig.empty());
}

TEST(test_list, test_push_front) {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  s21.push_front(-1);
  orig.push_front(-1);

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_pop_front) {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  s21.pop_front();
  orig.pop_front();

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_swap) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2{4, 5, 6, 7};
  std::list<int> orig{1, 2, 3};
  std::list<int> orig_2{4, 5, 6, 7};

  s21.swap(s21_2);
  orig.swap(orig_2);

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_merge) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2{4, 5, 6, 7};
  std::list<int> orig{1, 2, 3};
  std::list<int> orig_2{4, 5, 6, 7};

  s21.merge(s21_2);
  orig.merge(orig_2);

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_merge_same) {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  s21.merge(s21);
  orig.merge(orig);

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_merge_empty) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2;
  std::list<int> orig{1, 2, 3};
  std::list<int> orig_2;

  s21.merge(s21_2);
  orig.merge(orig_2);

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_merge_empty2) {
  s21::list<int> s21;
  s21::list<int> s21_2{1, 2, 3};
  std::list<int> orig;
  std::list<int> orig_2{1, 2, 3};

  s21.merge(s21_2);
  orig.merge(orig_2);

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_splice_end) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2{4, 5, 6, 7};
  s21::list<int>::iterator s21_it = s21.end();

  std::list<int> orig{1, 2, 3};
  std::list<int> orig_2{4, 5, 6, 7};
  std::list<int>::iterator orig_it = orig.end();

  s21.splice(s21_it, s21_2);
  orig.splice(orig_it, orig_2);

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_splice_begin) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2{4, 5, 6, 7};
  s21::list<int>::iterator s21_it = s21.begin();

  std::list<int> orig{1, 2, 3};
  std::list<int> orig_2{4, 5, 6, 7};
  std::list<int>::iterator orig_it = orig.begin();

  s21.splice(s21_it, s21_2);
  orig.splice(orig_it, orig_2);

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_splice_middle) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2{4, 5, 6, 7};
  s21::list<int>::iterator s21_it = s21.begin();
  s21_it++;
  std::list<int> orig{1, 2, 3};
  std::list<int> orig_2{4, 5, 6, 7};
  std::list<int>::iterator orig_it = orig.begin();
  orig_it++;

  s21.splice(s21_it, s21_2);
  orig.splice(orig_it, orig_2);

  s21_it++;
  orig_it++;
  EXPECT_EQ(*s21_it, *orig_it);
  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_splice_zero_list) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2;
  s21::list<int>::iterator s21_it = s21.end();

  std::list<int> orig{1, 2, 3};
  std::list<int> orig_2;
  std::list<int>::iterator orig_it = orig.end();

  s21.splice(s21_it, s21_2);
  orig.splice(orig_it, orig_2);

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_reverse) {
  s21::list<int> s21{1, 2, 3};
  std::list<int> orig{1, 2, 3};

  s21.reverse();
  orig.reverse();

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_unique) {
  s21::list<int> s21{1, 1, 2, 3, 3, 4, 5, 5};
  std::list<int> orig{1, 1, 2, 3, 3, 4, 5, 5};

  s21.unique();
  orig.unique();

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_unique_small) {
  s21::list<int> s21{1};
  std::list<int> orig{1};

  s21.unique();
  orig.unique();

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_sort) {
  s21::list<int> s21{2, 5, 7, 7, 8, 9, 4, 10, 5};
  std::list<int> orig{2, 5, 7, 7, 8, 9, 4, 10, 5};

  s21.sort();
  orig.sort();

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}

TEST(test_list, test_insert_many_back) {
  s21::list<int> s21{1, 2, 3};

  s21.insert_many_back(4, 5, 6);

  EXPECT_EQ(s21.front(), 1);
  EXPECT_EQ(s21.back(), 6);
  EXPECT_EQ(s21.size(), 6);
}

TEST(test_list, test_insert_many_front) {
  s21::list<int> s21{1, 2, 3};

  s21.insert_many_front(4, 5, 6);

  EXPECT_EQ(s21.front(), 4);
  EXPECT_EQ(s21.back(), 3);
  EXPECT_EQ(s21.size(), 6);
}

TEST(test_list, test_insert_many_begin) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.begin();

  s21_it = s21.insert_many(s21_it, 4, 5, 6);

  EXPECT_EQ(*s21_it, 4);
  s21_it++;
  EXPECT_EQ(*s21_it, 5);
  EXPECT_EQ(s21.front(), 4);
  EXPECT_EQ(s21.back(), 3);
  EXPECT_EQ(s21.size(), 6);
}

TEST(test_list, test_insert_many_end) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.end();

  s21_it = s21.insert_many(s21_it, 4, 5, 6);

  EXPECT_EQ(*s21_it, 4);
  s21_it++;
  EXPECT_EQ(*s21_it, 5);
  EXPECT_EQ(s21.front(), 1);
  EXPECT_EQ(s21.back(), 6);
  EXPECT_EQ(s21.size(), 6);
}

TEST(test_list, test_insert_many_middle) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.begin();

  s21_it++;

  s21_it = s21.insert_many(s21_it, 4, 5, 6);

  EXPECT_EQ(*s21_it, 4);
  s21_it++;
  EXPECT_EQ(*s21_it, 5);
  EXPECT_EQ(s21.size(), 6);
}

TEST(test_list, test_operator_equal) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int> s21_2{1, 2, 3};
  s21::list<int> s21_3{1, 2, 4};

  EXPECT_TRUE(s21 == s21_2);
  EXPECT_FALSE(s21 == s21_3);
}

TEST(test_list, test_iterator_not_equal) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::iterator s21_it = s21.begin();

  s21::list<int> s21_2{1, 2, 3};
  s21::list<int>::iterator s21_it_2 = s21_2.begin();

  EXPECT_TRUE(s21_it != s21_it_2);
}

TEST(test_list, test_const_iterator_dereferencing) {
  s21::list<int> s21{1, 2, 3};
  s21::list<int>::const_iterator s21_it;
  s21_it = s21.end();

  std::list<int> orig{1, 2, 3};
  std::list<int>::const_iterator orig_it = orig.end();

  EXPECT_EQ(*s21_it, *orig_it);
}

TEST(test_list, test_constructor_zero) {
  s21::list<int> s21(0);

  std::list<int> orig(0);

  EXPECT_EQ(s21.empty(), orig.empty());
}

TEST(test_list, test_operator_assignment_list) {
  s21::list<int> s21;
  s21::list<int> s21_2{1, 2, 3};
  s21 = s21_2;

  std::list<int> orig;
  std::list<int> orig_2{1, 2, 3};
  orig = orig_2;

  EXPECT_EQ(s21.front(), orig.front());
  EXPECT_EQ(s21.back(), orig.back());
  EXPECT_EQ(s21.size(), orig.size());
}
