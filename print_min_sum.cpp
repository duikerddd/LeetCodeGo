//把数组排成最小的数
//input: arr = {3,32,321} output: 32123

//解法: 1.将数组元素进行自定义排序 2.直接拼接排序后的数组
//      1.1 设置cmp函数为< 1.2 拼接比较的两数,返回较小的
/*{3,32,321}
  1.  332 323 ->  32 , 3
  2.  3213 3321 -> 321 , 3
  3.  32132 32321-> 321 ,32
  -->{321,32,3} == 321323
*/
class Solution{
public:
  static bool cmp(int a,int b)
  {
      string A = "";
      string B = "";
      
      A+=to_string(a);
      A+=to_string(b);
      B+=to_string(b);
      B+=to_string(a);
      
      return A<B;
  }
 string PrintMinNumber(vector<int> numbers) {
      if(numbers.empty()) return "";
      
      string ret;
      //1.自定义排序
      sort(numbers.begin(),numbers.end(),cmp);
      //2.输出
      for(int i=0;i<numbers.size();++i)
          ret+=to_string(numbers[i]);
          
      return ret;
 }
