
Node* buildTree(int* preorder,int ps,int pe,int* inorder,int is,int ie)
{
	//终止条件: 没有节点
	int len = pe - ps + 1;
	if (len <= 0) return NULL;
	
	//建立根节点
	Node* root = new Node();
	root->_data = preorder[ps];
	
	//只有一个节点
	if (len == 1) return root;

	//寻找中序遍历中根节点的位置
	//index为当前中序遍历区间的分界线
	//index = root下标 = 左子树个数;
	int index = 0;
	for (int i = is; i <= ie; ++i)
	{
		if (inorder[i] == root->_data)
		{
			index = i - is;
			break;
		}
	}

	//递归遍历: 注意计算好pre和inorder的起终点位置
	root->_left = buildTree(preorder, ps + 1, ps + index, inorder, is, is+index - 1);
	root->_right = buildTree(preorder, ps + index + 1, pe, inorder, is + index + 1, ie);

	return root;

}

Node* ReCreateTree(int* preorder, int* inorder, int size)
{
	//无效输入
	if (preorder == NULL || inorder == NULL || size <= 0)
		return NULL;

	return buildTree(preorder,0,size-1,inorder,0,size-1);  
}
