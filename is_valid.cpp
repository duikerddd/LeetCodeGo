class Solution {
public:
    
    
    bool isValid(string s) {
        stack<char> cp;

        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='{' || s[i]=='[' || s[i]=='(')
                cp.push(s[i]);
            else if(cp.empty()) return false;
            else
            {
                
                if(s[i]=='}' && cp.top()=='{') 
                {
                    cp.pop(); continue;
                }
                if(s[i]==')' && cp.top()=='(') 
                {
                    cp.pop(); continue;
                }
                if(s[i]==']' && cp.top()=='[') 
                {
                    cp.pop(); continue;
                }
                return false;
            }
            
        }

        if(cp.empty()) return true;
        return false;
    }
};
