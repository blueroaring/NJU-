#include "print_card.h"
void get_small_three_pair(int(*hand)[2], int(*play)[2], int n, int m, int level) {//三连二
    int base[15][2];
    bool found = true;
    int temp[8][2];
    if (n < 6) //小于6直接炸弹
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
    else
    {
       int face = play[0][0];
        hand_count(base, hand, n, level);
        non_level_base(base, level);
        for (int i = 0; i < 10; i++) {//找三连对(本身有的)
            found = true;
            for(int j=i;j<3+i;j++)
                if (base[j][1] != 2)
                {
                    found = false;
                    break;
                }
            if (found && base[2 + i][0] > face) {//最大点数比较
                int t = 0;
                for (int j = 2 + i; j >= i; j--)//从大到小
                {
                    for(int k=0;k<n;k++)
                        if (hand[k][0] == base[j][0]) {
                            temp[t][0] = hand[k][0];
                            temp[t][1] = hand[k][1];
                            hand[k][1] = 5;
                            t++;
                        }
                }
                out_card(temp, hand, 6, n);
                return;
            }
        } 
        for (int i = 0; i < 10; i++)//拆牌
        {
            found = true;
            for(int j=i;j<i+3;j++)
                if(base[j][1]<2||base[j][1]>=4)//是炸弹或不够
                {
                    found = false;
                    break;
                }
            if (found && base[2 + i][0] > face) {
                int t = 0;
                for (int j = 2 + i; j >= i; j--) {
                    int s = 0;
                    for(int k=0;k<n;k++)
                        if (hand[k][0] == base[j][0] && s < 2) {
                            temp[t][0] = hand[k][0];
                            temp[t][1] = hand[k][1];
                            hand[k][1] = 5;
                            t++;
                            s++;
                        }
                }
                out_card(temp, hand, 6, n);
                return;
            }
        }
        //没招出炸弹
        int j = 0;
        j = find_bomb(temp, hand, n, level, 0);
        if (j)
        {
            out_card(temp, hand, j, n);
            return;
        }
        pass(hand, n);
    }

}