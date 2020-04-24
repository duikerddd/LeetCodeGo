
//解法2:  同步指针法,计算出长度,让长的多走直到和短的一样长,再一起遍历比较
typedef struct ListNode{
	int data;
	ListNode* next;
}ListNode;

int GetLength(ListNode* p)
{
	int len = 0;
	ListNode* cur = p;
	for (cur; cur != NULL; cur = cur->next)
	{
		++len;
	}
	return len;
}

ListNode* FirstCommonNode(ListNode* p1,ListNode* p2)
{
	//无效输入
	if (p1 == NULL || p2 == NULL)
		return NULL;
	//统计长度
	int len1 = GetLength(p1);
	int len2 = GetLength(p2);
	//长的对齐
	int dif = len1 - len2;
	ListNode* LongNode = p1;
	ListNode* ShortNode = p2;
	if (len1 < len2)
	{
		dif = len2 - len1;
		LongNode = p2;
		ShortNode = p1;
	}
	while (dif--)
	{
		LongNode = LongNode->next;
	}
	//同步比较
	while (LongNode != NULL)
	{
		if (LongNode->data == ShortNode->data)
			return LongNode;
	}
	//没找到
	return NULL;
}
