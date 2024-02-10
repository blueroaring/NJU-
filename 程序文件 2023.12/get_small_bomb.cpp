#include "print_card.h"
void get_small_bomb(int(*hand)[2], int(*play)[2], int n, int m, int level) {
    int base[15][2];
	int face,j;
	int temp[8][2];
	bool found;
    for (int i = 0; i < 8; i++)
    {
        temp[i][0] = -1;
        temp[i][1] = -1;
    }
    face = play[0][0];
    hand_count(base, hand, n, level);//炸弹不用做还原级牌
    if (n > 0 && n < 4)
    {
        pass(hand, n);
        return;
    }
    if (m >= 4 && m <= 8) //找出m张大于face的炸弹/5张任意炸弹/同花顺/大于5张任意炸弹/四大天王
    {
        if (face != level)//先找正好的(不包括四大天王)
        {
            j = 0;
            j = judge_bomb(temp, hand, n, m, level, face);  //m张大于face的炸弹
            if (j)
            {
                out_card(temp, hand, j, n);
                return;
            }
        }
        j = 0;//找不到正好的
        if (m == 4)
        {
            j = find_bomb(temp, hand, n, level, 1); //5张任意炸弹
            if (j)
            {
                out_card(temp, hand, j, n);
                return;
            }
        }//没有5张，判断同花顺
        if (m == 4 || m == 5)
        {
            //以下为判断同花顺
            non_level_base(base, level); //将级数还原到原来位置,以找出同花顺
            for (int i = 0; i < 9; i++)  //遍历base数
            {
                found = true;
                for (j = i; j <= 4 + i; j++)
                    if (base[j][1] != 1)
                        found = false;
                if (found)
                {
                    int k = 0;
                    for (j = 4 + i; j >= i; j--)
                    {
                        temp[k][0] = base[j][0];
                        temp[k][1] = base[j][1]-1;
                        k++;
                    }
                    int t = card_type(temp, 5);
                    if (t == 8)
                    {
                        for (int j = 0; j < k; j++) {
                            for (int i = 0; i < n; i++)
                                if (hand[i][0] == temp[j][0]) {
                                    hand[i][1] = 5;
                                }
                        }
                        out_card(temp, hand, 5, n);
                        return;
                    }
                }
            }
            j = 0;
            j = find_bomb(temp, hand, n, level, 2); //大于五张的炸弹
            if (j)
            {
                out_card(temp, hand, j, n);
                return;
            }
        }
        if (m == 6 || m == 7) {
            j = 0;
            j = find_bomb(temp, hand, n, level, m + 1); //大于6/7张的炸弹
            if (j)
            {
                out_card(temp, hand, j, n);
                return;
            }
        }
            j = 0;//啥也找不到
            j = find_bomb(temp, hand, n, level, 3); //四大天王
            if (j)
            {
                out_card(temp, hand, 4, n);
                return;
            }
        
    }
    pass(hand, n);
    return;
}