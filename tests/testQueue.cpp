#include "gtest/gtest.h"
#include "../containers/queue/queue.h"

TEST(TEST_QUEUE, QUEUE_INT) {
  Queue<int> int_q;
  int_q.push(2);
  EXPECT_EQ(int_q.size(), 1);
  EXPECT_EQ(int_q.get(), 2);
  EXPECT_NO_THROW(int_q.pop());
  EXPECT_TRUE(int_q.empty());
  EXPECT_EQ(int_q.size(), 0);
  EXPECT_ANY_THROW(int_q.get());
  EXPECT_ANY_THROW(int_q.pop());
  int_q.push(10);
  int_q.push(322);
  EXPECT_EQ(int_q.get(), 10);
  EXPECT_EQ(int_q.size(), 2);
  EXPECT_NO_THROW(int_q.pop());
  EXPECT_NO_THROW(int_q.pop());
  EXPECT_ANY_THROW(int_q.pop());
  
  for (int i = 0; i < 100000; i++) {
    int_q.push(i);
  }
  EXPECT_FALSE(int_q.empty());
  EXPECT_EQ(int_q.size(), 100000);
}