#include<graphics.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include<easyx.h>
#define WIDTH 720  
#define HEIGHT 420
using namespace std;
void easyx_windows() {
	void startup();
    startup();
   /* void show();
   void updateWithoutInput();
    void  updateWithInput();
    while (1)
    {
        show();//绘制函数
        updateWithoutInput();//与输入无关的更新
        updateWithInput();//与输入有关的更新（包括键盘或鼠标）
    }*/
}
void startup() {
    initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
    IMAGE img1;//定义一个(变量)对象
    loadimage(&img1, "C:\\大作业\\程设基础\\CS2023.12 大作业（黑窗口）\\图像文件 2023.12\\牌桌.jpg", 768, 432);
    putimage(0, 0, &img1);

}