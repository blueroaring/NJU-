#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include"data.h"
#include"print_card.h"
#include<graphics.h>
#include<mmsystem.h>//包含多媒体设备接口头文件,一定放在graphics.h下面
#include <conio.h>
#include <time.h>
#include<easyx.h>
#define WIDTH 1024  
#define HEIGHT 650
#pragma comment(lib,"winmm.lib")
#define NDEBUG
using namespace std;
//说明:文件或键盘输入用户数据,按行存入vevctor类型的data,然后按行处理data并执行游戏
int main()
{
    IMAGE img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9,a10,a11,a12,a13,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,
        b11,b12,b13,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,d1,d2,d3,d4,d5,d6,d7,d8,d9
        ,d10,d11,d12,d13,e1,e2,img57,img58;//定义一个(变量)对象
    /*img1:掼蛋初始界面 img2:打牌界面 xx:花色＋牌（按照大小，不是点数匹配，详见loadimage1函数，img57:教程，img58:游戏结束）*/
    void BGM();
    char ch;
    void act_input(IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & a2, IMAGE & a3, IMAGE & a4, IMAGE & a5, IMAGE & a6, IMAGE & a7, IMAGE & a8, IMAGE & a9, IMAGE & a10,
        IMAGE & a11, IMAGE & a12, IMAGE & a13, IMAGE & b1, IMAGE & b2, IMAGE & b3, IMAGE & b4, IMAGE & b5, IMAGE & b6, IMAGE & b7, IMAGE & b8, IMAGE & b9,
        IMAGE & b10, IMAGE & b11, IMAGE & b12, IMAGE & b13, IMAGE & c1, IMAGE & c2, IMAGE & c3, IMAGE & c4, IMAGE & c5, IMAGE & c6, IMAGE & c7, IMAGE & c8,
        IMAGE & c9, IMAGE & c10, IMAGE & c11, IMAGE & c12, IMAGE & c13, IMAGE & d1, IMAGE & d2, IMAGE & d3, IMAGE & d4, IMAGE & d5, IMAGE & d6, IMAGE & d7,
        IMAGE & d8, IMAGE & d9, IMAGE & d10, IMAGE & d11, IMAGE & d12, IMAGE & d13, IMAGE & e1, IMAGE & e2); //键盘输入
    void act_file(IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & a2, IMAGE & a3, IMAGE & a4, IMAGE & a5, IMAGE & a6, IMAGE & a7, IMAGE & a8, IMAGE & a9, IMAGE & a10,
        IMAGE & a11, IMAGE & a12, IMAGE & a13, IMAGE & b1, IMAGE & b2, IMAGE & b3, IMAGE & b4, IMAGE & b5, IMAGE & b6, IMAGE & b7, IMAGE & b8, IMAGE & b9,
        IMAGE & b10, IMAGE & b11, IMAGE & b12, IMAGE & b13, IMAGE & c1, IMAGE & c2, IMAGE & c3, IMAGE & c4, IMAGE & c5, IMAGE & c6, IMAGE & c7, IMAGE & c8,
        IMAGE & c9, IMAGE & c10, IMAGE & c11, IMAGE & c12, IMAGE & c13, IMAGE & d1, IMAGE & d2, IMAGE & d3, IMAGE & d4, IMAGE & d5, IMAGE & d6, IMAGE & d7,
        IMAGE & d8, IMAGE & d9, IMAGE & d10, IMAGE & d11, IMAGE & d12, IMAGE & d13, IMAGE & e1, IMAGE & e2); //文件输入
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
    HWND hnd = GetHWnd();//获得一个句柄用于窗口
    SetWindowText(hnd, "掼蛋");
    BGM();
    cout << "Please select:" << endl;
    cout << "A) 开始新游戏" << endl;
    cout << "B) 加载一个文件中的打牌记录" << endl;
    cout << "Q) 退出游戏" << endl;
    void button(int k, int x, int y, TCHAR * text);//封装创造按钮，k用于切换参数
    //增加一个间隔变量和起始Y坐标变量；
    int gap = 40;
    
    int height = 50;
    TCHAR title[4][50] = { "游戏规则介绍","开始新游戏","加载打牌记录", "退出游戏" };
    TCHAR name1[2][5] = { "掼","蛋" };
    TCHAR name2[1][10] = { "返回" };
    putimage(0, 0, &img2);//img2:初始界面
   
    for (int i = 0; i < 4; i++)
        button(0, 220, 200 + i * height + i * gap, title[i]);
    button(1, 820, 120,name1[0]);//四个功能按钮
    button(1, 820, 540, name1[1]); //掼蛋
    ExMessage msg; //声明一个信息指针
    bool found1 = true;
    bool check1 = true;
    while (check1) {
        
        if (peekmessage(&msg, EM_MOUSE)) {//获取鼠标信息
            settextcolor(BLUE);
            switch (msg.message)
            {
            case WM_LBUTTONDOWN: {//按下鼠标左键
                found1 = false;
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 200 && msg.y <= 200 + 50)
                {
                    putimage(0, 0, &img57);
                    putimage(150, 100, &img58);
                    button(0, 820, 120, name2[0]);
                    ExMessage msg1;
                    while (true) {//教程的点击和返回
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
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 290 && msg.y <= 290 + 50) {//开始新游戏
                    check1 = false;
                    ch = 'A';
                    putimage(0, 0, &img1);
                    settextcolor(BLACK);
                    outtextxy(325, 325, "请在黑窗口输入数据！");   
                    break;
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 380 && msg.y <= 380 + 50) {//输入文件
                    check1 = false;
                    ch = 'B';
                    putimage(0, 0, &img1);
                    settextcolor(BLACK);
                    outtextxy(325, 325, "请在黑窗口写入你的文件路径！");
                    break;
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 470 && msg.y <= 470 + 50) {//quit
                    HWND hnd = GetHWnd();
                    SetWindowText(hnd, "quit");
                    int isok = MessageBox(hnd, "真的要退出吗", "提示", MB_OKCANCEL);
                    if (isok == IDOK)
                        return 0;
                }
                break; }
            case WM_MOUSEMOVE://鼠标光标移动到button
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 200 && msg.y <= 200 + 50&&found1)
                {
                    settextstyle(30, 0, "GB2312");
                    outtextxy(220 + 200, 205, "这真是介绍！");
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 290 && msg.y <= 290 + 50&&found1) {
                    settextstyle(30, 0, "GB2312");
                    outtextxy(220 + 200, 295, "发起决斗邀请！");
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 380 && msg.y <= 380 + 50&&found1) {
                    settextstyle(30, 0, "GB2312");
                    outtextxy(220 + 200, 385, "从文件里读！");
                }
                if (msg.x >= 220 && msg.x <= 220 + 170 && msg.y >= 470 && msg.y <= 470 + 50&&found1) {
                    settextstyle(30, 0, "GB2312");
                    outtextxy(220 + 200, 475, "真的要走吗？");
                }
                break;
            default:break;
            }
        }
    }
#ifdef DEBUG
         cin >> ch;

    ch = toupper(ch);//ctype中的函数，将小写字母转换为大写字母
#endif
    if (ch == 'A')
        act_input(img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
            b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
            , d10, d11, d12, d13, e1, e2);//黑窗口输入
    else if (ch == 'B')
        act_file(img1, img2, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10,
            b11, b12, b13, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, d1, d2, d3, d4, d5, d6, d7, d8, d9
            , d10, d11, d12, d13, e1, e2);//文件输入
#ifdef DEBUG
    else if (ch == 'Q')
    {
        cout << "正在退出游戏……" << endl;
        cout << "退出成功！" << endl;
        return 0;
    }
    else
    {
        cout << "Error:非法输入，程序已退出." << endl;
        return 0;
    }
#endif
    //这几段都是黑窗口模式下才会用到的
    return 0;
}
void act_file(IMAGE& img1, IMAGE& img2, IMAGE& a1, IMAGE& a2, IMAGE& a3, IMAGE& a4, IMAGE& a5, IMAGE& a6, IMAGE& a7, IMAGE& a8, IMAGE& a9, IMAGE& a10,
    IMAGE& a11, IMAGE& a12, IMAGE& a13, IMAGE& b1, IMAGE& b2, IMAGE& b3, IMAGE& b4, IMAGE& b5, IMAGE& b6, IMAGE& b7, IMAGE& b8, IMAGE& b9,
    IMAGE& b10, IMAGE& b11, IMAGE& b12, IMAGE& b13, IMAGE& c1, IMAGE& c2, IMAGE& c3, IMAGE& c4, IMAGE& c5, IMAGE& c6, IMAGE& c7, IMAGE& c8,
    IMAGE& c9, IMAGE& c10, IMAGE& c11, IMAGE& c12, IMAGE& c13, IMAGE& d1, IMAGE& d2, IMAGE& d3, IMAGE& d4, IMAGE& d5, IMAGE& d6, IMAGE& d7,
    IMAGE& d8, IMAGE& d9, IMAGE& d10, IMAGE& d11, IMAGE& d12, IMAGE& d13, IMAGE& e1, IMAGE& e2)
{
    void button(int k, int x, int y, TCHAR * text);
    string s; //字符临时变量
    vector<string> data; //所有数据按行存入
    int i;
    void game_run(vector<string> data, IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & a2, IMAGE & a3, IMAGE & a4, IMAGE & a5, IMAGE & a6, IMAGE & a7, IMAGE & a8, IMAGE & a9, IMAGE & a10,
        IMAGE & a11, IMAGE & a12, IMAGE & a13, IMAGE & b1, IMAGE & b2, IMAGE & b3, IMAGE & b4, IMAGE & b5, IMAGE & b6, IMAGE & b7, IMAGE & b8, IMAGE & b9,
        IMAGE & b10, IMAGE & b11, IMAGE & b12, IMAGE & b13, IMAGE & c1, IMAGE & c2, IMAGE & c3, IMAGE & c4, IMAGE & c5, IMAGE & c6, IMAGE & c7, IMAGE & c8,
        IMAGE & c9, IMAGE & c10, IMAGE & c11, IMAGE & c12, IMAGE & c13, IMAGE & d1, IMAGE & d2, IMAGE & d3, IMAGE & d4, IMAGE & d5, IMAGE & d6, IMAGE & d7,
        IMAGE & d8, IMAGE & d9, IMAGE & d10, IMAGE & d11, IMAGE & d12, IMAGE & d13, IMAGE & e1, IMAGE & e2); //开启游戏入口
    cout << "请输入您的文件路径:" << endl;
    cin.clear();
    cin >> s;
    ifstream inf(s, ios::in);//从一个已打开的文件中读取数据,ios::in:读文件，ios::out:写文件
    if (!inf)//打开文件失败
    {
        cout << "Error:文件无法打开.";
        exit(1);
    }
    i = 0;
    while (getline(inf, s))  //按行输入文件并存入data
    {
        data.push_back(s);
    }
    inf.close();//关闭文件
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
    IMAGE& d8, IMAGE& d9, IMAGE& d10, IMAGE& d11, IMAGE& d12, IMAGE& d13, IMAGE& e1, IMAGE& e2)//输出初始游戏内容，并存储数据到data
{
    void button(int k, int x, int y, TCHAR * text);
    int i, j;
    int times, level, n, m;
    string card, s; //字符临时变量
    vector<string> data; //所有数据按行存入, 需要事先组合
    void game_run(vector<string> data,IMAGE & img1, IMAGE & img2, IMAGE & a1, IMAGE & a2, IMAGE & a3, IMAGE & a4, IMAGE & a5, IMAGE & a6, IMAGE & a7, IMAGE & a8, IMAGE & a9, IMAGE & a10,
        IMAGE & a11, IMAGE & a12, IMAGE & a13, IMAGE & b1, IMAGE & b2, IMAGE & b3, IMAGE & b4, IMAGE & b5, IMAGE & b6, IMAGE & b7, IMAGE & b8, IMAGE & b9,
        IMAGE & b10, IMAGE & b11, IMAGE & b12, IMAGE & b13, IMAGE & c1, IMAGE & c2, IMAGE & c3, IMAGE & c4, IMAGE & c5, IMAGE & c6, IMAGE & c7, IMAGE & c8,
        IMAGE & c9, IMAGE & c10, IMAGE & c11, IMAGE & c12, IMAGE & c13, IMAGE & d1, IMAGE & d2, IMAGE & d3, IMAGE & d4, IMAGE & d5, IMAGE & d6, IMAGE & d7,
        IMAGE & d8, IMAGE & d9, IMAGE & d10, IMAGE & d11, IMAGE & d12, IMAGE & d13, IMAGE & e1, IMAGE & e2); //游戏入口
    cout << "输入花色(s)在(a|b|c|d)除了JOKER和joker." << endl;
    cout << "例如: A(a) JOKER K(c) 2(b)" << endl;
    cout << "下面是输入数据的介绍" << endl;
    cout << "times level             --- 想要演绎出牌的次数, 级牌数" << endl;
    cout << "n m                     --- 你手上有的牌, 对手出的牌数（可为0）" << endl;
    cout << "n1(s1) n2(s2) ...nn(sn) --- 输入你手上有的牌" << endl;
    cout << "m1(s1) m2(s2) ...mn(sn) --- 输入对手出的牌" << endl;
    cout << "注意，请严格按照times level的要求输入，用空格隔开，否则会出现不可预知结果" << endl;
    cout << "n m                     " << endl;
    cout << "n1(s1) n2(s2) ...nn(sn) " << endl;
    cout << "m1(s1) m2(s2) ...mn(sn) " << endl;
    cout << ".......--- times轮循环输入" << endl;
    cout << "请输入你的game data:" << endl;//黑窗口显示
    cin >> times >> level;
    s = "";
    s = to_string(times) + " " + to_string(level);//按照vector（str_get_num函数）的格式
    data.push_back(s); //在尾部存入times,level
    for (i = 0; i < times; i++)
    {
        s = "";//初始化
        cin >> n >> m;
        s = to_string(n) + " " + to_string(m);
        data.push_back(s); //存入n,m
        s = "";
        for (j = 0; j < n; j++)
        {
            cin >> card;
            if (s == "")
                s = card;
            else
                s += " " + card;//空格format存入
        }
        data.push_back(s);  //存入用户牌
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
            data.push_back(s); //存入上家打的牌
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
    vector<string> temp_data; //临时变量,用于将data每行数据拆分
    int i, j, times, level;
    int nm[2]; //保存n和m
    int card_on_hand[27][2]; //手牌最多27张
    int rival_out_card[8][2]; //打出的牌最多8张
    IMAGE storage_card[5][16];//存入数组进行匹配图形输出
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
    temp_data = str_get_num(s); //拆分成times and level
    times = stoi(temp_data[0]);  //转换成数字,c++标准函数
    level = stoi(temp_data[1]) - 2;//级数匹配
#ifdef DEBUG
    cout << times << "," << level << endl;
#endif
    j = 1; //从第一个n,m行读起
    cout << "---------The game result is:----------" << endl;
    for (i = 0; i < times; i++)
    {
        putimage(0, 0, &img1);
        bool check2 = true;
        //获得出牌有牌数组, 传递起始行数并返回下一次读入开始行数
        j = get_data(card_on_hand, rival_out_card, nm, data, j);
        int x1 = 20, y1 = 500, x2 = 20, y2 = 10;
        //判断输出最小的牌, 结果输出
        card_sort(card_on_hand, nm[0], 14);
        for (int h = 0; h < nm[0]; h++)//输出图形
        {
            putimage(x1, y1, &storage_card[card_on_hand[h][1]][card_on_hand[h][0]]);
            x1 += 20;
        }
        if(nm[1]>0)
        card_sort(rival_out_card, nm[1], 14);//输出图形
        for (int k = 0; k < nm[1]; k++) {
            putimage(x2, y2, &storage_card[rival_out_card[k][1]][rival_out_card[k][0]]);
            x2 += 20;
        }
        TCHAR s1[] = "Arial BLACK";
        settextstyle(50, 0, s1);
        settextcolor(BLACK);
        outtextxy(20, 150, "对手出牌↑");//输出字
        outtextxy(20, 425, "你手上的牌↓");
        TCHAR name1[2][20] = { "继续"};
        button(0, 820, 120, name1[0]);
        ExMessage msg;//继续按钮监测
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
        judge(card_on_hand, rival_out_card, nm[0], nm[1], level);//开始逻辑判断
        if (i == times - 1) {//结束了输出结束界面
            IMAGE img59;
            loadimage(&img59, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\南京原神大学.jpg",1024,650);
            putimage(0, 0, &img59);
            TCHAR s1[] = "Arial BLACK";
            settextstyle(100, 0, s1);
            settextcolor(BLACK);
            outtextxy(220 + 140, 385, "游戏结束！");
            TCHAR name3[2][30] = { "退出" };
            button(2, 820, 140, name3[0]);
            ExMessage msg;
            bool check4 = true;
            while(check4)
            if (peekmessage(&msg, EM_MOUSE)) {//quit
                if (msg.message == WM_LBUTTONDOWN) {
                    if (msg.x >= 820 && msg.x <= 820 + 170 && msg.y >= 140 && msg.y <= 140 + 50) {
                        HWND hnd = GetHWnd();
                        SetWindowText(hnd, "quit");
                        int isok = MessageBox(hnd, "真的要退出吗", "提示", MB_OKCANCEL);
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
void button(int k,int x, int y, TCHAR* text)//制作一个roundrect的button
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
        TCHAR s1[] = "微软雅黑";
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

void BGM()//播放音乐
{
    //打开音乐，播放音乐  alias取别名 repeat重复播放

    mciSendString("open C:\\IOmusic\\Atomic+Kitten+-+Nothing+In+The+World.mp3 alias BGM", NULL, 0, NULL);//向多媒体设备接口(mci)发送(send)一个字符串(string)
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
    IMAGE& d8, IMAGE& d9, IMAGE& d10, IMAGE& d11, IMAGE& d12, IMAGE& d13, IMAGE& e1, IMAGE& e2, IMAGE& img57,IMAGE &img58) {//加载图片
    loadimage(&img1, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\牌桌.jpg", 1024, 650);
    loadimage(&img2, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\掼蛋.jpg", 1024, 650);
    loadimage(&a1, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花A.jpg",  100, 130);
    loadimage(&a2, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花2.jpg", 100, 130);
    loadimage(&a3, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花3.jpg", 100, 130);
    loadimage(&a4, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花4.jpg", 100, 130);
    loadimage(&a5, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花5.jpg", 100, 130);
    loadimage(&a6, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花6.jpg", 100, 130);
    loadimage(&a7, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花7.jpg", 100, 130);
    loadimage(&a8, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花8.jpg", 100, 130);
    loadimage(&a9, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花9.jpg", 100, 130);
    loadimage(&a10, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花10.jpg", 100, 130);
    loadimage(&a11, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花J.jpg", 100, 130);
    loadimage(&a12, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花Q.jpg", 100, 130);
    loadimage(&a13 ,"C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\梅花K.jpg", 100, 130);
    loadimage(&b1, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片A.jpg", 100, 130);
    loadimage(&b2, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片2.jpg", 100, 130);
    loadimage(&b3, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片3.jpg", 100, 130);
    loadimage(&b4, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片4.jpg", 100, 130);
    loadimage(&b5, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片5.jpg", 100, 130);
    loadimage(&b6, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片6.jpg", 100, 130);
    loadimage(&b7, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片7.jpg", 100, 130);
    loadimage(&b8, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片8.jpg", 100, 130);
    loadimage(&b9, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片9.jpg", 100, 130);
    loadimage(&b10, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片10.jpg", 100, 130);
    loadimage(&b11, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片J.jpg", 100, 130);
    loadimage(&b12, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片Q.jpg", 100, 130);
    loadimage(&b13, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\方片K.jpg", 100, 130);
    loadimage(&c1, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃A.jpg", 100, 130);
    loadimage(&c2, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃2.jpg", 100, 130);
    loadimage(&c3, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃3.jpg", 100, 130);
    loadimage(&c4, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃4.jpg", 100, 130);
    loadimage(&c5, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃5.jpg", 100, 130);
    loadimage(&c6, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃6.jpg", 100, 130);
    loadimage(&c7, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃7.jpg", 100, 130);
    loadimage(&c8, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃8.jpg", 100, 130);
    loadimage(&c9, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃9.jpg", 100, 130);
    loadimage(&c10, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃10.jpg", 100, 130);
    loadimage(&c11, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃J.jpg", 100, 130);
    loadimage(&c12, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃Q.jpg", 100, 130);
    loadimage(&c13, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\黑桃K.jpg", 100, 130);
    loadimage(&d1, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃A.jpg", 100, 130);
    loadimage(&d2, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃2.jpg", 100, 130);
    loadimage(&d3, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃3.jpg", 100, 130);
    loadimage(&d4, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃4.jpg", 100, 130);
    loadimage(&d5, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃5.jpg", 100, 130);
    loadimage(&d6, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃6.jpg", 100, 130);
    loadimage(&d7, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃7.jpg", 100, 130);
    loadimage(&d8, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃8.jpg", 100, 130);
    loadimage(&d9, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃9.jpg", 100, 130);
    loadimage(&d10, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃10.jpg", 100, 130);
    loadimage(&d11, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃J.jpg", 100, 130);
    loadimage(&d12, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃Q.jpg", 100, 130);
    loadimage(&d13, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃K.jpg", 100, 130);
    loadimage(&d1, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\红桃A.jpg", 100, 130);
    loadimage(&e1, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\小王.jpg", 100, 130);
    loadimage(&e2, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\大王.jpg", 100, 130);
    loadimage(&img57, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\介绍.jpg", 1024, 650);
    loadimage(&img58, "C:\\大作业\\程设基础\\CS2023.12 大作业\\图像文件 2023.12\\教程.png", 625, 400);
}

