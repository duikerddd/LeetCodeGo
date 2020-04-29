void Reverse(char* begin, char* end)
{
	//无效输入
	if (begin == NULL || end == NULL) return;

	//交换
	while (begin < end)
	{
		char tmp = *begin;
		*begin = *end;
		*end = tmp;

		begin++; end--;
	}
}

char* LeftRotateString(char* s, int n)
{
	if (s == NULL || n<0) return NULL;

	int len = static_cast<int>(strlen(s));
	int left = n%len;
	char* begin1 = s;
	char* end1 = s + left-1;
	char* begin2 = end1 + 1;
	char* end2 = s + len-1;
	//翻转部分 
	Reverse(begin1, end1);
	Reverse(begin2, end2);
	//翻转整体
	Reverse(begin1, end2);
	return s;
}  
