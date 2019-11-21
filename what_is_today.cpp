#include<iostream>
#include<vector>
using namespace std;

//计算日期是当年第几天
int Cal(int year, int month, int day)
{
	int sum = 0;
	int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//特殊:闰年2月29天 
    //闰年:被四整除不被100整除 || 被400整除
	if ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0))
		months[2] = 29;

	if (month<1 || month>12 || day<0 || day>31)
		return -1;

	if (month == 1 && day>0 && day<32)
		return day;

    //迭代加到本月之前
	switch (month){
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		if (day>0 && day <= 31){
			for (int i = 1; i < month; i++)
			{
				sum += months[i];
			}
		}
		else
			return -1;
		break;

	case 2:
		if (day>0 && day <= months[2]){
			sum += months[1];
		}
		else
			return -1;
		break;

	case 4:case 6 : case 9 : case 11 :
		if (day>0 && day <= 30){
			for (int i = 1; i < month; i++)
			{
				sum += months[i];
			}
		}
		else
			return -1;
		break;

	}
    //加上天数即可
	sum += day;
	
	return sum;
}

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
		cout<<Cal(year, month, day)<<endl;
	return 0;
}
