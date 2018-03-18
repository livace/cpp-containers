//
// Created by livace on 14.03.2018.
//

#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H
#include <memory>
#include "../container.h"
#include "queueNode.h"

template <typename StoredType>
class Queue : public Container<StoredType>{
 public:
  Queue () {
    size_ = 0;
    first_ = nullptr;
    last_ = nullptr;
  }

  StoredType pop() override {
    if (empty()) {
      throw std::runtime_error("Trying to pop from empty queue");
    }
    --size_;
    StoredType ans = first_->Value();
    if (empty()) {
      first_ = nullptr;
      last_ = nullptr;
    } else {
      first_ = first_->GetNext();
    }
    return ans;
  }

  void push(const StoredType & value) override {
    ++size_;
    if (size_ == 1) {
      first_ = std::make_shared<QueueNode<StoredType>>(value);
      last_ = first_;
      return;
    }
    last_->SetNext(new QueueNode<StoredType>(value));
    last_ = last_->GetNext();
  }
  int size() const override {
    return size_;
  }
  bool empty() const override {
    return size_ == 0;
  }
  StoredType get() const override {
    if (empty()) {
      throw std::runtime_error("Trying to get element from empty queue");
    }
    return first_->Value();
  }
  ~Queue () override {
    while (!empty()) {
      pop();
    }
  }
 private:
  std::shared_ptr<QueueNode<StoredType>> first_;
  std::shared_ptr<QueueNode<StoredType>> last_;
  int size_;
};

#endif //LIST_QUEUE_H
