
class BinInsert {
public:

    //n   1024 =  10 0000 0000            10 0000 0000    
    //m   19 =          1 0011 -->左移2位      100 11
    //                                    10 0100 1100
    //m插入到n的j~i位
    //m左移到i位,直接|,即可插入
    int binInsert(int n, int m, int j, int i) {
        m <<= j;
        return n | m;

    }
};
