#include<iostream>
using namespace std;
string change_to_string(int cardnum, int n) {
	string cardface[15] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A","joker","JOKER" };
	string cardsuit[4] = { "a","b","c","d" };
	if (n == 0)//�����������
		return cardface[cardnum];
	else if (n == 1)//������滨ɫ�����Ʋ��������out_card���ƣ�
		return "(" + cardsuit[cardnum] + ")";//c++ string ��ǿ��֮��,��atoiǿ
	return "NULL";//������
}