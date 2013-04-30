//边界条件的考虑
//1.头结点;2.中间结点;3.尾结点;4.为空.
#include <iostream>
using namespace std;
struct Node
{
  int data;
	Node *next;
};

bool remove(Node *n)
{
//尾结点需要再考虑一下
	if (!n || !n->next)
	{
		return false;
	}
	Node *next=n->next;
	n->data=next->data;
	n->next=next->next;
	delete next;
	return true;
}
