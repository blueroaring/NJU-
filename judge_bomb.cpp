#include "print_card.h"
int judge_bomb(int(*temp)[2], int(*hand)[2], int n, int m, int level, int face) {//找到张数等于m,大于face的炸弹
    int hand_temp[27][2];
    int base[15][2];
    int bomb[1][2];
    int king[2][2];
    int streight_five[5][2];
    int five[5][2];
    int threetwo[5][2];
    int doublethree[6][2];
    int samethree[3][2];
    int threepair[6][2];
    int pairs[2][2];
    int single[1][2];
    int run[7][2];
    int i, j, k;
	int base1[15][2];
	hand_count(base1, hand, n, level);
    for (i = 0; i < 13; i++)
        if (base1[i][1] == m && (base1[i][0] > face || base1[i][0] == level))
        {
            j = 0;
            for (k = 0; k < n; k++)
                if (hand[k][0] == base1[i][0])
                {
                    temp[j][0] = hand[k][0];
                    temp[j][1] = hand[k][1];
                    hand[k][1] = 5;
                    j++;
                }
            return j; //炸弹张数
        }
    return 0;
}