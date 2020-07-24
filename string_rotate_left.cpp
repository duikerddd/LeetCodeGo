//左旋字符串

//解题思路
// iams 3 --> siam
// mai s
// s iam
//先局部,再整体

char* LeftRotateString(char* s, int len,int n)
{
      if(s==NULL) return ' ';
    
      int left = n%len;
      char* begin1 = s+left-1;
      char* end1 = s+left;
      Reverse(s,end1);
      Reverse(begin2,s+len);
      Reverse(s,s+len);
      
}
