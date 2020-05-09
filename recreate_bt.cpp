
Node* ReCreateTree(int* preorder, int* inorder, int size)
{
	//无效输入
	if (preorder == NULL || inorder == NULL || size <= 0)
		return NULL;

	return ReCreate(preorder, inorder, 0, size-1);
}
