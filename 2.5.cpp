#include <iostream>
#include <set>
using namespace std;
struct Node
{
  int data;
	Node *next;
	Node(int i=0,Node *n=NULL):data(i),next(n){ }
};

Node *findLoopStart1(Node *head)
{
	if (!head)
	{
		return NULL;
	}
	Node *slow=head;
	Node *fast=head;
	while (fast->next && fast->next->next)
	{
		fast=fast->next->next;
		slow=slow->next;
		if (fast==slow)
		{
			break;
		}
	}
	if (!fast->next || !fast->next->next)
	{
		return NULL;
	}
	slow=head;
	while (fast!=slow)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return fast;
}

set<Node *> hash;

Node *findLoopStart2(Node *head)
{
	Node *cur=head;
	while (cur)
	{
		if (hash.find(cur)!=hash.end())
		{
			return cur;
		}
		else
		{
			hash.insert(cur);
			cur=cur->next;
		}
	}
	return NULL;
}
