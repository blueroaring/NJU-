#include "print_card.h"
int find_bomb(int(*temp)[2], int(*hand)[2], int n, int level, int type) {
	int i, j, k, t, d1 = 4, d2 = 8;//默认张数为4，找最小炸弹
    int base[15][2];
	hand_count(base, hand, n, level);
    if (type == 3)
    {
        if (base[13][1] == 2 && base[14][1] == 2) //四大天王
        {
            t = 0;
            for (k = 0; k < n; k++)
                if (hand[k][0] == 13 || hand[k][0] == 14)
                {
                    temp[t][0] = hand[k][0];
                    temp[t][1] = hand[k][1];
                    hand[k][1] = 5;
                    t++;
                }
            return 4;  //炸弹张数
        }
        else
            return 0;
    }
    //默认是找出最小炸弹
    d1 = 4;
    d2 = 8;
    if (type == 1) //找张数5的炸弹
    {
        d1 = 5;
        d2 = 5;
    }
    if (type == 2) //找张数超过5的炸弹
    {
        d1 = 6;
        d2 = 8;
    }
    if (type == 7) //找张数超过6的炸弹
    {
        d1 = 7;
        d2 = 8;
    }
    if (type == 8) //找张数超过7的炸弹
    {
        d1 = 8;
        d2 = 8;
    }
    for (i = d1; i <= d2; i++)
        for (j = 0; j < 13; j++)
            if (base[j][1] == i)
            {
                t = 0;
                for (k = 0; k < n; k++)
                    if (hand[k][0] == base[j][0])
                    {
                        temp[t][0] = hand[k][0];
                        temp[t][1] = hand[k][1];
                        hand[k][1] = 5;
                        t++;
                    }
                return i; ////炸弹张数
            }
    if (type == 0)
        if (base[13][1] == 2 && base[14][1] == 2) //四大天王
        {
            t = 0;
            for (k = 0; k < n; k++)
                if (hand[k][0] == 13 || hand[k][0] == 14)
                {
                    temp[t][0] = hand[k][0];
                    temp[t][1] = hand[k][1];
                    hand[k][1] = 5;
                    t++;
                }
            return 4;  //炸弹张数
        }
    return 0;
}