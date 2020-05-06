//解法2: 私有一个辅助类,子类虚继承辅助类,并是他的友元.
//       友元能够调用辅助类的私有函数
//       虚继承会让继承他的类先调用虚基类,然而虚基类私有了构造和析构,所以调用不了
class MakeSealed{
    friend SealedClass;
 private:
     MakeSealed();
     ~MakeSealed();
};

class SealedClass : virtual public MakeSealed;
{
 public:
     SealedClass();
     ~SealedClass();
}
