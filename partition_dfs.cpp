class Solution {
public:
    vector<vector<string>> ret;
    vector<string> tmp;

    bool isPartition(string s,int left,int right)
    {
        while(left<right)
        {
            if(s[left]!=s[right]) return false;
            left++;right--;
        }
        return true;
    }
    //dfs
    void dfs(string s,int begin)
    {
          if(begin==s.size())
          {
              ret.push_back(tmp);
              return;
          }

          for(int i=begin;i<s.size();i++)
          {
              if(isPartition(s,begin,i))
              {
                  tmp.push_back(s.substr(begin,i-begin+1));
                  dfs(s,i+1);
                  tmp.pop_back();
              }
          }
    }

    vector<vector<string>> partition(string s) {
        dfs(s,0);
        return ret;
    }
};
