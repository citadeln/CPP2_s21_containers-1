#include "../s21_containers.h"
#include "test.h"
TEST(t_dequeue, constructor_1) {
  s21::dequeue<int> d;
  EXPECT_EQ(d.size(), 0);
  EXPECT_EQ(d.isEmpty(), true);
}
TEST(t_dequeue, init) {
  s21::dequeue<int> d{32, 23, 11, 22};
  EXPECT_EQ(d.size(), 4);
  EXPECT_EQ(d.isEmpty(), false);
  EXPECT_EQ(d.getFront(), 32);
  EXPECT_EQ(d.getRear(), 22);
}
TEST(t_dequeue, insertRear) {
  s21::dequeue<int> d;
  d.insertRear(32);
  d.insertRear(23);
  d.insertRear(11);
  d.insertRear(22);
  EXPECT_EQ(d.size(), 4);
  EXPECT_EQ(d.isEmpty(), false);
  EXPECT_EQ(d.getFront(), 32);
  EXPECT_EQ(d.getRear(), 22);
}
TEST(t_dequeue, insertFront) {
  s21::dequeue<int> d;
  d.insertFront(32);
  d.insertFront(23);
  d.insertFront(11);
  d.insertFront(22);
  EXPECT_EQ(d.size(), 4);
  EXPECT_EQ(d.isEmpty(), false);
  EXPECT_EQ(d.getFront(), 22);
  EXPECT_EQ(d.getRear(), 32);
}
TEST(t_dequeue, deleteFront) {
  s21::dequeue<int> d{32, 23, 11, 22};
  d.deleteFront();
  EXPECT_EQ(d.size(), 3);
  EXPECT_EQ(d.isEmpty(), false);
  EXPECT_EQ(d.getFront(), 23);
}
TEST(t_dequeue, deleteRear) {
  s21::dequeue<int> d{32, 23, 11, 22};
  d.deleteRear();
  EXPECT_EQ(d.size(), 3);
  EXPECT_EQ(d.isEmpty(), false);
  EXPECT_EQ(d.getFront(), 32);
  EXPECT_EQ(d.getRear(), 11);
}
TEST(t_dequeue, erase) {
  s21::dequeue<int> d{32, 23, 11, 22};
  d.erase();
  EXPECT_EQ(d.size(), 0);
  EXPECT_EQ(d.isEmpty(), true);
}
TEST(t_dequeue, copy) {
  s21::dequeue<int> d{32, 23, 11, 22};
  s21::dequeue<int> dd = d;
  EXPECT_EQ(d.size(), dd.size());
  EXPECT_EQ(d.isEmpty(), dd.isEmpty());
  EXPECT_EQ(d.getFront(), dd.getFront());
  EXPECT_EQ(d.getRear(), dd.getRear());
}
TEST(t_dequeue, ne) {
  s21::dequeue<int> d{32, 23, 11, 22};
  s21::dequeue<int> dd = d;
  EXPECT_FALSE(d != dd);
}
TEST(t_dequeue, ne_1) {
  s21::dequeue<int> d{32, 23, 11, 22};
  s21::dequeue<int> dd = d;
  dd.deleteFront();
  EXPECT_TRUE(d != dd);
}