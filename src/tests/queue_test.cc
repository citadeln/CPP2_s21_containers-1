#include <queue>

#include "test.h"

TEST(t_queue, constructor) {
  s21::queue<int> s;
  EXPECT_EQ(s.size(), 0);
  EXPECT_TRUE(s.empty());
}

template <typename T>
static bool compare_queues(s21::queue<T>& s21_queue, std::queue<T>& std_queue) {
  if (s21_queue.size() != std_queue.size()) {
    return false;
  }

  bool result = true;

  while (!s21_queue.empty() && !std_queue.empty()) {
    if (s21_queue.front() != std_queue.front()) {
      result = false;
      break;
    }
    s21_queue.pop();
    std_queue.pop();
  }

  return result;
}

TEST(QueueTest, DefaultConstructor) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.size(), 0);
  EXPECT_TRUE(s21_queue.empty());
  EXPECT_TRUE(compare_queues(s21_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor) {
  s21::queue<int> s21_queue{1, 2, 3, 7, 9};
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  EXPECT_TRUE(compare_queues(s21_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor_2) {
  std::initializer_list<int> b;
  s21::queue<int> s21_queue{b};
  std::queue<int> std_queue{b};
  EXPECT_TRUE(compare_queues(s21_queue, std_queue));
}

TEST(QueueTest, CopyConstructor) {
  s21::queue<int> s21_queue{1, 2, 3, 7, 9};
  s21::queue<int> s21_queue_copy(s21_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(s21_queue_copy, std_queue_copy));
}

TEST(QueueTest, CopyConstructorEmpty) {
  s21::queue<int> s21_queue;
  s21::queue<int> s21_queue_copy(s21_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(s21_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructor) {
  s21::queue<int> s21_queue{1, 2, 3, 7, 20};
  s21::queue<int> s21_queue_copy(s21_queue);
  s21::queue<int> s21_queue_move(std::move(s21_queue));
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(s21_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructorEmpty) {
  s21::queue<int> s21_queue;
  s21::queue<int> s21_queue_copy(s21_queue);
  s21::queue<int> s21_queue_move(std::move(s21_queue));
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(s21_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveAssignmentOperator) {
  s21::queue<int> s21_queue{1, 2, 3, 7, 20};
  s21::queue<int> s21_queue_copy(s21_queue);
  s21::queue<int> s21_queue_move = std::move(s21_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(s21_queue_move, std_queue_move));
}

TEST(QueueTest, MoveAssignmentOperatorEmpty) {
  s21::queue<int> s21_queue;
  s21::queue<int> s21_queue_copy(s21_queue);
  s21::queue<int> s21_queue_move = std::move(s21_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(s21_queue_move, std_queue_move));
}

TEST(QueueTest, Front) {
  s21::queue<int> s21_queue{99, 2, 3, 4, 5};
  std::initializer_list<int> il = {99, 1, 3, 7, 20};
  std::queue<int> std_queue{il};
  EXPECT_EQ(s21_queue.front(), std_queue.front());
}

TEST(QueueTest, Back) {
  s21::queue<int> s21_queue{1, 2, 3, 3, 4, 99};
  std::initializer_list<int> il = {99, 1, 3, 5, 4, 7, 99};
  std::queue<int> std_queue{il};
  EXPECT_EQ(s21_queue.back(), std_queue.back());
}

TEST(QueueTest, Empty) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
  s21_queue.push(2354);
  std_queue.push(2354);
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(QueueTest, Size) {
  s21::queue<int> s21_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(QueueTest, Push) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.push(627);
  std_queue.push(627);
  s21_queue.push(2354);
  std_queue.push(2354);
  EXPECT_TRUE(compare_queues(s21_queue, std_queue));
}

TEST(QueueTest, Pop) {
  s21::queue<int> s21_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  s21_queue.pop();
  s21_queue.pop();
  std_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.front(), 3);
  EXPECT_TRUE(compare_queues(s21_queue, std_queue));
}

TEST(QueueTest, Swap) {
  s21::queue<int> s21_queue1{1, 2, 3, 4, 5};
  s21::queue<int> s21_queue2{6, 7, 8, 9, 10, 11};
  s21_queue1.swap(s21_queue2);

  std::initializer_list<int> il1 = {1, 2, 3, 4, 5};
  std::initializer_list<int> il2 = {6, 7, 8, 9, 10, 11};
  std::queue<int> std_queue1{il1};
  std::queue<int> std_queue2{il2};
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(s21_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(s21_queue2, std_queue2));
}

TEST(QueueTest, Swap_2) {
  s21::queue<int> s21_queue1{1, 2, 99, 4, 242};
  s21::queue<int> s21_queue2;
  s21_queue1.swap(s21_queue2);

  std::initializer_list<int> il = {1, 2, 99, 4, 242};
  std::queue<int> std_queue1{il};
  std::queue<int> std_queue2;
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(s21_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(s21_queue2, std_queue2));
}

TEST(Queue, Constructor_Default) {
  s21::queue<int> our_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(Queue, Constructor_List) {
  s21::queue<int> our_queue = {1, 2, 3};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(Queue, Constructor_Copy) {
  s21::queue<int> our_queue = {1, 2, 3};
  s21::queue<int> our_copy(our_queue);
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std::queue<int> std_copy(std_queue);
  EXPECT_EQ(our_copy.front(), std_copy.front());
  EXPECT_EQ(our_copy.back(), std_copy.back());
}

TEST(Queue, Constructor_Move) {
  s21::queue<int> our_queue = {1, 2, 3};
  s21::queue<int> our_move(std::move(our_queue));
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std::queue<int> std_move(std::move(std_queue));
  EXPECT_EQ(our_move.front(), std_move.front());
  EXPECT_EQ(our_move.back(), std_move.back());
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

// TEST(Queue, Operator_Move) {
//   s21::queue<int> our_queue_int = {1, 2, 3};
//   std::queue<int> std_queue_int;
//   std_queue_int.push(1);
//   std_queue_int.push(2);
//   std_queue_int.push(3);
//   s21::queue<int> our_queue_empty;
//   std::queue<int> std_queue_empty;
//   our_queue_empty = std::move(our_queue_int);
//   std_queue_empty = std::move(std_queue_int);
//   EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
//   EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
//   EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
// }

// TEST(Queue, FrontAndBack) {
//   s21::queue<int> our_queue_int = {1, 2, 3};
//   std::queue<int> std_queue_int;
//   std_queue_int.push(1);
//   std_queue_int.push(2);
//   std_queue_int.push(3);
//   s21::queue<double> our_queue_double = {1.1f, 2.1f, 3.1f};
//   std::queue<double> std_queue_double;
//   std_queue_double.push(1.1f);
//   std_queue_double.push(2.1f);
//   std_queue_double.push(3.1f);
//   s21::queue<std::string> our_queue_string = {"abc", "def", "ghf"};
//   std::queue<std::string> std_queue_string;
//   std_queue_string.push("abc");
//   std_queue_string.push("def");
//   std_queue_string.push("ghf");
//   EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
//   EXPECT_EQ(our_queue_double.front(), std_queue_double.front());
//   EXPECT_EQ(our_queue_string.front(), std_queue_string.front());
//   EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
//   EXPECT_EQ(our_queue_double.back(), std_queue_double.back());
//   EXPECT_EQ(our_queue_string.back(), std_queue_string.back());
// }

TEST(Queue, Empty) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.empty(), std_queue_empty.empty());
}

TEST(Queue, Size) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.size(), std_queue_int.size());
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.size(), std_queue_empty.size());
}

TEST(Queue, Push) {
  s21::queue<int> our_queue_int;
  our_queue_int.push(1);
  our_queue_int.push(2);
  our_queue_int.push(3);
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
}

TEST(Queue, Pop) {
  s21::queue<int> our_queue_int;
  our_queue_int.push(1);
  our_queue_int.push(2);
  our_queue_int.push(3);
  our_queue_int.pop();
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  std_queue_int.pop();
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
  our_queue_int.pop();
  our_queue_int.pop();
  std_queue_int.pop();
  std_queue_int.pop();
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(Queue, Swap) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty.swap(our_queue_int);
  std_queue_empty.swap(std_queue_int);
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(Queue, InsertManyBack_01) {
  s21::queue<int> our_queue_int;
  our_queue_int.insert_many_back(1, 2, 3);
  EXPECT_EQ(our_queue_int.front(), 1);
  EXPECT_EQ(our_queue_int.back(), 3);
}
