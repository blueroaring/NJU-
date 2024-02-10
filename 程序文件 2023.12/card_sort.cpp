#include<iostream>
using namespace std;
void card_sort(int(*arr)[2], int n, int level) {//��С�����򣬻�ɫ�ǽ���,����������
	int face, suit;
	bool card_compare(int face1, int suit1, int face2, int suit2, int level);
	for (int i = 0; i < n - 1; i++) {//��������
		for (int j = 0; j < n - 1; j++) {
			if (card_compare(arr[j][0], arr[j][1], arr[j + 1][0], arr[j + 1][1], level)) {
				face = arr[j][0];
				suit = arr[j][1];
				arr[j][0] = arr[j + 1][0];
				arr[j][1] = arr[j + 1][1];
				arr[j + 1][0] = face;
				arr[j + 1][1] = suit;
			}
		}
	}
}
bool card_compare(int face1, int suit1, int face2, int suit2, int level) {//�Ƚ������Ƶ������С�����Ǽ��ƣ�
	bool compare = false;
	if (face1 == level) {//��һ�����Ǽ���
		if ((face2 == 13 || face2 == 14) || (face1 == face2 && suit1 > suit2))
			compare = true;
	}
	else if (face1 < face2 || (face1 == face2 && suit1 > suit2) || (face1 != 13 && face2 != 14 && face2 == level))//�����Ѿ�������ֿ��ԱȽϣ�ֻ�迼�Ǽ���
		compare = true;
	return compare;

}
