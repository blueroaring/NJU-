#include "print_card.h"
#define NDEBUG
#include<iostream>
#include<graphics.h>
#include <conio.h>
#include <time.h>
#include<easyx.h>
#include<string.h>
using namespace std;
int count1;
int hand_temp[27][2];
int base[15][2];
int bomb[1][2];
int king[4][2];
int streight_five[5][2];
int five[5][2];
int threetwo[5][2];
int doublethree[6][2];
int samethree[3][2];
int threepair[6][2];
int pairs[2][2];
int single[1][2];
int run[7][2];
int MAX_LEN1 = 8;
int MAX_LEN2 = 27;
void delete_card(int(*hand)[2], int(*play)[2], int n, int m, int level) {
	bool found, found7, found8;
	int face;
	bool exist;
	if (m == 0) {
		for (int i = 0; i < 27; i++) {//��ʼ��
			hand_temp[i][0] = -1;//ɾ��ը��˳�Ӻ����
			hand_temp[i][1] = -1;
		}
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				king[i][j] = -1;//�Ĵ�����
		bomb[0][0] = -1;//ը��
		bomb[0][1] = -1;
		for (int i = 0; i < 5; i++) {
			streight_five[i][0] = -1;
			streight_five[i][1] = -1;//ͬ��˳
			five[i][0] = -1;
			five[i][1] = -1;//��ͨ˳��
			threetwo[i][0] = -1;
			threetwo[i][1] = -1;//������
		}
		for (int i = 0; i < 6; i++) {
			doublethree[i][0] = -1;
			doublethree[i][1] = -1;//������
			threepair[i][0] = -1;
			threepair[i][1] = -1;//������
		}
		for (int i = 0; i < 3; i++) {
			samethree[i][0] = -1;
			samethree[i][1] = -1;//��ͬ��
		}
		for (int i = 0; i < 2; i++) {
			pairs[i][0] = -1;
			pairs[i][1] = -1;//����
		}
		single[0][0] = -1;
		single[0][1] = -1;//����
		found = false;
		hand_count(base, hand, n, level); //������
		//�ҳ���Сը��,�Ĵ�����,���ɳ�ը�������ʱ����hand_temp
		count1 = deal_bomb(base, bomb, king, hand, hand_temp, n);
		if (count1 >= 5){ //�ҳ���Сͬ��˳,ɾ������ͬ��˳��������ʱ��hand_temp 
			hand_count(base, hand_temp, count1, level);
			non_level_base(base, level);//ȡ�����ƣ���Ϊ��ͨ����
			count1 = deal_streight_five(base, streight_five, hand_temp, count1, level);
		}
	}
}
extern void find_min(int(*hand)[2], int(*play)[2], int n, int m, int level) {//ʣ�µĲ����ͻ
	if (m == 0) {
		if (count1 >= 5) {//��hand_temp�ҳ���С˳��
			hand_count(base, hand_temp, count1, level);
			non_level_base(base, level);
			deal_five(base, five, hand_temp, count1);
		}
		if (count1 >= 5) {//��hand_temp�ҳ���С��������
			hand_count(base, hand_temp, count1, level);
			bool found = false;
			for (int i = 0; i < 15; i++)//��������
				if (!found)
					if (base[i][1] == 3)//��
						for (int j = 0; j < 15; j++)
							if (base[j][1] == 2) {    //����
								int t = 0;
								for (int k = 0; k < count1; k++)
									if (hand_temp[k][0] == base[i][0]) {//��������������
										threetwo[t][0] = hand_temp[k][0];
										threetwo[t][1] = hand_temp[k][1];
										t++;
									}
								for (int k = 0; k < count1; k++)
									if (hand_temp[k][0] == base[j][0]) {
										threetwo[t][0] = hand_temp[k][0];
										threetwo[t][1] = hand_temp[k][1];
										t++;
									}
								found = true;
								break;
							}
#ifdef DEBUG
			cout << "��С������";
			for (i = 0; i < 5; i++)
			{
				cout << threetwo[i][0] << "," << threetwo[i][1] << " ";
			}
			cout << "��" << count1 << "����" << endl;
#endif					
		}
		if (count1 >= 6) //��hand_temp�ҳ���С�Ķ�����
		{
			hand_count(base, hand_temp, count1, level);
			non_level_base(base, level);
			for (int i = 0; i < 12; i++)
				if (base[i][1] == 3 && base[i + 1][1] == 3)
				{
					int k = 0;
					for (int j = 0; j < count1; j++)
					{
						if (hand_temp[j][0] == base[i + 1][0])//�Ӵ���С��
						{
							doublethree[k][0] = hand_temp[j][0];
							doublethree[k][1] = hand_temp[j][1];
							k++;
						}
					}
					for (int j = 0; j < count1; j++)
					{
						if (hand_temp[j][0] == base[i][0])
						{
							doublethree[k][0] = hand_temp[j][0];
							doublethree[k][1] = hand_temp[j][1];
							k++;
						}
					}
				}
#ifdef DEBUG
			cout << "��С������";
			for (i = 0; i < 6; i++)
			{
				cout << doublethree[i][0] << "," << doublethree[i][1] << " ";
			}
			cout << "��" << count1 << "����" << endl;
#endif
		}
		if (count1 >= 3) //��С��ͬ��
		{
			hand_count(base, hand_temp, count1, level);
			for (int i = 0; i < 13; i++)
				if (base[i][1] == 3)
				{
					int k = 0;
					for (int j = 0; j < count1; j++)
						if (hand_temp[j][0] == base[i][0])
						{
							samethree[k][0] = hand_temp[j][0];
							samethree[k][1] = hand_temp[j][1];
							k++;
						}
					break;
				}
#ifdef DEBUG
			cout << "��С��ͬ��";
			for (i = 0; i < 3; i++)
				cout << samethree[i][0] << "," << samethree[i][1] << " ";
			cout << "��" << count1 << "����" << endl;
#endif
		}
		if (count1 >= 6) //��С������
		{
			int d, j;
			hand_count(base, hand_temp, count1, level);
			non_level_base(base, level);
			for (int i = 0; i < 11; i++) //��������
			{
				bool found = true;
				for (j = i; j < 3 + i; j++)
					if (base[j][1] < 2)
					{
						found = false;
						break;
					}
				if (found)
				{
					int t = 0;
					for (j = 2 + i; j >= i; j--) //�Ӵ�С
						d = 0;
					for (int k = 0; k < count1; k++)
						if (d < 2)
						{
							if (hand_temp[k][0] == base[j][0])
							{
								threepair[t][0] = hand_temp[k][0];
								threepair[t][1] = hand_temp[k][1];
								t++;
								d++;
							}
						}
					break;
				}
			}
#ifdef DEBUG
			cout << "��С������";
			for (i = 0; i < 6; i++)
				cout << threepair[i][0] << "," << threepair[i][1] << " ";
			cout << "��" << count1 << "����" << endl;

#endif
		}
		if (count1 >= 2) //����
		{
			hand_count(base, hand_temp, count1, level);
			for (int i = 0; i < 15; i++)
				if (base[i][1] == 2)
				{
					int k = 0;
					for (int j = 0; j < count1; j++)
						if (hand_temp[j][0] == base[i][0])
						{
							pairs[k][0] = hand_temp[j][0];
							pairs[k][1] = hand_temp[j][1];
							k++;
						}
					break;
				}
#ifdef DEBUG
			cout << "��С����:" << pairs[0][0] << "," << pairs[0][1] << " " << pairs[1][0] << "," << pairs[1][1] << " ";
			cout << "��" << count1 << "����" << endl;
#endif
		}
		if (count1 >= 1) //����
		{
			hand_count(base, hand_temp, count1, level);
			for (int i = 0; i < 15; i++)
				if (base[i][1] == 1)
				{
					for (int j = 0; j < count1; j++)
						if (hand_temp[j][0] == base[i][0])
						{
							single[0][0] = hand_temp[j][0];
							single[0][1] = hand_temp[j][1];
						}
					break;
				}

		}
		
	}
}
//�����߼�:��С(����,����,������,��ͬ��,������,������,˳��),ͬ��˳/ը���Ƚ�,�Ĵ�����
	   // single[0][0] pairs[0][0] threepair[5][0] samethree[0][0] doublethree[5][0] threetwo[0][0] five[4][0]
void run_card(int(*hand)[2], int(*play)[2], int n, int m, int level) {
	int t,k;
	int temp[8][2];
	for (int i = 0; i < 7; i++) {//��ʼ��
		run[i][0] = -1;
	}
	run[0][0] = single[0][0];//����
	run[0][1] = 1;
	run[1][0] = pairs[0][0];//����
	run[1][1] = 2;
	run[2][0] = threepair[5][0];//������
	run[2][1] = 6;
	run[3][0] = samethree[0][0];//��ͬ��
	run[3][1] = 3;
	run[4][0] = doublethree[5][0];//������
	run[4][1] = 6;
	run[5][0] = threetwo[0][0];//������
	run[5][1] = 5;
	run[6][0] = five[4][0];//˳��
	run[6][1] = 5;
	k = -1;
	for (int i = 0; i < 7; i++) {
		if (run[i][0] != -1)
		{
			temp[0][0] = run[i][0];//����
			temp[0][1] = run[i][1];
			k = i;
		}
	}
	

	for (int i = 1; i < 7; i++)
		if (run[i][0] != -1)
			if (run[i][0] < temp[0][0] ||
				(run[i][0] == temp[0][0] && run[i][1] > temp[0][1])) {
				temp[0][0] = run[i][0];
				temp[0][1] = run[i][1];
				k = i;
			}//ð�ݻ���Ƚϣ��ҳ���С�ĵ���,����k��switch
	for (int i = 0; i < 8; i++) {
		temp[i][0] = -1;
		temp[i][1] = -1;//���³�ʼ��
	}
	switch (k) {//֮ǰ�ж�ʱ�Ѿ��ų���ը����ͬ��˳��������hand�ж�һ��������Ӱ�쵽����
	case 0://����
		temp[0][0] = single[0][0];
		temp[0][1] = single[0][1];//����,ͳһ��(�����꼰�޹���
		for (int i = 0; i < n; i++)//�жϣ�ͨ����������5�ﵽ��ɾ����Ч��,����ͬ��
			if (hand[i][0] == single[0][0] && hand[i][1] == single[0][1]) {
				hand[i][1] = 5;//û�����⣬��Ϊ�����һģһ���ľͲ����ж�Ϊ������
				break;
			}
		out_card(temp, hand, 1, n);		
		return;//���ټ���,����һ��
		break;//����switch
	case 1: //����
		for (int i = 0; i < 2; i++)
		{
			temp[i][0] = pairs[i][0];
			temp[i][1] = pairs[i][1];
		}
		t = 0;
		for (int j = 0; j < n; j++)
			if (hand[j][0] == pairs[0][0] && t < 2)//ȡǰ����
			{
				hand[j][1] = 5;
				t++;
			}
		out_card(temp, hand, 2, n);
		return;
		break;
	case 2: //,������
		for (int i = 0; i < 6; i++)
		{
			temp[i][0] = threepair[i][0];
			temp[i][1] = threepair[i][1];
		}
		for (int i = 0; i < 6; i += 2)
		{
			t = 0;
			for (int j = 0; j < n; j++)
				if (hand[j][0] == threepair[i][0] && t < 2)//ȡǰ����
				{
					hand[j][1] = 5;
					t++;
				}
		}
		out_card(temp, hand, 6, n);
		return;
		break;
	case 3: //��ͬ��,�������ÿ���ը�������У���Ϊը��һ����������
		for (int i = 0; i < 3; i++)
		{
			temp[i][0] = samethree[i][0];
			temp[i][1] = samethree[i][1];
		}
		for (int j = 0; j < n; j++)
			if (hand[j][0] == samethree[0][0]) //����һ������ȡһ��(����ȥ�������ȡ��ɫ��С��)
			{
				hand[j][1] = 5;
			}
		out_card(temp, hand, 3, n);
		return;
		break;
	case 4: //������
		for (int i = 0; i < 6; i++)
		{
			temp[i][0] = doublethree[i][0];
			temp[i][1] = doublethree[i][1];
		}
		for (int i = 0; i < 6; i += 3)
			for (int j = 0; j < n; j++)
				if (hand[j][0] == doublethree[i][0])//ͬ���ģ�ѡ��ǰ���һ��
				{
					hand[j][1] = 5;
				}
		out_card(temp, hand, 6, n);
		return;
		break;

	case 5: //������
		for (int i = 0; i < 5; i++)
		{
			temp[i][0] = threetwo[i][0];
			temp[i][1] = threetwo[i][1];
		}
		for (int i = 0; i < 5; i += 3)
			for (int j = 0; j < n; j++)
				if (hand[j][0] == threetwo[i][0])
				{
					hand[j][1] = 5;
				}
		out_card(temp, hand, 5, n);
		return;
		break;
	case 6: //˳��
		for (int i = 0; i < 5; i++)
		{
			temp[i][0] = five[i][0];
			temp[i][1] = five[i][1];
		}
		for (int i = 0; i < 5; i++)
		{
			t = 0;
			for (int j = 0; j < n; j++)
				if (hand[j][0] == five[i][0] && t < 1)//˳�Ӳ��ܻ�ɫ
				{
					hand[j][1] = 5;
					t++;
				}
		}
		out_card(temp, hand, 5, n);
		return;
		break;
	default:
		break;
	}
	//���ը��(5������)
	if (bomb[0][0] != -1 && bomb[0][1] <= 5)
	{
		int j = 0;
			for (int i = 0; i < n; i++)
				if (hand[i][0] == bomb[0][0])
				{
					temp[j][0] = hand[i][0];
					temp[j][1] = hand[i][1];
					hand[i][1] = 5;
					j++;
				}
		
		out_card(temp, hand, bomb[0][1], n);
		return;
	}
	//���ͬ��˳
	if (streight_five[0][0] != -1 &&( (bomb[0][0] != -1 && bomb[0][1] > 5)||bomb[0][0]==-1))
	{
		int i;
		for (int k = 0; k < 5; k++)
		{
			temp[k][0] = streight_five[k][0];
			temp[k][1] = streight_five[k][1];
		}
		for ( i = 0; i < 5; i++)
		{
			int t = 0;
			for (int j = 0; j < n; j++)
				if (hand[j][0] == streight_five[i][0] && t < 1)
				{
					hand[j][1] = 5;
					t++;
				}
		}
			out_card(temp, hand, 5, n);
			return;
		
		}
	//���ը����5�����ϣ�
	if (bomb[0][1] > 5&&bomb[0][1]<=8)
	{
		int j = 0;
			for (int i = 0; i < n; i++)
				if (hand[i][0] == bomb[0][0])
				{
					temp[j][0] = hand[i][0];
					temp[j][1] = hand[i][1];
					hand[i][1] = 5;
					j++;
				}
		
		out_card(temp, hand, bomb[0][1], n);
		return;
	}
	if (king[0][0] != -1)
	{
		for (int i = 0; i < 2; i++)
		{
			temp[i][0] = king[0][0];
			temp[i][1] = 4;
		}
		for (int j = 2; j < 4; j++)
		{
			temp[j][0] = king[1][0];
			temp[j][1] = 4;
		}
		for (int i = 0; i < 4; i += 2)
			for (int j = 0; j < n; j++)
				if (hand[j][0] == king[i][0])
				{
					hand[j][1] = 5;
				}
		out_card(temp, hand, 4, n);
		return;
	}
		pass( hand, n);
		return;

	}

	
	void out_card(int(*temp)[2], int(*hand)[2], int j, int n)
	{
		IMAGE img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
			b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
			, d10, d11, d12, d13, e1, e2, img57, img58;
		extern void loadimage1(IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & a2, IMAGE & a3, IMAGE & a4, IMAGE & a5, IMAGE & a6, IMAGE & a7, IMAGE & a8, IMAGE & a9, IMAGE & a10,
			IMAGE & a11, IMAGE & a12, IMAGE & a13, IMAGE & b1, IMAGE & b2, IMAGE & b3, IMAGE & b4, IMAGE & b5, IMAGE & b6, IMAGE & b7, IMAGE & b8, IMAGE & b9,
			IMAGE & b10, IMAGE & b11, IMAGE & b12, IMAGE & b13, IMAGE & c1, IMAGE & c2, IMAGE & c3, IMAGE & c4, IMAGE & c5, IMAGE & c6, IMAGE & c7, IMAGE & c8,
			IMAGE & c9, IMAGE & c10, IMAGE & c11, IMAGE & c12, IMAGE & c13, IMAGE & d1, IMAGE & d2, IMAGE & d3, IMAGE & d4, IMAGE & d5, IMAGE & d6, IMAGE & d7,
			IMAGE & d8, IMAGE & d9, IMAGE & d10, IMAGE & d11, IMAGE & d12, IMAGE & d13, IMAGE & e1, IMAGE & e2, IMAGE & img57, IMAGE & img58);//����ճ������
		extern void button(int k, int x, int y, TCHAR * text);
		loadimage1(img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
			b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
			, d10, d11, d12, d13, e1, e2, img57, img58);
		int i, num;
		string change_to_string(int cardnum, int n);
		IMAGE storage_card[5][16];
		storage_card[0][0] = a2;
		storage_card[0][1] = a3;
		storage_card[0][2] = a4;
		storage_card[0][3] = a5;
		storage_card[0][4] = a6;
		storage_card[0][5] = a7;
		storage_card[0][6] = a8;
		storage_card[0][7] = a9;
		storage_card[0][8] = a10;
		storage_card[0][9] = a11;
		storage_card[0][10] = a12;
		storage_card[0][11] = a13;
		storage_card[0][12] = a1;
		storage_card[1][0] = b2;
		storage_card[1][1] = b3;
		storage_card[1][2] = b4;
		storage_card[1][3] = b5;
		storage_card[1][4] = b6;
		storage_card[1][5] = b7;
		storage_card[1][6] = b8;
		storage_card[1][7] = b9;
		storage_card[1][8] = b10;
		storage_card[1][9] = b11;
		storage_card[1][10] = b12;
		storage_card[1][11] = b13;
		storage_card[1][12] = b1;
		storage_card[2][0] = c2;
		storage_card[2][1] = c3;
		storage_card[2][2] = c4;
		storage_card[2][3] = c5;
		storage_card[2][4] = c6;
		storage_card[2][5] = c7;
		storage_card[2][6] = c8;
		storage_card[2][7] = c9;
		storage_card[2][8] = c10;
		storage_card[2][9] = c11;
		storage_card[2][10] = c12;
		storage_card[2][11] = c13;
		storage_card[2][12] = c1;
		storage_card[3][0] = d2;
		storage_card[3][1] = d3;
		storage_card[3][2] = d4;
		storage_card[3][3] = d5;
		storage_card[3][4] = d6;
		storage_card[3][5] = d7;
		storage_card[3][6] = d8;
		storage_card[3][7] = d9;
		storage_card[3][8] = d10;
		storage_card[3][9] = d11;
		storage_card[3][10] = d12;
		storage_card[3][11] = d13;
		storage_card[3][12] = d1;
		storage_card[4][13] = e1;
		storage_card[4][14] = e2;
		putimage(0, 0, &img1);
		TCHAR name1[2][20] = { "����" };
		button(0, 820, 120, name1[0]);
		int x1 = 20, y1 = 500, x2 = 400, y2 = 300;
		cout << "Player plays:";//�����
		for (i = 0; i < j; i++)
		{
			putimage(x2, y2, &storage_card[temp[i][1]][temp[i][0]]);
			x2 += 20;
			cout << change_to_string(temp[i][0], 0);
			if (temp[i][1] != 4)
				cout << change_to_string(temp[i][1], 1);
			cout << " ";
		}
		cout << endl;
		cout << "Player holds:";//�㻹ʣ����
		for (i = 0; i < n; i++)
		{
			if (hand[i][1] != 5)
			{
				putimage(x1, y1, &storage_card[hand[i][1]][hand[i][0]]);
				x1 += 20;
				cout << change_to_string(hand[i][0], 0);
				if (hand[i][0] != 13 && hand[i][0] != 14)
					cout << change_to_string(hand[i][1], 1);
				cout << " ";
			}
		}
		cout << endl;
		TCHAR s1[] = "Arial BLACK";//����
		settextstyle(50, 0, s1);
		settextcolor(BLACK);
		outtextxy(20, 425, "������ʣ����ơ�");
		outtextxy(380, 225, "������ơ�");
		num = 0;
		
		
			for (i = 0; i < n; i++)//����ʣ�µ���
				if (hand[i][1] != 5)
					num += 1;
			if(n>10)//alert
			{	
			if (num <= 10)
			{
				
				cout << "ALERT: The number of cards in the player's hand is only " << num << "!" << endl;
				settextcolor(BLACK);
				outtextxy(0, 0, "С�ģ�������10��������");
				
			}
		}
		TCHAR name5[100];//��ʾʣ������
		sprintf(name5, "%s%d", "ʣ��������", num);
		outtextxy(100, 100, name5);
		if (num == 0)
			cout << "���ƽ���: ���Ӯ���Ѵ���浵" << endl;
		ExMessage msg;//����
		bool check1 = true;
		while (true) {
			if (peekmessage(&msg, EM_MOUSE)) {
				if (msg.message == WM_LBUTTONDOWN) {
					if (msg.x >= 820 && msg.x <= 820 + 170 && msg.y >= 120 && msg.y <= 120 + 50) {

						check1 = false;
						break;
					}
				}
			}
		}
	}
		void run_card_1(int(*hand)[2], int(*play)[2], int n, int m, int level) {//���ֳ��Ƶ�runcard
 //��������ϼ��Ƶ���С�Ż�ը��
		int temp[8][2];
		for (int i = 0; i < 27; i++)
		{
			hand_temp[i][0] = -1;
			hand_temp[i][1] = -1;
		}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 2; j++)
				king[i][j] = -1;
		bomb[0][0] = -1;
		bomb[0][1] = -1;
		hand_count(base, hand, n, level);
		//�ҳ���Сը��,�Ĵ�����,���ɳ�ը�������ʱ��hand_temp
		int count = deal_bomb(base, bomb, king, hand, hand_temp, n);
		int face = play[0][0];
		hand_count(base, hand_temp, n, level);
		if (face != level && face != 13&&face!=14) //�ϼ�����ͨ��,����
		{
			for (int i = 0; i < 15; i++) //�����ƴ���
				if ((base[i][1] == 1 && base[i][0] > face)
					|| (base[i][1] == 1 && base[i][0] == level)) 
				{
					for (int j = 0; j < n; j++)
						if (hand[j][0] == base[i][0])
						{
							temp[0][0] = hand[j][0];
							temp[0][1] = hand[j][1];
							hand[j][1] = 5;
							out_card(temp, hand, 1, n);
							return;
						}
				}
			for (int i = 0; i < 15; i++) //���ƴ���
				if ((base[i][1] > 1 && base[i][0] > face)
					|| (base[i][1] > 1 && base[i][0] == level))
					for (int j = 0; j < n; j++)
						if (hand[j][0] == base[i][0])
						{
							temp[0][0] = hand[j][0];
							temp[0][1] = hand[j][1];
							hand[j][1] = 5;
							out_card(temp, hand, 1, n);
							return;
						}
		}
		if (face == level || face == 13) //�ϼ����Ǽ��ƻ�С��
		{
			//if (base[13][1] != 2 && base[14][1] != 2) //�����Ĵ����������
			for (int j = 13; j <= 14; j++)  //С�������
				if (base[j][1] == 1 && base[j][0] > face)
				{
					for (int i = 0; i < n; i++)
						if (hand[i][0] == j)
						{
							temp[0][0] = hand[i][0];
							temp[0][1] = hand[i][1];
							hand[i][1] = 5;
							out_card(temp, hand, 1, n);
							return;
						}
				}
			for (int j = 13; j <= 14; j++)  //С�������
				if (base[j][1] > 1 && base[j][0] > face)
				{
					for (int i = 0; i < n; i++)
						if (hand[i][0] == j)
						{
							temp[0][0] = hand[i][0];
							temp[0][1] = hand[i][1];
							hand[i][1] = 5;
							out_card(temp, hand, 1, n);
							return;
						}

				}
		}
		int j = find_bomb(temp, hand, n, level, 0); //�����Ĵ�����������ը��
		if (j)
		{
			out_card(temp, hand, j, n);
			return;
		}
		pass(hand, n);
		
	}
	