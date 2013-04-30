#include <iostream>
using namespace std;
struct Node
{
  int data;
	Node *next;
};

int n;
Node *answer;

void findNthToLast1(Node *head)
{
	if (!head)
	{
		return;
	}
	findNthToLast1(head->next);
	if (n==1)
	{
		answer=head;
	}
	n--;
}

Node *findNthToLast2(Node *head,int n)
{
	if (!head || n<1)
	{
		return NULL;
	}
	Node *p1=head;
	Node *p2=head;
	for (int i=0;i<n-1;i++)
	{
		if(!p2) return NULL;
		p2=p2->next;
	}
	while (p2->next)
	{
		p1=p1->next;
		p2=p2->next;
	}
	return p1;
}
