#include "finegrainedqueue.h"
int main()
{

  //демо
  FineGrainedQueue q;

  q.insertIntoMiddle(21, 1);
  q.insertIntoMiddle(33, 1);
  q.insertIntoMiddle(65, 2);
  q.insertIntoMiddle(13, 10);
  q.insertIntoMiddle(89, 1);

  q.print();
}
