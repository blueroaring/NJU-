#include "print_card.h"
void get_small_five(int(*hand)[2], int(*play)[2], int n, int m, int level) {
    int base[15][2];
	int face;
	int temp[8][2];
	bool found = true;
    if (n > 0 && n < 5)
    {
        int j = 0;
        j = find_bomb(temp, hand, n, level, 0);
        if (j && (card_type(play, m) == 7 || (card_type(play, m) == 8 && temp[0][1] == 4))) //普通顺子用炸弹,同花顺用四大天王
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
    for (int i = 0; i < 9; i++)  //遍历base数
    {
        if (base[4 + i][0] > face)
        {
            found = true;
            for (int j = i; j <= 4 + i; j++)
                if (base[j][1] < 1)
                    found = false;
            if (found)
            {
                int t = 0,k;
                for (int j = 4 + i; j >= i; j--)
                    for ( k = 0; k < n; k++)
                        if (hand[k][0] == base[j][0])
                        {
                            temp[t][0] = hand[k][0];
                            temp[t][1] = hand[k][1];
                            t++;
                            break;
                        }
                k = card_type(play, 5);
                t = card_type(temp, 5);
                if (k == t)//类型匹配成功
                {
                    for (int j = 0; j < 5; j++)
                        for (k = 0; k < n; k++)
                            if (hand[k][0] == temp[j][0])
                            {
                                hand[k][1] = 5;
                                break;
                            }
                    out_card(temp, hand, 5, n);
                    return;
                }
            }
        }
    }
    //没有可用顺子,出炸弹
    int k = card_type(play, 5);
    if (k == 7)
    {
        int j = 0;
        j = find_bomb(temp, hand, n, level, 0);
        if (j)
        {
            out_card(temp, hand, j, n);
            return;
        }
    }
    else if (k == 8)
    {
        int j = 0;
        j = find_bomb(temp, hand, n, level, 2); //大于五张的炸弹
        if (j)
        {
            out_card(temp, hand, j, n);
            return;
        }
        j = 0;
        j = find_bomb(temp, hand, n, level, 3); //四大天王
        if (j)
        {
            out_card(temp, hand, 4, n);
            return;
        }
    }
    pass(hand, n);
    
}