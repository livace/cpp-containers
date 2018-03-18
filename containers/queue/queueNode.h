//
// Created by livace on 14.03.2018.
//

#ifndef LIST_QUEUENODE_H
#define LIST_QUEUENODE_H
#include <memory>
template <typename StoredType>
class QueueNode {
 public:
  QueueNode<StoredType>() : QueueNode<StoredType>(StoredType()) {

  }

  explicit QueueNode<StoredType>(StoredType value) {
    next_ = nullptr;
    value_ = value;
  }

  StoredType Value() const {
    return value_;
  }

  void SetNext(QueueNode<StoredType> *next) {
    next_ = std::shared_ptr<QueueNode<StoredType>>(next);
  }

  void SetNext(const StoredType & next) {
    SetNext(new QueueNode(next));
  }

  std::shared_ptr<QueueNode<StoredType>> GetNext() const {
    return next_;
  }
  ~QueueNode() {
  }
 private:
  std::shared_ptr<QueueNode> next_;
  StoredType value_;
};

#endif //LIST_QUEUENODE_H
