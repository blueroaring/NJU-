#include<iostream>
#include<string>
using namespace std;
int change_to_num(string s, int num) {//��������ַ���ת��Ϊ��Ӧ����,2->0,��������
	string cardface[15] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A","joker","JOKER" };//����
	string cardsuit[4] = { "a","b","c","d" };//��ɫ
	//num=0:ת����������   =1:ת����ɫ
	if (num == 0) {
		if (s.substr(0, 2) == "10")//substr��������aλ�ÿ�ʼ��ѯ��һֱ��ѯb���ַ�
			return 8;//ֻ��10����λ�����������ǣ���֤�����߼����ң�
		else {
			for (int a = 0; a < 13; a++)//��������
				if (cardface[a] == s.substr(0, 1)&&s.substr(0,2)!="jo"&&s.substr(0,2)!="JO")
					return a;
			if (s.substr(0, 2) == "jo")
				return 13;
			if (s.substr(0, 2) == "JO")
				return 14;
		}
	}
	else if (num == 1) {//��ɫͬ��
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
