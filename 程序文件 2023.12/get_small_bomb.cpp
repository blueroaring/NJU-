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
    hand_count(base, hand, n, level);//ը����������ԭ����
    if (n > 0 && n < 4)
    {
        pass(hand, n);
        return;
    }
    if (m >= 4 && m <= 8) //�ҳ�m�Ŵ���face��ը��/5������ը��/ͬ��˳/����5������ը��/�Ĵ�����
    {
        if (face != level)//�������õ�(�������Ĵ�����)
        {
            j = 0;
            j = judge_bomb(temp, hand, n, m, level, face);  //m�Ŵ���face��ը��
            if (j)
            {
                out_card(temp, hand, j, n);
                return;
            }
        }
        j = 0;//�Ҳ������õ�
        if (m == 4)
        {
            j = find_bomb(temp, hand, n, level, 1); //5������ը��
            if (j)
            {
                out_card(temp, hand, j, n);
                return;
            }
        }//û��5�ţ��ж�ͬ��˳
        if (m == 4 || m == 5)
        {
            //����Ϊ�ж�ͬ��˳
            non_level_base(base, level); //��������ԭ��ԭ��λ��,���ҳ�ͬ��˳
            for (int i = 0; i < 9; i++)  //����base��
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
            j = find_bomb(temp, hand, n, level, 2); //�������ŵ�ը��
            if (j)
            {
                out_card(temp, hand, j, n);
                return;
            }
        }
        if (m == 6 || m == 7) {
            j = 0;
            j = find_bomb(temp, hand, n, level, m + 1); //����6/7�ŵ�ը��
            if (j)
            {
                out_card(temp, hand, j, n);
                return;
            }
        }
            j = 0;//ɶҲ�Ҳ���
            j = find_bomb(temp, hand, n, level, 3); //�Ĵ�����
            if (j)
            {
                out_card(temp, hand, 4, n);
                return;
            }
        
    }
    pass(hand, n);
    return;
}