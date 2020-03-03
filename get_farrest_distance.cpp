//二叉树中,两点之间的最远距离
//前序遍历,回溯时计算
int GetFarrestDistance(BNode *root)
{
  //终止条件: 走到头 
	if (root == NULL)
	{
		return 0;
	}


	int leftDistance = GetFarrestDistance(root->left);
	int rightDistance = GetFarrestDistance(root->right);

	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);
  //记录最
	int rootDistance = leftHeight + rightHeight;

	return MAX3(leftDistance, rightDistance, rootDistance);
}
