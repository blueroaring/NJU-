#include<iostream>
using namespace std;
string change_to_string(int cardnum, int n) {
	string cardface[15] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A","joker","JOKER" };
	string cardsuit[4] = { "a","b","c","d" };
	if (n == 0)//输出牌面数字
		return cardface[cardnum];
	else if (n == 1)//输出牌面花色（王牌不输出，在out_card控制）
		return "(" + cardsuit[cardnum] + ")";//c++ string 的强大之处,比atoi强
	return "NULL";//出错检测
}