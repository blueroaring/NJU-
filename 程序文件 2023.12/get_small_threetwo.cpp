#include "print_card.h"
void get_small_three_two(int(*hand)[2], int(*play)[2], int n, int m, int level) {
    int base[15][2];
	int face;
	int temp[8][2];
    if (n > 0 && n < 5)
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
    for (int i = 0; i < 13; i++)  //遍历base数
    {
        if (base[i][1] == 3 && base[i][0] > face)
            for (int j = 0; j < 15; j++)
                if (base[j][1] == 2)
                {
                    if (j == 13 && base[j + 1][1] == 2)
                        break;//保留四大天王
                    int t = 0;
                    for (int k = 0; k < n; k++)
                    {
                        if (hand[k][0] == base[i][0])
                        {
                            temp[t][0] = hand[k][0];
                            temp[t][1] = hand[k][1];
                            hand[k][1] = 5;
                            t++;
                        }
                    }
                    for (int k = 0; k < n; k++)
                    {
                        if (hand[k][0] == base[j][0])
                        {
                            temp[t][0] = hand[k][0];
                            temp[t][1] = hand[k][1];
                            hand[k][1] = 5;
                            t++;
                        }
                    }
                    out_card(temp, hand, 5, n);
                    return;
                }
    }
        for (int i = 0; i < 13; i++)  //遍历base数
        {
            if (base[i][1] == 3 && base[i][0] > face)
                for (int j = 0; j < 13; j++)
                    if (base[j][1] > 2 && base[j][1] < 4 && base[j][0] != base[i][0]) //拆张
                    {
                        int t = 0;
                        for (int k = 0; k < n; k++)
                        {
                            if (hand[k][0] == base[i][0])
                            {
                                temp[t][0] = hand[k][0];
                                temp[t][1] = hand[k][1];
                                hand[k][1] = 5;
                                t++;
                            }
                        }
                        int d = 0;
                        for (int k = 0; k < n; k++)
                        {
                            if (hand[k][0] == base[j][0] && d < 2)
                            {
                                temp[t][0] = hand[k][0];
                                temp[t][1] = hand[k][1];
                                hand[k][1] = 5;
                                t++;
                            }
                        }
                        out_card(temp, hand, 5, n);
                        return;
                    }
        }
    
    //没有可用三带二,出炸弹
    int j = 0;
    j = find_bomb(temp, hand, n, level, 0);
    if (j)
    {
        out_card(temp, hand, j, n);
        return;
    }
    pass(hand, n);
}