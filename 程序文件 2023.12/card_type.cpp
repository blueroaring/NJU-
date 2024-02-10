#include<iostream>
using namespace std;
int card_type(int(*play)[2], int m) {
	bool a = true;
	if (m == 1)//单张
		return 1;
	else if (m == 2 && play[0][0] == play[1][0])//对子
		return 2;
	else if (m == 6 && play[0][0] == play[1][0] && play[2][0] == play[3][0]
		&& play[4][0] == play[5][0] && play[0][0] - 1 == play[2][0]
		&& play[2][0] - 1 == play[4][0])
		return 3;
	else if (m == 3 && play[0][0] == play[1][0] && play[1][0] == play[2][0])//三连张
		return 4;
	else if (m == 6 && play[0][0] == play[1][0] && play[0][0] == play[2][0]
		&& play[3][0] == play[4][0] && play[3][0] == play[5][0]
		&& play[0][0] - 1 == play[3][0])//二连三
		return 5;
	else if (((m == 5 && play[0][0] == play[1][0] && play[0][0] == play[2][0]
		&& play[3][0] == play[4][0] && play[0][0] != play[3][0])) ||
		(m == 5 && play[0][0] == play[1][0] && play[2][0] == play[3][0] && play[2][0] == play[4][0])
		&& play[0][0] != play[2][0])//三带二AAABB或者AABBB
		return 6;
	else if (m == 5 && play[0][0] - 1 == play[1][0] && play[1][0] - 1 == play[2][0]
		&& play[2][0] - 1 == play[3][0] && play[3][0] - 1 == play[4][0]) //顺子
		if (play[0][1] == play[1][1] && play[0][1] == play[2][1]
			&& play[0][1] == play[3][1] && play[0][1] == play[4][1]) //同花顺
			return 8;
		else
			return 7;
	else if (m == 4) {
		if (play[0][0] == play[1][0] && play[1][0] == play[2][0] && play[2][0] == play[3][0])//普通炸弹
			return 9;
		if (play[0][0] == play[1][0] && play[2][0] == play[3][0]
			&& play[0][0] == 14 && play[2][0] == 13) //四大天王
			return 10;
	}
	else if (m > 4) {//其他普通炸弹
		for (int i = 1; i < m; i++)
			if (play[i - 1][0] != play[i][0])
				a = false;
		if (a)
			return 9;
	}
	return -1;
}