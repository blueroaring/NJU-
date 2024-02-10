#include<iostream>
#define NDEBUG
using namespace std;
#include <conio.h>
#include <time.h>
#include<easyx.h>
#include "print_card.h"
void judge(int(*hand)[2], int(*play)[2], int n, int m, int level) {//�ж���С�����
	int i, j, face, suit;
	card_sort(hand, n, level);//�����ֹ����
#ifdef DEBUG
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < 2; j++)
			cout << hand[i][j] << "  ";
	}
	for (int i = 0; i < m; i++) {
		cout << endl;
		for (int j = 0; j < 2; j++)
			cout << play[i][j] << "  ";
	}
#endif
	if (m > 0)
		card_sort(play, m, 14);//���ֳ��ĺͼ����޹�����ν
	if (card_type(play, m) == 6 && play[0][0] != play[2][0]) {//��������BBAAAתΪAABBB����ͳһ
		for (int i = 0; i < 2; i++)
		{
			face = play[0][0]; 
			suit = play[0][1];
			for (int j = 1; j < 5; j++)
			{
				play[j - 1][0] = play[j][0];
				play[j - 1][1] = play[j][1];
			}
			play[4][0] = face;
			play[4][1] = suit;
		}
	}
	if (m == 0)//�Լ������߼�
	{
		delete_card(hand, play, n, m, level);//���ҳ�ը����ͬ��˳�޳�
		find_min(hand, play, n, m, level);//��ʣ�������е���С
		run_card(hand, play, n, m, level);//����
	}
	switch(card_type(play,m))//m=0ʱ������-1��ֱ��break��
	{
	case 1: //����
		run_card_1(hand, play, n, m, level);
		break;
	case 2: //����
		get_small_pair(hand, play, n, m, level);
		break;
	case 3: //������
		get_small_three_pair(hand, play, n, m, level);
		break;
	case 4: //��ͬ��
		get_small_three(hand, play, n, m, level);
		break;
	case 5: //������
		get_small_double_three(hand, play, n, m, level);
		break;
	case 6: //������
		get_small_three_two(hand, play, n, m, level);
		break;
	case 7: //˳��
		get_small_five(hand, play, n, m, level);
		break;
	case 8: //ͬ��˳
		get_small_five(hand, play, n, m, level);
		break;
	case 9: //ը��
		get_small_bomb(hand, play, n, m, level);
		break;
	case 10: //�Ĵ�����
		pass(hand, n);
		break;
	default:
		break;
	}


}