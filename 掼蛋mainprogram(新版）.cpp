#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include"data.h"
#include"print_card.h"
#include<graphics.h>
#include<mmsystem.h>//������ý���豸�ӿ�ͷ�ļ�,һ������graphics.h����
#include <conio.h>
#include <time.h>
#include<easyx.h>
#define WIDTH 1024  
#define HEIGHT 650
#pragma comment(lib,"winmm.lib")
#define NDEBUG
using namespace std;
//˵��:�ļ�����������û�����,���д���vevctor���͵�data,Ȼ���д���data��ִ����Ϸ
int main()
{
    IMAGE img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,
        b11,b12,b13,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,d1,d2,d3,d4,d5,d6,d7,d8,d9
        ,d10,d11,d12,d13,e1,e2,img57,img58;//����һ��(����)����
    /*img1:�走��ʼ���� img2:���ƽ��� xx:��ɫ���ƣ����մ�С�����ǵ���ƥ�䣬���loadimage1������img57:�̳̣�img58:��Ϸ������*/
    void BGM();
    char ch;
    void act_input(IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & a2, IMAGE & a3, IMAGE & a4, IMAGE & a5, IMAGE & a6, IMAGE & a7, IMAGE & a8, IMAGE & a9, IMAGE & a10,
        IMAGE & a11, IMAGE & a12, IMAGE & a13, IMAGE & b1, IMAGE & b2, IMAGE & b3, IMAGE & b4, IMAGE & b5, IMAGE & b6, IMAGE & b7, IMAGE & b8, IMAGE & b9,
        IMAGE & b10, IMAGE & b11, IMAGE & b12, IMAGE & b13, IMAGE & c1, IMAGE & c2, IMAGE & c3, IMAGE & c4, IMAGE & c5, IMAGE & c6, IMAGE & c7, IMAGE & c8,
        IMAGE & c9, IMAGE & c10, IMAGE & c11, IMAGE & c12, IMAGE & c13, IMAGE & d1, IMAGE & d2, IMAGE & d3, IMAGE & d4, IMAGE & d5, IMAGE & d6, IMAGE & d7,
        IMAGE & d8, IMAGE & d9, IMAGE & d10, IMAGE & d11, IMAGE & d12, IMAGE & d13, IMAGE & e1, IMAGE & e2); //��������
    void act_file(IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & a2, IMAGE & a3, IMAGE & a4, IMAGE & a5, IMAGE & a6, IMAGE & a7, IMAGE & a8, IMAGE & a9, IMAGE & a10,
        IMAGE & a11, IMAGE & a12, IMAGE & a13, IMAGE & b1, IMAGE & b2, IMAGE & b3, IMAGE & b4, IMAGE & b5, IMAGE & b6, IMAGE & b7, IMAGE & b8, IMAGE & b9,
        IMAGE & b10, IMAGE & b11, IMAGE & b12, IMAGE & b13, IMAGE & c1, IMAGE & c2, IMAGE & c3, IMAGE & c4, IMAGE & c5, IMAGE & c6, IMAGE & c7, IMAGE & c8,
        IMAGE & c9, IMAGE & c10, IMAGE & c11, IMAGE & c12, IMAGE & c13, IMAGE & d1, IMAGE & d2, IMAGE & d3, IMAGE & d4, IMAGE & d5, IMAGE & d6, IMAGE & d7,
        IMAGE & d8, IMAGE & d9, IMAGE & d10, IMAGE & d11, IMAGE & d12, IMAGE & d13, IMAGE & e1, IMAGE & e2); //�ļ�����
    initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
    void loadimage1(IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & img4, IMAGE & ing5, IMAGE & img6, IMAGE & img7, IMAGE & img8, IMAGE & img9, IMAGE & img10, IMAGE & img11, IMAGE & img12,
        IMAGE & img13, IMAGE & img14, IMAGE & img15, IMAGE & img16, IMAGE & img17, IMAGE & img18, IMAGE & img19, IMAGE & img20, IMAGE & img21, IMAGE & img22, IMAGE & img23, IMAGE & img24,
        IMAGE & img25, IMAGE & img26, IMAGE & img27, IMAGE & img28, IMAGE & img29, IMAGE & img30, IMAGE & img31, IMAGE & img32, IMAGE & img33, IMAGE & img34, IMAGE & img35, IMAGE & img36,
        IMAGE & img37, IMAGE & img38, IMAGE & img39, IMAGE & img40, IMAGE & img41, IMAGE & img42, IMAGE & img43, IMAGE & img44, IMAGE & img45, IMAGE & img46, IMAGE & img47, IMAGE & img48,
        IMAGE & img49, IMAGE & img50, IMAGE & img51, IMAGE & img52, IMAGE & img53, IMAGE & img54, IMAGE & img55, IMAGE & img56, IMAGE & img57,IMAGE &img58);
    loadimage1(img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
        b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
        , d10, d11, d12, d13, e1, e2, img57,img58);
    putimage(0, 0, &img1);
    HWND hnd = GetHWnd();//���һ��������ڴ���
    SetWindowText(hnd, "�走");
    BGM();
    cout << "Please select:" << endl;
    cout << "A) ��ʼ����Ϸ" << endl;
    cout << "B) ����һ���ļ��еĴ��Ƽ�¼" << endl;
    cout << "Q) �˳���Ϸ" << endl;
    void button(int k, int x, int y, TCHAR * text);//��װ���찴ť��k�����л�����
    //����һ�������������ʼY���������
    int gap = 40;
    
    int height = 50;
    TCHAR title[4][50] = { "��Ϸ�������","��ʼ����Ϸ","���ش��Ƽ�¼", "�˳���Ϸ" };
    TCHAR name1[2][5] = { "��","��" };
    TCHAR name2[1][10] = { "����" };
    putimage(0, 0, &img2);//img2:��ʼ����
   
    for (int i = 0; i < 4; i++)
        button(0, 220, 200 + i * height + i * gap, title[i]);
    button(1, 820, 120,name1[0]);//�ĸ����ܰ�ť
    button(1, 820, 540, name1[1]); //�走
    ExMessage msg; //����һ����Ϣָ��
    bool found1 = true;
    bool check1 = true;
    while (check1) {
        
        if (peekmessage(&msg, EM_MOUSE)) {//��ȡ�����Ϣ
            settextcolor(BLUE);
            switch (msg.message)
            {
            case WM_LBUTTONDOWN: {//����������
                found1 = false;
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 200 && msg.y <= 200 + 50)
                {
                    putimage(0, 0, &img57);
                    putimage(150, 100, &img58);
                    button(0, 820, 120, name2[0]);
                    ExMessage msg1;
                    while (true) {//�̵̳ĵ���ͷ���
                        if (peekmessage(&msg1, EM_MOUSE)) {
                            if (msg1.message == WM_LBUTTONDOWN) {
                                if (msg1.x >= 820 && msg1.x <= 820 + 170 && msg1.y >= 120 && msg1.y <= 120 + 50) {
                                    putimage(0, 0, &img2);
                                    for (int i = 0; i < 4; i++)
                                        button(0, 220, 200 + i * height + i * gap, title[i]);
                                    button(1, 820, 120, name1[0]);
                                    button(1, 820, 540, name1[1]);
                                    found1 = true;
                                    break;
                                }
                            }
                        }
                    }

                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 290 && msg.y <= 290 + 50) {//��ʼ����Ϸ
                    check1 = false;
                    ch = 'A';
                    putimage(0, 0, &img1);
                    settextcolor(BLACK);
                    outtextxy(325, 325, "���ںڴ����������ݣ�");   
                    break;
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 380 && msg.y <= 380 + 50) {//�����ļ�
                    check1 = false;
                    ch = 'B';
                    putimage(0, 0, &img1);
                    settextcolor(BLACK);
                    outtextxy(325, 325, "���ںڴ���д������ļ�·����");
                    break;
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 470 && msg.y <= 470 + 50) {//quit
                    HWND hnd = GetHWnd();
                    SetWindowText(hnd, "quit");
                    int isok = MessageBox(hnd, "���Ҫ�˳���", "��ʾ", MB_OKCANCEL);
                    if (isok == IDOK)
                        return 0;
                }
                break; }
            case WM_MOUSEMOVE://������ƶ���button
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 200 && msg.y <= 200 + 50&&found1)
                {
                    settextstyle(30, 0, "GB2312");
                    outtextxy(220 + 200, 205, "�����ǽ��ܣ�");
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 290 && msg.y <= 290 + 50&&found1) {
                    settextstyle(30, 0, "GB2312");
                    outtextxy(220 + 200, 295, "����������룡");
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 380 && msg.y <= 380 + 50&&found1) {
                    settextstyle(30, 0, "GB2312");
                    outtextxy(220 + 200, 385, "���ļ������");
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 470 && msg.y <= 470 + 50&&found1) {
                    settextstyle(30, 0, "GB2312");
                    outtextxy(220 + 200, 475, "���Ҫ����");
                }
                break;
            default:break;
            }
        }
    }
#ifdef DEBUG
         cin >> ch;

    ch = toupper(ch);//ctype�еĺ�������Сд��ĸת��Ϊ��д��ĸ
#endif
    if (ch == 'A')
        act_input(img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
            b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
            , d10, d11, d12, d13, e1, e2);//�ڴ�������
    else if (ch == 'B')
        act_file(img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
            b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
            , d10, d11, d12, d13, e1, e2);//�ļ�����
#ifdef DEBUG
    else if (ch == 'Q')
    {
        cout << "�����˳���Ϸ����" << endl;
        cout << "�˳��ɹ���" << endl;
        return 0;
    }
    else
    {
        cout << "Error:�Ƿ����룬�������˳�." << endl;
        return 0;
    }
#endif
    //�⼸�ζ��Ǻڴ���ģʽ�²Ż��õ���
    return 0;
}
void act_file(IMAGE& img1, IMAGE& img2, IMAGE& a1, IMAGE& a2, IMAGE& a3, IMAGE& a4, IMAGE& a5, IMAGE& a6, IMAGE& a7, IMAGE& a8, IMAGE& a9, IMAGE& a10,
    IMAGE& a11, IMAGE& a12, IMAGE& a13, IMAGE& b1, IMAGE& b2, IMAGE& b3, IMAGE& b4, IMAGE& b5, IMAGE& b6, IMAGE& b7, IMAGE& b8, IMAGE& b9,
    IMAGE& b10, IMAGE& b11, IMAGE& b12, IMAGE& b13, IMAGE& c1, IMAGE& c2, IMAGE& c3, IMAGE& c4, IMAGE& c5, IMAGE& c6, IMAGE& c7, IMAGE& c8,
    IMAGE& c9, IMAGE& c10, IMAGE& c11, IMAGE& c12, IMAGE& c13, IMAGE& d1, IMAGE& d2, IMAGE& d3, IMAGE& d4, IMAGE& d5, IMAGE& d6, IMAGE& d7,
    IMAGE& d8, IMAGE& d9, IMAGE& d10, IMAGE& d11, IMAGE& d12, IMAGE& d13, IMAGE& e1, IMAGE& e2)
{
    void button(int k, int x, int y, TCHAR * text);
    string s; //�ַ���ʱ����
    vector<string> data; //�������ݰ��д���
    int i;
    void game_run(vector<string> data, IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & a2, IMAGE & a3, IMAGE & a4, IMAGE & a5, IMAGE & a6, IMAGE & a7, IMAGE & a8, IMAGE & a9, IMAGE & a10,
        IMAGE & a11, IMAGE & a12, IMAGE & a13, IMAGE & b1, IMAGE & b2, IMAGE & b3, IMAGE & b4, IMAGE & b5, IMAGE & b6, IMAGE & b7, IMAGE & b8, IMAGE & b9,
        IMAGE & b10, IMAGE & b11, IMAGE & b12, IMAGE & b13, IMAGE & c1, IMAGE & c2, IMAGE & c3, IMAGE & c4, IMAGE & c5, IMAGE & c6, IMAGE & c7, IMAGE & c8,
        IMAGE & c9, IMAGE & c10, IMAGE & c11, IMAGE & c12, IMAGE & c13, IMAGE & d1, IMAGE & d2, IMAGE & d3, IMAGE & d4, IMAGE & d5, IMAGE & d6, IMAGE & d7,
        IMAGE & d8, IMAGE & d9, IMAGE & d10, IMAGE & d11, IMAGE & d12, IMAGE & d13, IMAGE & e1, IMAGE & e2); //������Ϸ���
    cout << "�����������ļ�·��:" << endl;
    cin.clear();
    cin >> s;
    ifstream inf(s, ios::in);//��һ���Ѵ򿪵��ļ��ж�ȡ����,ios::in:���ļ���ios::out:д�ļ�
    if (!inf)//���ļ�ʧ��
    {
        cout << "Error:�ļ��޷���.";
        exit(1);
    }
    i = 0;
    while (getline(inf, s))  //���������ļ�������data
    {
        data.push_back(s);
    }
    inf.close();//�ر��ļ�
#ifdef DEBUG
    cout << "The game input is:" << endl;
    vector_show(data, 0,0,0);
#endif
    putimage(0, 0, &img1);
    game_run(data, img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
        b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
        , d10, d11, d12, d13, e1, e2);
}
void act_input(IMAGE& img1, IMAGE& img2, IMAGE& a1, IMAGE& a2, IMAGE& a3, IMAGE& a4, IMAGE& a5, IMAGE& a6, IMAGE& a7, IMAGE& a8, IMAGE& a9, IMAGE& a10,
    IMAGE& a11, IMAGE& a12, IMAGE& a13, IMAGE& b1, IMAGE& b2, IMAGE& b3, IMAGE& b4, IMAGE& b5, IMAGE& b6, IMAGE& b7, IMAGE& b8, IMAGE& b9,
    IMAGE& b10, IMAGE& b11, IMAGE& b12, IMAGE& b13, IMAGE& c1, IMAGE& c2, IMAGE& c3, IMAGE& c4, IMAGE& c5, IMAGE& c6, IMAGE& c7, IMAGE& c8,
    IMAGE& c9, IMAGE& c10, IMAGE& c11, IMAGE& c12, IMAGE& c13, IMAGE& d1, IMAGE& d2, IMAGE& d3, IMAGE& d4, IMAGE& d5, IMAGE& d6, IMAGE& d7,
    IMAGE& d8, IMAGE& d9, IMAGE& d10, IMAGE& d11, IMAGE& d12, IMAGE& d13, IMAGE& e1, IMAGE& e2)//�����ʼ��Ϸ���ݣ����洢���ݵ�data
{
    void button(int k, int x, int y, TCHAR * text);
    int i, j;
    int times, level, n, m;
    string card, s; //�ַ���ʱ����
    vector<string> data; //�������ݰ��д���, ��Ҫ�������
    void game_run(vector<string> data,IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & a2, IMAGE & a3, IMAGE & a4, IMAGE & a5, IMAGE & a6, IMAGE & a7, IMAGE & a8, IMAGE & a9, IMAGE & a10,
        IMAGE & a11, IMAGE & a12, IMAGE & a13, IMAGE & b1, IMAGE & b2, IMAGE & b3, IMAGE & b4, IMAGE & b5, IMAGE & b6, IMAGE & b7, IMAGE & b8, IMAGE & b9,
        IMAGE & b10, IMAGE & b11, IMAGE & b12, IMAGE & b13, IMAGE & c1, IMAGE & c2, IMAGE & c3, IMAGE & c4, IMAGE & c5, IMAGE & c6, IMAGE & c7, IMAGE & c8,
        IMAGE & c9, IMAGE & c10, IMAGE & c11, IMAGE & c12, IMAGE & c13, IMAGE & d1, IMAGE & d2, IMAGE & d3, IMAGE & d4, IMAGE & d5, IMAGE & d6, IMAGE & d7,
        IMAGE & d8, IMAGE & d9, IMAGE & d10, IMAGE & d11, IMAGE & d12, IMAGE & d13, IMAGE & e1, IMAGE & e2); //��Ϸ���
    cout << "���뻨ɫ(s)��(a|b|c|d)����JOKER��joker." << endl;
    cout << "����: A(a) JOKER K(c) 2(b)" << endl;
    cout << "�������������ݵĽ���" << endl;
    cout << "times level             --- ��Ҫ������ƵĴ���, ������" << endl;
    cout << "n m                     --- �������е���, ���ֳ�����������Ϊ0��" << endl;
    cout << "n1(s1) n2(s2) ...nn(sn) --- �����������е���" << endl;
    cout << "m1(s1) m2(s2) ...mn(sn) --- ������ֳ�����" << endl;
    cout << "ע�⣬���ϸ���times level��Ҫ�����룬�ÿո�������������ֲ���Ԥ֪���" << endl;
    cout << "n m                     " << endl;
    cout << "n1(s1) n2(s2) ...nn(sn) " << endl;
    cout << "m1(s1) m2(s2) ...mn(sn) " << endl;
    cout << ".......--- times��ѭ������" << endl;
    cout << "���������game data:" << endl;//�ڴ�����ʾ
    cin >> times >> level;
    s = "";
    s = to_string(times) + " " + to_string(level);//����vector��str_get_num�������ĸ�ʽ
    data.push_back(s); //��β������times,level
    for (i = 0; i < times; i++)
    {
        s = "";//��ʼ��
        cin >> n >> m;
        s = to_string(n) + " " + to_string(m);
        data.push_back(s); //����n,m
        s = "";
        for (j = 0; j < n; j++)
        {
            cin >> card;
            if (s == "")
                s = card;
            else
                s += " " + card;//�ո�format����
        }
        data.push_back(s);  //�����û���
        if (m > 0)
        {
            s = "";
            for (j = 0; j < m; j++)
            {
                cin >> card;
                if (s == "")
                    s = card;
                else
                    s += " " + card;
            }
            data.push_back(s); //�����ϼҴ����
        }
    }
    putimage(0, 0, &img1);
    game_run(data, img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
        b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
        , d10, d11, d12, d13, e1, e2);
}
void game_run(vector<string> data, IMAGE& img1, IMAGE& img2, IMAGE& a1, IMAGE& a2, IMAGE& a3, IMAGE& a4, IMAGE& a5, IMAGE& a6, IMAGE& a7, IMAGE& a8, IMAGE& a9, IMAGE& a10,
    IMAGE& a11, IMAGE& a12, IMAGE& a13, IMAGE& b1, IMAGE& b2, IMAGE& b3, IMAGE& b4, IMAGE& b5, IMAGE& b6, IMAGE& b7, IMAGE& b8, IMAGE& b9,
    IMAGE& b10, IMAGE& b11, IMAGE& b12, IMAGE& b13, IMAGE& c1, IMAGE& c2, IMAGE& c3, IMAGE& c4, IMAGE& c5, IMAGE& c6, IMAGE& c7, IMAGE& c8,
    IMAGE& c9, IMAGE& c10, IMAGE& c11, IMAGE& c12, IMAGE& c13, IMAGE& d1, IMAGE& d2, IMAGE& d3, IMAGE& d4, IMAGE& d5, IMAGE& d6, IMAGE& d7,
    IMAGE& d8, IMAGE& d9, IMAGE& d10, IMAGE& d11, IMAGE& d12, IMAGE& d13, IMAGE& e1, IMAGE& e2)
{
    extern void judge(int(*arr1)[2], int(*arr2)[2], int n, int m, int level);
    extern vector<string> str_get_num(const string & str);
    void button(int k, int x, int y, TCHAR * text);
    string s;
    vector<string> temp_data; //��ʱ����,���ڽ�dataÿ�����ݲ��
    int i, j, times, level;
    int nm[2]; //����n��m
    int card_on_hand[27][2]; //�������27��
    int rival_out_card[8][2]; //����������8��
    IMAGE storage_card[5][16];//�����������ƥ��ͼ�����
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
    s = data[0];  //times, level
    temp_data = str_get_num(s); //��ֳ�times and level
    times = stoi(temp_data[0]);  //ת��������,c++��׼����
    level = stoi(temp_data[1]) - 2;//����ƥ��
#ifdef DEBUG
    cout << times << "," << level << endl;
#endif
    j = 1; //�ӵ�һ��n,m�ж���
    cout << "---------The game result is:----------" << endl;
    for (i = 0; i < times; i++)
    {
        putimage(0, 0, &img1);
        bool check2 = true;
        //��ó�����������, ������ʼ������������һ�ζ��뿪ʼ����
        j = get_data(card_on_hand, rival_out_card, nm, data, j);
        int x1 = 20, y1 = 500, x2 = 20, y2 = 10;
        //�ж������С����, ������
        card_sort(card_on_hand, nm[0], 14);
        for (int h = 0; h < nm[0]; h++)//���ͼ��
        {
            putimage(x1, y1, &storage_card[card_on_hand[h][1]][card_on_hand[h][0]]);
            x1 += 20;
        }
        if(nm[1]>0)
        card_sort(rival_out_card, nm[1], 14);//���ͼ��
        for (int k = 0; k < nm[1]; k++) {
            putimage(x2, y2, &storage_card[rival_out_card[k][1]][rival_out_card[k][0]]);
            x2 += 20;
        }
        TCHAR s1[] = "Arial BLACK";
        settextstyle(50, 0, s1);
        settextcolor(BLACK);
        outtextxy(20, 150, "���ֳ��ơ�");//�����
        outtextxy(20, 425, "�����ϵ��ơ�");
        TCHAR name1[2][20] = { "����"};
        button(0, 820, 120, name1[0]);
        ExMessage msg;//������ť���
            while (true) {
                if (peekmessage(&msg, EM_MOUSE)) {
                    if (msg.message == WM_LBUTTONDOWN) {
                        if (msg.x >= 820 && msg.x <= 820 + 170 && msg.y >= 120 && msg.y <= 120 + 50) {
                           
                            check2 = false;
                            break;
                        }
                    }
                }
            }
            if (i == times - 1)
                check2 = false;
        while(check2)
            system("pause");
        judge(card_on_hand, rival_out_card, nm[0], nm[1], level);//��ʼ�߼��ж�
        if (i == times - 1) {//�����������������
            IMAGE img59;
            loadimage(&img59, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\�Ͼ�ԭ���ѧ.jpg",1024,650);
            putimage(0, 0, &img59);
            TCHAR s1[] = "Arial BLACK";
            settextstyle(100, 0, s1);
            settextcolor(BLACK);
            outtextxy(220 + 140, 385, "��Ϸ������");
            TCHAR name3[2][30] = { "�˳�" };
            button(2, 820, 140, name3[0]);
            ExMessage msg;
            bool check4 = true;
            while(check4)
            if (peekmessage(&msg, EM_MOUSE)) {//quit
                if (msg.message == WM_LBUTTONDOWN) {
                    if (msg.x >= 820 && msg.x <= 820 + 170 && msg.y >= 140 && msg.y <= 140 + 50) {
                        HWND hnd = GetHWnd();
                        SetWindowText(hnd, "quit");
                        int isok = MessageBox(hnd, "���Ҫ�˳���", "��ʾ", MB_OKCANCEL);
                        if (isok == IDOK) {
                            check4 = false;
                            return;
                        }
                    }
                }
            }
            
        }
    }
}
void button(int k,int x, int y, TCHAR* text)//����һ��roundrect��button
{
    
    if (k == 0) {
        int w = 200, h = 44;
        setbkmode(TRANSPARENT);

        setfillcolor(RED);
        fillroundrect(x, y, x + w, y + h, 10, 10);
        TCHAR s1[] = "Arial BLACK";
        settextstyle(30, 0, s1);
        settextcolor(WHITE);

        int tx = x + (w - textwidth(text)) / 2;
        int ty = y + (h - textheight(text)) / 2;

        outtextxy(tx, ty, text);
       
       
    }
    if (k == 1) {
        setbkmode(TRANSPARENT);

        setfillcolor(RED);
        fillcircle(x, y,100);
        TCHAR s1[] = "΢���ź�";
        settextstyle(100, 0, s1);
        settextcolor(BLACK);
        outtextxy(x-40, y-50, text);
    }
    if (k == 2) {
        int w = 200, h = 44;
        setbkmode(TRANSPARENT);

        setfillcolor(YELLOW);
        fillroundrect(x, y, x + w, y + h, 10, 10);
        TCHAR s1[] = "Arial BLACK";
        settextstyle(30, 0, s1);
        settextcolor(BLACK);

        int tx = x + (w - textwidth(text)) / 2;
        int ty = y + (h - textheight(text)) / 2;

        outtextxy(tx, ty, text);
    }
}

void BGM()//��������
{
    //�����֣���������  aliasȡ���� repeat�ظ�����

    mciSendString("open C:\\IOmusic\\Atomic+Kitten+-+Nothing+In+The+World.mp3 alias BGM", NULL, 0, NULL);//���ý���豸�ӿ�(mci)����(send)һ���ַ���(string)
    mciSendString("play BGM repeat", NULL, 0, NULL);
    if (0)
    {
        mciSendString("close BGM ", 0, 0, 0);
    }


}
void loadimage1(IMAGE& img1, IMAGE& img2, IMAGE& a1, IMAGE& a2, IMAGE& a3, IMAGE& a4, IMAGE& a5, IMAGE& a6, IMAGE& a7, IMAGE& a8, IMAGE& a9, IMAGE& a10,
    IMAGE& a11, IMAGE& a12, IMAGE& a13, IMAGE& b1, IMAGE& b2, IMAGE& b3, IMAGE& b4, IMAGE& b5, IMAGE& b6, IMAGE& b7, IMAGE& b8, IMAGE& b9,
    IMAGE& b10, IMAGE& b11, IMAGE& b12, IMAGE& b13, IMAGE& c1, IMAGE&c2 , IMAGE& c3, IMAGE& c4, IMAGE& c5, IMAGE& c6, IMAGE& c7, IMAGE& c8,
    IMAGE& c9, IMAGE& c10, IMAGE& c11, IMAGE& c12, IMAGE& c13, IMAGE& d1, IMAGE& d2, IMAGE& d3, IMAGE& d4, IMAGE& d5, IMAGE& d6, IMAGE& d7,
    IMAGE& d8, IMAGE& d9, IMAGE& d10, IMAGE& d11, IMAGE& d12, IMAGE& d13, IMAGE& e1, IMAGE& e2, IMAGE& img57,IMAGE &img58) {//����ͼƬ
    loadimage(&img1, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����.jpg", 1024, 650);
    loadimage(&img2, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\�走.jpg", 1024, 650);
    loadimage(&a1, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��A.jpg",  100, 130);
    loadimage(&a2, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��2.jpg", 100, 130);
    loadimage(&a3, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��3.jpg", 100, 130);
    loadimage(&a4, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��4.jpg", 100, 130);
    loadimage(&a5, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��5.jpg", 100, 130);
    loadimage(&a6, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��6.jpg", 100, 130);
    loadimage(&a7, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��7.jpg", 100, 130);
    loadimage(&a8, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��8.jpg", 100, 130);
    loadimage(&a9, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��9.jpg", 100, 130);
    loadimage(&a10, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��10.jpg", 100, 130);
    loadimage(&a11, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��J.jpg", 100, 130);
    loadimage(&a12, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��Q.jpg", 100, 130);
    loadimage(&a13 ,"C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\÷��K.jpg", 100, 130);
    loadimage(&b1, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��ƬA.jpg", 100, 130);
    loadimage(&b2, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��Ƭ2.jpg", 100, 130);
    loadimage(&b3, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��Ƭ3.jpg", 100, 130);
    loadimage(&b4, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��Ƭ4.jpg", 100, 130);
    loadimage(&b5, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��Ƭ5.jpg", 100, 130);
    loadimage(&b6, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��Ƭ6.jpg", 100, 130);
    loadimage(&b7, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��Ƭ7.jpg", 100, 130);
    loadimage(&b8, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��Ƭ8.jpg", 100, 130);
    loadimage(&b9, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��Ƭ9.jpg", 100, 130);
    loadimage(&b10, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��Ƭ10.jpg", 100, 130);
    loadimage(&b11, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��ƬJ.jpg", 100, 130);
    loadimage(&b12, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��ƬQ.jpg", 100, 130);
    loadimage(&b13, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\��ƬK.jpg", 100, 130);
    loadimage(&c1, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����A.jpg", 100, 130);
    loadimage(&c2, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����2.jpg", 100, 130);
    loadimage(&c3, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����3.jpg", 100, 130);
    loadimage(&c4, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����4.jpg", 100, 130);
    loadimage(&c5, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����5.jpg", 100, 130);
    loadimage(&c6, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����6.jpg", 100, 130);
    loadimage(&c7, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����7.jpg", 100, 130);
    loadimage(&c8, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����8.jpg", 100, 130);
    loadimage(&c9, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����9.jpg", 100, 130);
    loadimage(&c10, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����10.jpg", 100, 130);
    loadimage(&c11, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����J.jpg", 100, 130);
    loadimage(&c12, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����Q.jpg", 100, 130);
    loadimage(&c13, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����K.jpg", 100, 130);
    loadimage(&d1, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����A.jpg", 100, 130);
    loadimage(&d2, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����2.jpg", 100, 130);
    loadimage(&d3, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����3.jpg", 100, 130);
    loadimage(&d4, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����4.jpg", 100, 130);
    loadimage(&d5, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����5.jpg", 100, 130);
    loadimage(&d6, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����6.jpg", 100, 130);
    loadimage(&d7, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����7.jpg", 100, 130);
    loadimage(&d8, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����8.jpg", 100, 130);
    loadimage(&d9, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����9.jpg", 100, 130);
    loadimage(&d10, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����10.jpg", 100, 130);
    loadimage(&d11, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����J.jpg", 100, 130);
    loadimage(&d12, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����Q.jpg", 100, 130);
    loadimage(&d13, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����K.jpg", 100, 130);
    loadimage(&d1, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����A.jpg", 100, 130);
    loadimage(&e1, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\С��.jpg", 100, 130);
    loadimage(&e2, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����.jpg", 100, 130);
    loadimage(&img57, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\����.jpg", 1024, 650);
    loadimage(&img58, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ\\ͼ���ļ� 2023.12\\�̳�.png", 625, 400);
}

