//
// Created by livace on 14.03.2018.
//

#include <cassert>
#include "testQueue.h"
#include "queue.h"
#include <string>
#include <iostream>
void testQueue::runTests() {
  Queue<int> int_q;
  int_q.push(2);
  assert(int_q.size() == 1);
  assert(int_q.get() == 2);
  int_q.pop();
  assert(int_q.empty());
  assert(int_q.size() == 0);
  Queue<std::string> string_q;
  assert(string_q.empty());
  assert(string_q.size() == 0);
  string_q.push("abc");
  string_q.push("def");
  string_q.push("efg");
  assert(string_q.size() == 3);
  assert(string_q.get() == "abc");
  assert(string_q.pop() == "abc");
  assert(string_q.size() == 2);
  assert(string_q.pop() == "def");
  assert(string_q.pop() == "efg");
  assert(string_q.empty());

  try {
    string_q.get();
  } catch (const std::runtime_error & e) {
      std::cerr << "Caught: " << e.what() << '\n';
  }

  try {
    string_q.pop();
  } catch (const std::runtime_error & e) {
    std::cerr << "Caught: " << e.what() << '\n';
  }

  std::cerr << "Tests passed!";
}
