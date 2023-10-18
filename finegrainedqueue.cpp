#include "finegrainedqueue.h"

FineGrainedQueue::FineGrainedQueue() : head(nullptr){}// Устанавливаем длину списка в 0  , tail(nullptr), length(0)

void FineGrainedQueue::insertIntoMiddle(int value, int pos)
{
  if (pos <= 0)// Вставка в начало не рассматривается
    {
      return;
    }
  Node* newNode = new Node(value);// новый узел списка

  Node* tail;
  std::unique_lock<std::mutex> queuelock(queue_mutex);
  if (!head) // Если список пустой, добавляем первый элемент
    {
      head = newNode;
      tail = newNode;
      length = 1;
      return;
    }
  if (pos >= length) // Если pos больше или равно длине списка, добавляем элемент в конец списка
    {
      std::lock_guard<std::mutex> tailLock(tail->node_mutex);
      tail->next = newNode;
      tail = newNode;
      length++;
    }
  else // Если pos меньше длины списка, добавляем элемент в середину списка
    {
      Node* current = head;
      int currentIndex = 0;
      while (current->next != nullptr && currentIndex < pos - 1)
      {
        current = current->next;
        currentIndex++;
      }
      std::lock_guard<std::mutex> nodeLock(current->node_mutex);
      newNode->next = current->next;
      current->next = newNode;
      length++;
    }
}


void FineGrainedQueue::print()
    {
        Node* current = head;
        while (current)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
