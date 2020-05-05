
//解法1: 私有构造函数,让子类函数无法调用其构造和析构.
//为了自己能够实现构造和析构,用静态函数实现
class Sealed{
  public:
      static Sealed* GetInstance()
      {
          return new Sealed();
      }
      static void DeleteInstance(Sealed* pInstance)
      {
          delete pInstance;
      }
  private:
      Sealed(){}
      ~Sealed(){}  
};
