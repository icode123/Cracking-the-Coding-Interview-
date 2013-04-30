bool isMatch(Node *r1,Node *r2)
{
  if (!r1 && !r2)
	{
		return true;
	}
	if (!r1 || !r2)
	{
		return false;
	}
	if (r1->data!=r2->data)
	{
		return false;
	}
	return isMatch(r1->left,r2->left) && isMatch(r1->right,r2->right);
}

bool subtree(Node *r1,Node *r2)
{
	if (!r1)
	{
		return false;
	}
	if (r1->data==r2->data)
	{
		if (isMatch(r1,r2))
		{
			return true;
		}
	}
	return subtree(r1->left,r2) || subtree(r1->right,r2);
}

bool contain_tree(Node *r1,Node *r2)
{
	if (!r2)
	{
		return true;
	}
	else
	{
		return subtree(r1,r2);
	}
}
