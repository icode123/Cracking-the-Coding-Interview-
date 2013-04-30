//结点中包含指向父亲结点的指针
void print1(Node *head,int level)
{
  vector<int> v;
	for (int i=0;i<level;i++)
	{
		v.push_back(head->data);
		head=head->parent;
	}
	while (!v.empty())
	{
		cout<<v.back()<<" ";
		v.pop_back();
	}
	cout<<endl;
}

void find_sum1(Node *head,int sum)
{
	if (!head)
	{
		return;
	}
	Node *no=head;
	int tmp=0;
	for (int i=1;no;i++)
	{
		tmp+=no->data;
		if (tmp==sum)
		{
			print1(head,i);
		}
	}
	find_sum1(head->left,sum);
	find_sum1(head->right,sum);
}

//结点中不包含指向父亲结点的指针
void print2(vector<int> v,int level)
{
  for (int i=level;i<v.size();i++)
	{
		cout<<v.at(i)<<" ";
	}
	cout<<endl;
}
void find_sum2(Node *head,int sum,vector<int> v,int level)
{
	if (!head)
	{
		return;
	}
	v.push_back(head->data);
	int tmp=0;
	for (int i=level;i>-1;--i)
	{
		tmp+=v.at(i);
		if (tmp==sum)
		{
			print1(v,i);
		}
	}
	vector<int> v1(v),v2(v);
	find_sum2(head->left,sum,v1,level+1);
	find_sum2(head->right,sum,v2,level+1);
}
