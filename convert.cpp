class Solution {
public:
/*   0          0
*    0      0   0
*    0  0       0
*    0          0
*/
//数学规律题
//规律: 第一排是向下转折,最后一排是向上转折
//方法: down标记是否向下   if index==numRow-1 down=false if index==0 down=true
    string convert(string s, int numRows) {
        //1行直接返回
        if(numRows==1)
            return s;

        //记录是否向下
        bool down = false;
        vector<string> vs(numRows);
        int index = 0;
       
        for(int i=0;i<s.size();++i)
        {
             vs[index] += s[i];
            if(index == 0 || index == numRows - 1)
                down = !down;
            index += down ? 1 : -1;
        }

        string ret;
        for(auto& it:vs)
        {
            ret+=it;
        }

        return ret;
    }
};
