#include<iostream>
#include<string>

using namespace std;

//长度得分
int length(string s){
	size_t len = s.size();
	if (len <= 4){
		return 5;
	}
	else if (len >= 5 && len <= 7){
		return 10;
	}
	return 25;
}
//字母得分(用了isalpha等三个函数)
int letter(string s){
	size_t alpha = 0;
	size_t  big = 0;
	size_t small = 0;
	size_t i = 0;
	for (i = 0; i < s.size(); i++){
		if (isalpha(s[i])){
			alpha++;
		}
		if (isupper(s[i])){
			big++;
		}
		if (islower(s[i])){
			small++;
		}
	}
	if (alpha == 0){
		return 0;
	}
	if (big == s.size() || small == s.size()){
		return 10;
	}
	if (big > 0 && small > 0){
		return 20;
	}
	return 0;
}
//数字得分(用了isdigit函数)
int number(string s){
	int count = 0;
	size_t i = 0;
	for (i = 0; i < s.size(); i++){
		if (isdigit(s[i])){
			count++;
		}
	}
	if (count == 0){
		return 0;
	}
	if (count == 1){
		return 10;
	}
	if (count > 1){
		return 20;
	}
	return 0;
}
//符号得分(isalnum可以判断是否是字母或数字 除此之外就是字符)
int sign(string s){
	int count = 0;
	size_t i = 0;
	for (i = 0; i < s.size(); i++){
		if (!isalnum(s[i])){
			count++;
		}
	}
	if (count == 0){
		return 0;
	}
	if (count == 1){
		return 10;
	}
	if (count > 1){
		return 25;
	}
	return 0;
}
//奖励得分
int reward(string s){
	int count = 0;
	if (letter(s) == 20 && number(s) > 0 && sign(s) > 0){
		return 5;
	}
	else if (letter(s) > 0 && number(s) > 0 && sign(s) > 0){
		return 3;
	}
	else if (letter(s) > 0 && number(s) > 0){
		return 2;
	}
	return 0;
}

void GetPwdSecurityLevel(string pPasswordStr){
	int ret1 = length(pPasswordStr);
	int ret2 = letter(pPasswordStr);
	int ret3 = number(pPasswordStr);
	int ret4 = sign(pPasswordStr);
	int ret5 = reward(pPasswordStr);
	int ret = ret1 + ret2 + ret3 + ret4 + ret5;
	if (ret >= 90){
		cout << "VERY_SECURE" << endl;
	}
	else if (ret >= 80){
		cout << "SECURE" << endl;
	}
	else if (ret >= 70){
		cout << "VERY_STRONG" << endl;
	}
	else if (ret >= 60){
		cout << "STRONG" << endl;
	}
	else if (ret >= 50){
		cout << "AVERAGE" << endl;
	}
	else if (ret >= 25){
		cout << "WEAK" << endl;
	}
	else if (ret >= 0){
		cout << "VERY_WEAK" << endl;
	}
	return;
}

int main(){
	string pPasswordStr;
	while(getline(cin, pPasswordStr))
	GetPwdSecurityLevel(pPasswordStr);

	return 0;
}
