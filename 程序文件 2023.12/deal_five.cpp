#include "print_card.h"
void deal_five(int(*base)[2], int(*five)[2], int(*hand_temp)[2], int count) {
	bool found;
	int temp[5][2];
	int temp_base[15][2];
	void find_five(int(*temp_base)[2], int(*five)[2]);
    for (int i = 0; i < 5; i++)
    {
        temp[i][0] = -1;
        temp[i][1] = -1;
    }
    for (int i = 0; i < 15; i++)
    {
        temp_base[i][0] = -1;
        temp_base[i][1] = -1;
    }
    for (int i = 0; i < 9; i++)  // 找到最小顺子,写入five
    {
        found = true;
        for (int j = i; j <= 4 + i; j++)  //从最小开始
            if (base[j][1] == 0)
                found = false;
        if (found)
        {
            int t = 0;
            for (int j = 0; j < 5; j++) //按从大到小将比较元素写入temp_base 3*5(和同花顺一样)
            {
                for (int k = 0; k < count; k++)
                {
                    if (hand_temp[k][0] == base[4 + i - j][0])
                    {
                        temp_base[t][0] = hand_temp[k][0];
                        temp_base[t][1] = hand_temp[k][1];
                        t++;
                    }
                }
                t = 3 * (j + 1);
            }
            find_five(temp_base, five);
            break;
        }
    }
}
void find_five(int(*temp_base)[2], int(*five)[2]) {
    int temp[5][2];
    int num[5];
    for (int i = 0; i < 5; i++)//初始化
    {
        temp[i][0] = -1;
        temp[i][1] = -1;
    }
    for (int i = 0; i < 5; i++)
        num[i] = 0;
    for (int i = 0; i < 15; i++)
        if (temp_base[i][0] != -1)
            num[i / 3] += 1;
    for (int i = 0; i < num[0]; i++)//所有排列组合
        for (int j = 0; j < num[1]; j++)
            for (int k = 0; k < num[2]; k++)
                for (int t = 0; t < num[3]; t++)
                    for (int d = 0; d < num[4]; d++)
                    {
                        temp[0][0] = temp_base[i][0];
                        temp[0][1] = temp_base[i][1];
                        temp[1][0] = temp_base[j + 3][0];
                        temp[1][1] = temp_base[j + 3][1];
                        temp[2][0] = temp_base[k + 6][0];
                        temp[2][1] = temp_base[k + 6][1];
                        temp[3][0] = temp_base[t + 9][0];
                        temp[3][1] = temp_base[t + 9][1];
                        temp[4][0] = temp_base[d + 12][0];
                        temp[4][1] = temp_base[d + 12][1];
                        if (card_type(temp, 5) == 7)
                        {
                            for (k = 0; k < 5; k++)
                            {
                                five[k][0] = temp[k][0];
                                five[k][1] = temp[k][1];
                            }
                            return;
                        }
                    }
    return;
}
