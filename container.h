//
// Created by livace on 14.03.2018.
//

#ifndef LIST_CONTAINER_H
#define LIST_CONTAINER_H
template <typename StoredType>
class Container {
 public:
  Container<StoredType> () {

  }
  virtual StoredType pop()= 0;
  virtual void push(const StoredType & value)= 0;
  virtual int size()= 0;
  virtual bool empty()= 0;
  virtual StoredType get()= 0;
  virtual ~Container<StoredType>()= default;
};

#endif //LIST_CONTAINER_H
