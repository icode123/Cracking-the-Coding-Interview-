//1.链表为空;2.有进位;3.链表长度不一样.
#include <iostream>
using namespace std;
struct Node
{
  int data;
	Node *next;
	Node(int i=0,Node *n=NULL):data(i),next(n){ }
};

Node *addList(Node *head1,Node *head2,int carry)
{
	if (!head1 && !head2)
	{
		return NULL;
	}
	Node *result=new Node();
	int value=carry;
	if (head1)
	{
		value+=head1->data;
	}
	if (head2)
	{
		value+=head2->data;
	}
	result->data=value%10;
	Node *more=addList(head1->next,head2->next,value/10);
	result->next=more;
	return result;
}
