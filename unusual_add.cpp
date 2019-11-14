class UnusualAdd {
public:
    //异或---半加运算,不进位的加法
    //1.异或ab得没有进位的和sum
    //2.ab按位与得需要进位的位,向右移位一个和sum继续加
    //3.直到没有进位
 
    int addAB(int A, int B) {
       
       if(B==0)
           return A;
       int sum = A^B;
       int carry = (A&B)<<1;
       
       return addAB(sum,carry);
    }
};
