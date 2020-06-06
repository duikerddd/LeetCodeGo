//栈的压入,弹出
//给一个压入栈的顺序,问: 弹出栈的顺序是否可能

//辅助栈: 压入数字,栈顶如果和pop相等则弹出,否则继续压栈
//        辅助栈还有数据则表示不是弹出顺序 
// push:  1 2 3 4
// pop:   1 4 3 2
// stack: 1
bool IsPopOrder(vector<int> push,vector<int> pop)
{
    //无效输入
    if(push.empty() || pop.empty()) return false;
    
    //辅助栈
    stack<int> s;
    int j = 0;
    for(int i=0;i<push.size();++i)
    {
       s.push_back(push[i]);
       
       //比较是否弹出
       while(j<pop.size() && s.top() == pop[j])
       {
            s.pop();
            j++;
       }
    }
    //不是正常序列
    if(!s.empty()) return false;
    
    return true;
}



