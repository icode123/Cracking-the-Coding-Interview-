#include <iostream>
#include <queue>
using namespace std;

int mini2(int a,int b)
{
  return a<b ? a:b;
}

int mini3(int a,int b,int c) 
{
	return	mini2(mini2(a,b),c);
}

int get_num(int k)
{
	if (k<=0)
	{
		return 0;
	}
	int res=1;
	queue<int> q3, q5, q7;
	q3.push(3);
	q5.push(5);
	q7.push(7);
	for(int i=1;i<k;i++)
	{
		res=mini3(q3.front(),q5.front(),q7.front());
		if (res=q7.front())
		{
			q7.pop();
		}
		else
		{
			if (res==q5.front())
			{
				q5.pop();
			}
			else
			{
				if (res==q3.front())
				{
					q3.pop();
					q3.push(3*res);
				}
			}
			q5.push(5*res);
		}
		q7.push(7*res);
	}
	return res;
}
