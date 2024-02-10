#include "print_card.h"
void get_small_three(int(*hand)[2], int(*play)[2], int n, int m, int level)//ÈýÍ¬ÕÅ 
{
	int face;
    int base[15][2];
	int temp[8][2];
	if (n >= 0 && n < 3) {
		pass(hand, n);
		return;
	}
	for (int i = 0; i < 8; i++) {
		temp[i][0] = -1;
		temp[i][1] = -1;
	}
	hand_count(base, hand, n, level);
	face = play[0][0];
	if(face!=level)
		for(int i=0;i<13;i++)
			if ((base[i][0] > face || base[i][0] == level) && base[i][1] == 3) {
				int k = 0;
				for (int j = 0; j < n; j++) 
					if (hand[j][0] == base[i][0]) {
						temp[k][0] = hand[j][0];
						temp[k][1] = hand[j][1];
						hand[j][1] = 5;
						k++;

					}
				
				out_card(temp, hand, 3, n);
				return;
			}
	int j = 0;
	j = find_bomb(temp, hand, n, level, 0);
	if (j)
	{
		out_card(temp, hand, j, n);
		return;
	}
	pass(hand, n);
}