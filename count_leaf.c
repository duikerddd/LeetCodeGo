//求结点个数
//终止条件: 
//1)空树 return 0
//2)叶子结点 return 1
//3)一个孩子为空

int GetSize(BNode *root)
{
	//终止条件
	if (root == NULL)
	{
		//空树
		return 0;
	}
	//递推
	return GetSize(root->left) +
		GetSize(root->right) + 1;
}
