#include<iostream>
using namespace std;
int card_type(int(*play)[2], int m) {
	bool a = true;
	if (m == 1)//����
		return 1;
	else if (m == 2 && play[0][0] == play[1][0])//����
		return 2;
	else if (m == 6 && play[0][0] == play[1][0] && play[2][0] == play[3][0]
		&& play[4][0] == play[5][0] && play[0][0] - 1 == play[2][0]
		&& play[2][0] - 1 == play[4][0])
		return 3;
	else if (m == 3 && play[0][0] == play[1][0] && play[1][0] == play[2][0])//������
		return 4;
	else if (m == 6 && play[0][0] == play[1][0] && play[0][0] == play[2][0]
		&& play[3][0] == play[4][0] && play[3][0] == play[5][0]
		&& play[0][0] - 1 == play[3][0])//������
		return 5;
	else if (((m == 5 && play[0][0] == play[1][0] && play[0][0] == play[2][0]
		&& play[3][0] == play[4][0] && play[0][0] != play[3][0])) ||
		(m == 5 && play[0][0] == play[1][0] && play[2][0] == play[3][0] && play[2][0] == play[4][0])
		&& play[0][0] != play[2][0])//������AAABB����AABBB
		return 6;
	else if (m == 5 && play[0][0] - 1 == play[1][0] && play[1][0] - 1 == play[2][0]
		&& play[2][0] - 1 == play[3][0] && play[3][0] - 1 == play[4][0]) //˳��
		if (play[0][1] == play[1][1] && play[0][1] == play[2][1]
			&& play[0][1] == play[3][1] && play[0][1] == play[4][1]) //ͬ��˳
			return 8;
		else
			return 7;
	else if (m == 4) {
		if (play[0][0] == play[1][0] && play[1][0] == play[2][0] && play[2][0] == play[3][0])//��ͨը��
			return 9;
		if (play[0][0] == play[1][0] && play[2][0] == play[3][0]
			&& play[0][0] == 14 && play[2][0] == 13) //�Ĵ�����
			return 10;
	}
	else if (m > 4) {//������ͨը��
		for (int i = 1; i < m; i++)
			if (play[i - 1][0] != play[i][0])
				a = false;
		if (a)
			return 9;
	}
	return -1;
}