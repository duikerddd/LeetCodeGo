class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
     vector<vector<string>> ret;
     vector<string> tmp;
     
     bool IsPalind(string& s,int begin,int end)
     {
         int left = begin;
         int right = end;
         
         while(left<right)
         {
             if(s[left]!=s[right])
            {
                return false;        
            }
            left++;right--;
         }
         
         return true;
     }
     
    //dfs
    //a
    //aa 
    //aab
    //按照切割大小遍历
    void dfs(string& s,int begin)
    {
        if(begin == s.size())
        {
            ret.push_back(tmp);
            return;
        }
        
        for(int i=begin;i<s.size();++i)
        {
            if(IsPalind(s,begin,i)) 
            {
                tmp.push_back(s.substr(begin,i-begin+1));
                dfs(s,i+1);
                tmp.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string &s) {
        // write your code here
        dfs(s,0);
        return ret;
    }
    
};
