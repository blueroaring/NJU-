#include "print_card.h"
#include<graphics.h>
#include <conio.h>
#include <time.h>
#include<easyx.h>
void pass(int(*hand)[2], int n) {//除了输出pass,剩下与outcard基本一致，不再赘述
    IMAGE img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
        b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
        , d10, d11, d12, d13, e1, e2, img57, img58;
    extern void loadimage1(IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & a2, IMAGE & a3, IMAGE & a4, IMAGE & a5, IMAGE & a6, IMAGE & a7, IMAGE & a8, IMAGE & a9, IMAGE & a10,
        IMAGE & a11, IMAGE & a12, IMAGE & a13, IMAGE & b1, IMAGE & b2, IMAGE & b3, IMAGE & b4, IMAGE & b5, IMAGE & b6, IMAGE & b7, IMAGE & b8, IMAGE & b9,
        IMAGE & b10, IMAGE & b11, IMAGE & b12, IMAGE & b13, IMAGE & c1, IMAGE & c2, IMAGE & c3, IMAGE & c4, IMAGE & c5, IMAGE & c6, IMAGE & c7, IMAGE & c8,
        IMAGE & c9, IMAGE & c10, IMAGE & c11, IMAGE & c12, IMAGE & c13, IMAGE & d1, IMAGE & d2, IMAGE & d3, IMAGE & d4, IMAGE & d5, IMAGE & d6, IMAGE & d7,
        IMAGE & d8, IMAGE & d9, IMAGE & d10, IMAGE & d11, IMAGE & d12, IMAGE & d13, IMAGE & e1, IMAGE & e2, IMAGE & img57, IMAGE & img58);
    extern void button(int k, int x, int y, TCHAR * text);
    loadimage1(img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
        b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
        , d10, d11, d12, d13, e1, e2, img57, img58);
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
    int i;
    cout << "Player plays: Pass" << endl;
    cout << "Player holds: ";
	int x1 = 20, y1 = 500; 
    for (i = 0; i < n; i++)
    {
        {
            cout << change_to_string(hand[i][0], 0);
			putimage(x1, y1, &storage_card[hand[i][1]][hand[i][0]]);
			x1 += 20;
            if (hand[i][0] != 13 && hand[i][0] != 14)
                cout << change_to_string(hand[i][1], 1);
            cout << " ";
        }
    }
	TCHAR s1[] = "Arial BLACK";
	settextstyle(50, 0, s1);
	settextcolor(BLACK);
	outtextxy(20, 425, "你手上剩余的牌↓");
	outtextxy(380, 225, "你出的牌↓");
	TCHAR name1[2][20] = { "继续" };
	TCHAR name5[100];
	sprintf(name5, "%s%d", "剩余牌数：", n);
	outtextxy(100, 100, name5);
	button(0, 820, 120, name1[0]);
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x >= 820 && msg.x <= 820 + 170 && msg.y >= 120 && msg.y <= 120 + 50) {
					break;
				}
			}
		}
	}
}