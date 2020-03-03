class Solution {
public:
    //贪心算法:尽量使用最少的字符,从最大的开始
    string intToRoman(int num) {
        map<int,string> mapRom = {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"}, {90,"XC"},
                                  {100,"C"},{400,"CD"},{500,"D"},{900,"CM"}, {1000,"M"} };
        auto r_iter = mapRom.rbegin();
        
        
        string ret;
       
        while(num>0 && r_iter!=mapRom.rend())
        {
            if(num >= r_iter->first)
            {
                ret += r_iter->second;
                num-= r_iter->first;
            }
            else
                r_iter++;
        }
        return ret;

        
    }
};
