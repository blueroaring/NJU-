/*#include<iostream>
#define NDEBUG
using namespace std;
int main() {
	int  times, n, m,level;
	string level1;
	//times:执行次数，level:当前级牌(0-12),n:现在手上的牌数，m:对方打出牌数
	string card;//string类型，代替c的假字符串
	extern int change_to_num(string s, int num);//将输入的字符串转换为对应整数
	extern void judge(int(*arr1)[2], int(*arr2)[2], int n, int m, int level,int times);
		int card_on_hand[27][2];//手上手牌最多27张
		int rival_out_card[8][2];//对手最多出8张牌
		cin >> times >> level1;
		level = change_to_num(level1, 0);
		cin.clear();
		//初始化
		for (int i = 1; i <= times; i++)
		{
			for (int j = 0; j < 27; j++)
				for (int k = 0; k < 2; k++)
					card_on_hand[j][k] = -1;
			for (int j = 0; j < 8; j++)
				for (int k = 0; k < 2; k++)
					rival_out_card[j][k] = -1;

			cin >> n >> m;
			cin.clear();
			for (int i = 0; i < n; i++) {
				cin >> card;
				card_on_hand[i][0] = change_to_num(card, 0);
				card_on_hand[i][1] = change_to_num(card, 1);
			}
			if (m > 0) {
				for (int i = 0; i < m; i++) {
					cin >> card;
					rival_out_card[i][0] = change_to_num(card, 0);
					rival_out_card[i][1] = change_to_num(card, 1);
				}
			}
#ifdef DEBUG
			for (int i = 0; i < n; i++) {
				cout << endl;
				for (int j = 0; j < 2; j++)
					cout << card_on_hand[i][j] << "  ";
			}
			system("cls");
#endif
			judge(card_on_hand, rival_out_card, n, m, level,times);
		}//判断并输出最小且张数最多的牌
		return 0;
}*/