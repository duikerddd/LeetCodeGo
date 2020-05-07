//赋值运算符重载
MyString operator=(const MyString& s)
{
    //不是自己
    if(this!=s){
       //删除自己的空间
       delete[] _data;
       _data = nullptr;
       //申请空间
       _data = new char[strlen(s._data) + 1];
       //赋值
       strcpy(_data,s._data);
    }
    return *this;
}

//更安全的版本
//new char失败会抛异常-->指针置空
//解决: 用tmp
MyString& operator=(const MyString& s)
{
    if(this!=s)
    {
        //构造一个tmp
        MyString tmp(str);
        
        //指针内容互换
        char* ptmp = tmp._data;
        tmp._data = _data;
        _data = ptmp;
    }
    return *this;
}
