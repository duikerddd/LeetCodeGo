class LCA {
public:
    
    //核心 : parent=child/2; 
    //思路 : 因为不知道两个的大小,所以要让大的变小,然后迭代比较
    int getLCA(int a, int b) {
        while (a!=b)
        {
            if (a>b)
            {
                a /= 2;
            }
            else
            {
                b /= 2;
            }
        }
        return a;
    }
};
