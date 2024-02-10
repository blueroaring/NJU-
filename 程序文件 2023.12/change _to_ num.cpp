#include<iostream>
#include<string>
using namespace std;
int change_to_num(string s, int num) {//将输入的字符串转换为对应整数,2->0,依次类推
	string cardface[15] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A","joker","JOKER" };//牌面
	string cardsuit[4] = { "a","b","c","d" };//花色
	//num=0:转换牌面数字   =1:转换花色
	if (num == 0) {
		if (s.substr(0, 2) == "10")//substr函数：从a位置开始查询，一直查询b个字符
			return 8;//只有10是两位数，单独考虑（保证下面逻辑不乱）
		else {
			for (int a = 0; a < 13; a++)//除了王牌
				if (cardface[a] == s.substr(0, 1)&&s.substr(0,2)!="jo"&&s.substr(0,2)!="JO")
					return a;
			if (s.substr(0, 2) == "jo")
				return 13;
			if (s.substr(0, 2) == "JO")
				return 14;
		}
	}
	else if (num == 1) {//花色同理
		if (s.substr(0, 2) == "10") {
			for (int d = 0; d < 4; d++)
				if (cardsuit[d] == s.substr(3, 1))
					return d;
		}
		else {
			for (int d = 0; d < 4; d++)
				if (cardsuit[d] == s.substr(2, 1))
					return d;
			if (s.substr(0, 2) == "jo" || s.substr(0, 2) == "JO")
				return 4;

		}
	}
	return -1;
		
		
}
