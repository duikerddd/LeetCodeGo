
typedef struct BTNode{
	BTNode* _left;
	BTNode* _right;
	int _data;
}Node;

Node* CreateNode(int data)
{
	Node* node = new Node;
	node->_data = data;
	node->_left = NULL;
	node->_right = NULL;
	
	return node;
}
Node* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	if (preorderSize <= 0) {
		return NULL;
	}
	//创建根节点
	Node *root = new Node();
	root->_data = preorder[0];
	//搜索根节点在中序的位置
	//index: 根节点位置,左子树数量
	int index = 0;
	for (int i = 0; i < preorderSize; ++i)
	{
		if (inorder[i] == preorder[0])
			index = i;
	}
		
	//递归,计算前序遍历和中序遍历的起点和大小
	root->_left = buildTree(preorder + 1, preorderSize-1, inorder, index);
	root->_right = buildTree(preorder + 1 + index, preorderSize - 1 - index, inorder + index + 1, preorderSize - 1 - index);

	return root;
}

Node* ReCreateTree(int* preorder, int* inorder, int size)
{
	//无效输入
	if (preorder == NULL || inorder == NULL || size <= 0)
		return NULL;

	return buildTree(preorder,size,inorder,size);
}
