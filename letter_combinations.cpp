//电话号码的字母组合
//input: 2-9 output:2-9表示的字母组合

//解题思路: 每个数字能代表很多字母,输入23相当于输入了"abc""def"
//         本质上就是求多个字符串之间的有序组合
//解法: 1.做一个映射数组 2.求组合,dfs

class Solution {
public:
    vector<string> ans;
    string tmp;
    map<int, string> itos = { { 2, "abc" }, { 3, "def" }, { 4, "ghi" }, \
	                            {5, "jkl"}, { 6, "mno" }, { 7, "pqrs" }, \
	                            {8, "tuv"}, { 9, "wxyz" } };
											

    void dfs(string& digits, int cur_pos)
    {
	   //终止条件: 到达最后一个数字. 输出组合
	    if (cur_pos == digits.size())
	    {
		    ans.push_back(tmp);
		    return;
	    }

	    int cur_num = digits[cur_pos] - '0';
	    //遍历该位置的数字的所有情况
	    for (int i = 0; i < itos[cur_num].size(); ++i)
	    {
		    tmp.push_back(itos[cur_num][i]);
		    //深入
		    dfs(digits,  cur_pos+1);
		    //回溯
		    tmp.pop_back();
	    }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;

	    
    	dfs(digits, 0);
	    return ans;
    }
};
