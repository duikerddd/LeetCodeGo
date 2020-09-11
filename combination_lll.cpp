//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
//解题思路: dfs .  组合 
 //       [ 1 2 3 4 5 6 7 8 9 ]

class Solution
 {
public:   
     vector<vector<int>> ret;  
     vector<int> tmp;  
     void dfs(int target,int count,int begin,int sum) 
     {       
      if(count==0 && target == sum) 
                  ret.push_back(tmp); 
               
      //大剪枝: 个数用光, 总和超过        
      if(count<0 || target<sum) return;       
     
      for(int i=begin;i<10;++i)        
      {             
          sum+=i;            
          tmp.push_back(i);            
          count--;                        
          dfs(target,count,i+1,sum);          
          sum-=i;            
          tmp.pop_back();            
          count++;        
       }    
   }    

 vector<vector<int>> combinationSum3(int k, int n) 
 {        
       dfs(n,k,1,0);       
       return ret;   
 }
};
