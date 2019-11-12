#include<stack>
using namespace std;

class Parenthesis {
public:
    //1.只包含括号字符
    //2.一一对应
    //用栈实现,左括号入,遇到右括号出
    bool chkParenthesis(string A, int n) {
            stack<char> st;
            
            for(int i=0;i<A.size();++i)
            {
                if(A[i]=='(')
                {
                    st.push('(');
                }
                else if(A[i]==')')
                {
                    //右括号多余
                    if(st.empty())
                    {
                        return false;
                    }
                    st.pop();
                }
                //有其他字母
                else
                {
                    return false;
                }
            }
            //左括号多余
            if(!st.empty())
            {
                return false;
            }
            return true;
            
            
    }
};
