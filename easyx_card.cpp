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
        show();//���ƺ���
        updateWithoutInput();//�������޹صĸ���
        updateWithInput();//�������йصĸ��£��������̻���꣩
    }*/
}
void startup() {
    initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
    IMAGE img1;//����һ��(����)����
    loadimage(&img1, "C:\\����ҵ\\�������\\CS2023.12 ����ҵ���ڴ��ڣ�\\ͼ���ļ� 2023.12\\����.jpg", 768, 432);
    putimage(0, 0, &img1);

}