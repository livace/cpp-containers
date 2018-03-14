//
// Created by livace on 14.03.2018.
//

#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H
#include <memory>
#include "container.h"
#include "QueueNode.h"

template <typename StoredType>
class Queue : public Container<StoredType>{
 public:
  Queue () {
    size_ = 0;
    first_ = std::shared_ptr<QueueNode<StoredType>>(nullptr);
    last_ = std::shared_ptr<QueueNode<StoredType>>(nullptr);
  }

  StoredType pop() override {
    --size_;
    StoredType ans = first_->Value();
    first_ = first_->GetNext();
    return ans;
  }

  void push(const StoredType & value) override {
    ++size_;
    if (!last_) {
      first_ = std::shared_ptr<QueueNode<StoredType>>(new QueueNode<StoredType>(value));
      last_ = first_;
      return;
    }
    last_->SetNext(new QueueNode<StoredType>(value));
    last_ = last_->GetNext();
  }
  int size() override {
    return size_;
  }
  bool empty() override {
    return size_ == 0;
  }
  StoredType get() override {
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
