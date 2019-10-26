class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //用size记录最长子串长度
        //for循环内记录每一段不重复子串长度并比较
        if(s.size()==1)
        {
            return 1;
        }
        
        string _s;
        int size = 0;
        for(int i=0;i<s.size();++i)
        {
            //比较是否有重复,重复则看长度大小
           for(int j=0;j<_s.size();++j)
           {
               //重复,提取长度比较,清空_s
               if(_s[j]==s[i])
               {
                   if(size < _s.size())
                   {
                       size = _s.size();
                   }
                   _s.erase(_s.begin(),_s.begin()+j+1);
                   break;
               }
           }
            
            
            _s.push_back(s[i]);
        }
        
        if(size<_s.size())
        {
            size = _s.size();
        }
        
       
        return size;
        
    }
};
