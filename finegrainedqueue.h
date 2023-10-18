#pragma once
#include <iostream>
#include <mutex>

struct Node
{
  int value;
  Node* next;
  std::mutex node_mutex;
  Node(int val) : value(val), next(nullptr) {}
};

class FineGrainedQueue
{
public:
  FineGrainedQueue();
  void insertIntoMiddle(int value, int pos);
  void print();
private:
  Node* head;
  std::mutex queue_mutex;
  int length = 0;
};
