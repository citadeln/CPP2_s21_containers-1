#include "test.h"
#include "../s21_vector.h"
using namespace s21;
TEST(t_vector, constructors_1) {
    vector<int> v;EXPECT_EQ(0, v.size());
    EXPECT_TRUE(v.empty());
}
TEST(t_vector, constructors_2) {
    vector<int> v (10);EXPECT_EQ(0, v.size());
    EXPECT_EQ(10, v.capacity());
    EXPECT_TRUE(v.empty());
}
TEST(t_vector, constructors_3) {
    vector<int> v {1,2,3,4,5};EXPECT_EQ(5, v.size());
    EXPECT_FALSE(v.empty());
}
TEST(t_vector, constructors_4) {
    vector<char> v1 {1,2,3,4,5};
    vector<char> v2 (v1);
    EXPECT_EQ(5, v2.size());
}
TEST(t_vector, constructors_5) {
    vector<int> v1 {1,2,3,4,5};
    vector<int> v2 = v1;
    EXPECT_EQ(5, v2.size());
}
TEST(t_vector, constructors_6) {
    vector<int> v1 {1,2,3,4,5};
    vector<int> v2 = std::move(v1);
    EXPECT_EQ(5, v2.size());
    EXPECT_EQ(0, v1.size());
}
TEST(t_vector, funcs_1) {
    vector<int> v1 {1,2,3,4,5,6};
    VectorIterator<int> it_bg = v1.begin();
    EXPECT_EQ(1, *it_bg);
    VectorIterator<int> it_end = v1.end()-1;
    EXPECT_EQ(6, *it_end);
    v1.at(0) = 0;
    EXPECT_EQ(0, v1.data()[0]);
}

TEST(t_vector, funcs_2) {
    vector<int> v1 {1,2,3,4,5,6};
    EXPECT_ANY_THROW(v1.at(7));
    EXPECT_ANY_THROW(v1.at(-1));
}
TEST(t_vector, funcs_3) {
    vector<int> v (10);
    EXPECT_EQ(v.capacity(), 10);
    v.push_back(3);
    v.push_back(4);
    EXPECT_EQ(4, v.at(1));
    EXPECT_EQ(v.capacity(), 10);
    v.shrink_to_fit();
    EXPECT_EQ(v.capacity(), 2);

}
TEST(t_vector, funcs_4) {
    vector<int> v {1,2,3,4,5,6};
    v.pop_back();
    EXPECT_EQ(5, v.size());
    EXPECT_ANY_THROW(v.at(5));
}

TEST(t_vector, funcs_5) {
    vector<double> v (11);
    EXPECT_EQ(v.max_size(), 11);
}
TEST(t_vector, funcs_6) {
    vector<int> v {1,2,3,4,5,6};
    v.clear();
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
    EXPECT_EQ(v.data(), nullptr);
}
TEST(t_vector, funcs_7) {
    vector<int> v {1,2,3,4,5,6};
    v.shrink_to_fit();
    EXPECT_EQ(v.capacity(), 6);
    EXPECT_EQ(v.size(), 6);
    v.insert(v.begin()+2,43);
    EXPECT_EQ(v.size(), 7);
    EXPECT_EQ(v.capacity(), 12);
    EXPECT_EQ(v.at(2), 43);

}
TEST(t_vector, funcs_7_1) {
    vector<int> v {1,2,3,4,5,6};
    v.insert(v.begin()+2,43);

    EXPECT_EQ(v.at(2), 43);

}
TEST(t_vector, funcs_8) {
    vector<int> v {1,2,3,4,5,6};
    v.erase(v.begin()+2);
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 6);
    EXPECT_EQ(v.at(2), 4);
    EXPECT_ANY_THROW(v.at(5));
    EXPECT_EQ(v[1], 2);
}

TEST(t_vector, funcs_9) {
    vector<int> v {1,2,3,4,5,6};
    vector<int> v2 {23, 11, 22};
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

TEST(t_vector, t_iterator_1) {
    vector<int> v  {1,2,3,4,5};
    VectorIterator<int> it = v.begin();
    VectorIterator<int> it_end = v.end();
    EXPECT_EQ(*it, 1);
    ++it; EXPECT_EQ(*it, 2);
    it++; EXPECT_EQ(*it, 3);
    it_end--; EXPECT_EQ(*it_end, 5);
    --it_end; EXPECT_EQ(*it_end, 4);
    EXPECT_TRUE(it != it_end);

}

TEST(t_vector, t_iterator_2) {
    vector<int> v  {1,2,3,4,5};
    VectorIterator<int> it = v.begin();
    VectorIterator<int> it_end = v.end();
    EXPECT_EQ(*it, 1);
    it+=1; EXPECT_EQ(*it, 2);
    it+=2; EXPECT_EQ(*it, 4);
    it_end-=1; EXPECT_EQ(*it_end, 5);
    it_end-=2; EXPECT_EQ(*it_end, 3);
    it-=1; EXPECT_EQ(*it, 3);
    EXPECT_TRUE(it == it_end);
    
}
TEST(t_vector, t_iterator_3) {
    vector<int> v  {1,2,3,4,5};
    VectorIterator<int> it = v.begin();
    VectorIterator<int> it_c (it);
    VectorIterator<int> it_end = v.end();
    EXPECT_TRUE(it < it_end);
    EXPECT_TRUE(it <= it_end);
    EXPECT_TRUE(it <= it_c);
    EXPECT_TRUE(it >= it_c);
    EXPECT_TRUE(it_end > it);

}
TEST(t_vector, t_reverse) {
    vector<int> v  {1,2,3,4,5};
    v.reverse(5);
    EXPECT_EQ(v[0], 5);
    EXPECT_EQ(v[1], 4);
    EXPECT_EQ(v[2], 3);
    EXPECT_EQ(v[3], 2);
    EXPECT_EQ(v.front(),5);
    EXPECT_EQ(v.back(),1);
    v.reverse(4);
    EXPECT_EQ(v.front(),2);
    EXPECT_EQ(v.back(),1);
}
TEST(t_vector, t_assign) {
    vector<int> v  {1,2,3,4,5,234,234,234};
    EXPECT_EQ(v.at(6), 234);
}