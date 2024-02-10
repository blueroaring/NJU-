#include "print_card.h"
void get_small_double_three(int(*hand)[2], int(*play)[2], int n, int m, int level) {//二连三
	int face;
	int temp[8][2];
     int base[15][2];
    if (n > 0 && n < 6)
    {
        int j = 0;
        j = find_bomb(temp, hand, n, level, 0);
        if (j)
        {
            out_card(temp, hand, j, n);
            return;
        }
        pass(hand, n);
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        temp[i][0] = -1;
        temp[i][1] = -1;
    }
    face = play[0][0];
    hand_count(base, hand, n, level);
    non_level_base(base, level); 
    for (int i = 0; i < 12; i++)
        if (base[i][1] == 3 && base[i + 1][1] == 3 && base[i + 1][0] > face)
        {
            int k = 0;
            for (int j = 0; j < n; j++)
            {
                if (hand[j][0] == base[i + 1][0])
                {
                    temp[k][0] = hand[j][0];
                    temp[k][1] = hand[j][1];
                    hand[j][1] = 5;
                    k++;
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (hand[j][0] == base[i][0])
                {
                    temp[k][0] = hand[j][0];
                    temp[k][1] = hand[j][1];
                    hand[j][1] = 5;
                    k++;
                }
            }
            out_card(temp, hand, 6, n);
            return;
        }
    //没有可用二连三,出炸弹
    int j = 0;
    j = find_bomb(temp, hand, n, level, 0);
    if (j)
    {
        out_card(temp, hand, j, n);
        return;
    }
    pass(hand, n);
}