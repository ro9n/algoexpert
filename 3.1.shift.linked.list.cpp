using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = 0;
  }
};

LinkedList* shiftLinkedList(LinkedList *head, int k) {
  // Write your code here.
	LinkedList *h = head, *p = 0; int n = 0;

  while (h) ++n, p = h, h = h->next;
  p->next = head;

  k %= n; if (k > 0) k = n - k; else if (k < 0) k = -k;
  h = head; while (k--) p = h, h = h->next;
  p->next = 0;

  return h;
}

