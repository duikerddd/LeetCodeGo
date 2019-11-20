#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string str;
    while (getline(cin, str)) {
        
        bool flag = false;
        vector<string> vec;
        string row;
        
        for (int i = 0; i < str.size(); i++) {
            if (flag) {//在括号内
                if (str[i] != '\"') 
                    row += str[i];
                else 
                    flag = false;
            } else {
                //空格 --- 截断输入,更新字符串
                if (str[i] == ' ') {
                    vec.push_back(row);
                    row = "";
                }
                //双引号 --- 特殊处理
                else if (str[i] == '\"') 
                            flag = true;
                //正常情况给字符串加字符
                else 
                    row += str[i];
            }
        }
        
        vec.push_back(row);
        cout << vec.size() << endl;
        for (auto i : vec)
            cout << i << endl;
        
       
    }
    return 0;
}
