/*日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
  嫌疑犯的一个。以下为4个嫌疑犯的供词。
  A说：不是我。   a=0
  B说：是C。   c=1 
  C说：是D。      d=1
  D说：C在胡说    d=0
  已知3个人说了真话，1个人说的是假话。
  现在请根据这些信息，写一个程序来确定到底谁是凶手*/
#include <stdio.h> 
#include<stdlib.h>
  int main()  //用逻辑直接翻译语言
{
	int murder;
	for (murder = 'A'; murder <= 'D'; murder++)
	{
		if (((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D')) == 3)
			//三真一假，在if语句的，括号里为真结果为1，要是假结果为0。因此if括号后面若成立，必定为三真一假，即必定等于3.      
		{
			printf("murder is %c\n", murder);     //由于最终要输出凶手，为一个字符，%c可用输出字符                
		}
}

	system("pause");
	return 0;

}
