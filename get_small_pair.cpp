#include "print_card.h"
void get_small_pair(int(*hand)[2], int(*play)[2], int n, int m, int level) {//����
    int base[15][2];
    int i, j, k, face;
	int temp[8][2];
    int bomb[1][2];
    int king[4][2];
    int hand_temp[27][2];
	if (n >= 0 && n < 2) {//�鲻������
        pass(hand, n);
		return;
	}
	for (i = 0; i < 8; i++) {
		temp[i][0] = -1;
		temp[i][1] = -1;
	}
	for (i = 0; i < 27; i++)
	{
		hand_temp[i][0] = -1;
		hand_temp[i][1] = -1;
	}
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			king[i][j] = -1;
	for (j = 0; j < 2; j++)
		bomb[0][j] = -1;
	hand_count(base, hand, n, level);
	deal_bomb(base, bomb, king, hand, hand_temp, n);
	//�ҳ���Сը��,�Ĵ�����,���ɳ�ը�������ʱ����hand_temp�����ã�
	face = play[0][0];
	hand_count(base, hand_temp, n, level);
	if (face != level && face != 13&&face!=14)//�ϼ�����ͨ��,�����
	{
        for (i = 0; i < 15; i++)
            if (base[i][1] == 2 && base[i][0] > face
                || base[i][1] == 2 && base[i][0] == level) //������
            {
                k = 0;
                for (j = 0; j < n; j++)
                    if (hand[j][0] == base[i][0])
                    {
                        temp[k][0] = hand[j][0];
                        temp[k][1] = hand[j][1];
                        hand[j][1] = 5;
                        k++;
                    }
                out_card(temp, hand, 2, n);
                return;
            }
        for (i = 0; i < 15; i++)
            if (base[i][1] > 2 && base[i][0] > face ||
                base[i][1] > 2 && base[i][0] == level)  //����
            {
                k = 0;
                for (j = 0; j < n; j++)
                    if (hand[j][0] == base[i][0] && k < 2)//��ǰ������
                    {
                        temp[k][0] = hand[j][0];
                        temp[k][1] = hand[j][1];
                        hand[j][1] = 5;
                        k++;
                    }
                out_card(temp, hand, 2,n);
                return;
            }
	}
    if (face == level || face == 13) //�ϼ��������ż��ƻ�С��,����ܵ�����
    {
        for (j = 13; j <= 14; j++)
            if (base[j][1] == 2 && base[j][0] > face)
            {
                k = 0;
                for (i = 0; i < n; i++)
                    if (hand[i][0] == j)
                    {
                        temp[k][0] = hand[i][0];
                        temp[k][1] = hand[i][1];
                        hand[i][1] = 5;
                        k++;
                    }
                out_card(temp, hand, 2, n);
                return;
            }
    }
    j = find_bomb(temp, hand, n, level, 0);
    if (j)
    {
        out_card(temp, hand, j, n);
        return;
    }
    pass(hand, n);
}