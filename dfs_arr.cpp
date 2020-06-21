//字符串排列
//输入abc  写出所有排可能排列顺序

//                " "
//   "a"          "b"            "c"
//"ab"   "ac"  "ba"   "bc"    "ca"   "cb"
//"abc"  "acb" "bac"  "bca"  "cab"     "cba"

//算法: 深度优先遍历+回溯  特殊情况: aa重复 使用find去重
//模型: 数组输出
vector<string> Permutation(string str)
{
    if(str.size()==0) return NULL;
    
    vector<string> str_arr;
    //深度优先遍历+回溯
    DFS(str,str_arr);
    
    //字典序输出
    sort(str_arr.begin(),str_arr.end(),0);
    return str_arr;
}

void DFS(string& str,vector<string>& str_arr,int begin)
{
    //1.判断边界: 字母全部都用完了,放入数组
    if(begin == str.size()-1)
    {
        //没找到则添加
        if(find(str_arr.begin(),str_arr.end(),str) == str_arr.end())
        {
            str_arr.push_back(str);
        }
    }
   
    else
    {
        //2.尝试每一种可能
        for(int i=begin;i<str.size();++i)
        {
        swap(str[i],str[begin]);  //i:选定的字母 begin:固定的位置
        //3.下一步可能
        DFS(str,str_arr,i+1);
        //4.回溯原状态
        swap(str[i],str[begin]);
        }
    }
}
