#include<iostream>
#define NDEBUG
using namespace std;
#include <conio.h>
#include <time.h>
#include<easyx.h>
#include "print_card.h"
void judge(int(*hand)[2], int(*play)[2], int n, int m, int level) {//判断最小并输出
	int i, j, face, suit;
	card_sort(hand, n, level);//排序防止意外
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
		card_sort(play, m, 14);//对手出的和级牌无关无所谓
	if (card_type(play, m) == 6 && play[0][0] != play[2][0]) {//三带二将BBAAA转为AABBB方便统一
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
	if (m == 0)//自己出牌逻辑
	{
		delete_card(hand, play, n, m, level);//先找出炸弹和同花顺剔除
		find_min(hand, play, n, m, level);//找剩下牌型中的最小
		run_card(hand, play, n, m, level);//出牌
	}
	switch(card_type(play,m))//m=0时，返回-1，直接break了
	{
	case 1: //单张
		run_card_1(hand, play, n, m, level);
		break;
	case 2: //对子
		get_small_pair(hand, play, n, m, level);
		break;
	case 3: //三连对
		get_small_three_pair(hand, play, n, m, level);
		break;
	case 4: //三同张
		get_small_three(hand, play, n, m, level);
		break;
	case 5: //二连三
		get_small_double_three(hand, play, n, m, level);
		break;
	case 6: //三带二
		get_small_three_two(hand, play, n, m, level);
		break;
	case 7: //顺子
		get_small_five(hand, play, n, m, level);
		break;
	case 8: //同花顺
		get_small_five(hand, play, n, m, level);
		break;
	case 9: //炸弹
		get_small_bomb(hand, play, n, m, level);
		break;
	case 10: //四大天王
		pass(hand, n);
		break;
	default:
		break;
	}


}