//第一次加锁--提高性能,防止有变量后还加锁影响性能
//      第二次加锁--防止两个线程同时访问,创建两个!
class Singleton
{
  public:
      static Singleton* GetInstance()
      {
          if(m_instance==NULL){
              Lock();
              if(m_instance==NULL)
              {
                  m_instacne = new Singleton();
              }
              return m_instance;
         }
      }  
  private: 
      Singleton(){}
      Singleton(Singleton const&) = delete;     
      Singleton& operator=(Singleton const&) = delete; 
      static Singleton* m_instance;
};
