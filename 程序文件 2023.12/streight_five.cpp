#include "print_card.h"
#include<iostream>
using namespace std;
bool find_streight_five(int(*temp_base)[2], int(*streight_five)[2])//找一个和找全部通用
{
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
                        if (card_type(temp, 5) == 8)
                        {
                            for (k = 0; k < 5; k++)
                            {
                                streight_five[k][0] = temp[k][0];
                                streight_five[k][1] = temp[k][1];
                            }
                            return true;
                        }
                    }
    return false;
}
int deal_streight_five(int(*base)[2], int(*streight_five)[2], int(*hand_temp)[2], int count, int level)
{
    int t;
    bool found, found8, exist;
    int temp[5][2];
    int temp_base[15][2];
    for (int i = 0; i < 5; i++)//初始化
    {
        temp[i][0] = -1;
        temp[i][1] = -1;
    }
    for (int i = 0; i < 15; i++)
    {
        temp_base[i][0] = -1;
        temp_base[i][1] = -1;
    }
    found8 = false;
    for (int i = 0; i < 9; i++)  // 找到最小同花顺,写入streight_five
    {
        if (found8)
            break;
        found = true;
        for (int j = i; j <= 4 + i; j++)  //从最小开始
            if (base[j][1] == 0)
                found = false;
        if (found)
        {
            t = 0;
            for (int j = 0; j < 5; j++) //按从大到小（从后向前）将比较元素写入temp_base3×5（大于等于4张已经被炸弹删除了）
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
                t = 3 * (j + 1);  //重置3*t的位置，0,3，6,9,12行
            }
            found8 = find_streight_five(temp_base, streight_five);//判断顺子是不是同花顺，是的话存进去
        }
    }
    /*将所有是同花顺的数据从临时表hand_temp删除,从最大开始
    如果删除后需要重新开始下一次查询和删除,直到找完退出*/
    exist = true;
    while (exist && count >= 5)
    {
        hand_count(base, hand_temp, count, level);
        non_level_base(base, level);
        for (int i = 0; i < 9; i++)
        {
            found = true;
            for (int j = 12 - i; j >= 8 - i; j--) //从最大开始
                if (base[j][1] == 0)
                    found = false;
            if (found)
            {
                t = 0;
                for (int j = 0; j < 5; j++) //按从大到小将比较元素写入temp_base 4*5
                {
                    for (int k = 0; k < count; k++)
                    {
                        if (hand_temp[k][0] == base[12 - j - i][0])
                        {
                            temp_base[t][0] = hand_temp[k][0];
                            temp_base[t][1] = hand_temp[k][1];
                            t++;//多张点数相同的牌
                        }
                    }
                    t = 3 * (j + 1);  //保证每个元素占用4个空间
                }
                found8 = find_streight_five(temp_base, streight_five);
                if (found8)//如果是同花顺
                {
                    for (int j = 0; j < 5; j++)  //删除一组同花顺
                    {
                        for (int k = 0; k < count; k++)
                            if (hand_temp[k][0] == streight_five[j][0])
                            {
                                for (t = k + 1; t < count; t++)//后面牌往前移冒泡，cnt--
                                {
                                    hand_temp[t - 1][0] = hand_temp[t][0];
                                    hand_temp[t - 1][1] = hand_temp[t][1];
                                }
                                count--;
                                break; //只删除5张每个点数的第一张牌
                            }
                    }
                    break;//跳出i循环，重新重置寻找同花顺
                }
            }
            if (i == 8)
                exist = false;//找不到了，控制跳出while循环
        }
    }
    return count;
}