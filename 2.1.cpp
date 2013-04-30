#include <iostream>
#include <set>
using namespace std;
struct Node
{
  int data;
	Node *next;
};

set<int> hs;

void removedulicate1(Node *head)
{
	if (!head)
	{
		return;
	}
	Node *p=head,*q=head->next;
	hs.insert(p->data);
	while (q)
	{
		if (hs.find(q->data)!=hs.end())
		{
			Node *remove=q;
			p->next=q->next；
			q=q->next;
			delete remove;
		}
		else
		{
			hs.insert(q->data);
			p=q;
			q=q->next;
		}
	}
}

void removedulicate2(Node *head)
{
	if (!head)
	{
		return;
	}
	Node *p,*q,*c=head;
	while (c)
	{
		p=c;
		q=c->next;
		int d=c->data;
		while (q)
		{
			if (q->data==d)
			{
				Node *remove=q;
				p->next=q->next；
				q=q->next;
				delete remove;
			}
			else
			{
				p=q;
				q=q->next;
			}
		}
		c=c->next;
	}
}
