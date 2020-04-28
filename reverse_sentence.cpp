
void Reverse(char* begin,char* end)
{
	//无效输入
	if (begin == NULL || end == NULL) return;

	while (begin <  end)
	{
		char tmp = *begin;
		*begin = *end;
		*end = tmp;

		begin++; end--;
	}
}

char* ReverseSentence(char* s)
{
	//无效输入
	if (s == NULL) return NULL;

	//整体翻转
	char* begin = s;
	char* end = s;
	while (*end != '\0')
		end++;
	end--;
	Reverse(begin,end);

	//局部翻转
	begin = s;
	char* cur = s;
	while (*cur!='\0')
	{
		//遇到空格后,begin先不变,end在空格之前
		//           翻转完,begin在空格之后
		//翻转完,cur++.
		if (*cur == ' ')
		{
			end = cur;
			end--;
			Reverse(begin, end);
			begin = cur;
			begin++;
		}
		cur++;
	}
	return s;
}
