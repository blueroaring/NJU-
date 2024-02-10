
void hand_count(int(*base)[2], int(*hand)[2], int n, int level) {
	for (int i = 0; i < 15; i++) {//初始化,base为计数数组，记录各种牌的数目
		base[i][0] = i;
		base[i][1] = 0;
	}
	for (int i = level; i < 12; i++)//级牌复位
		base[i][0] = base[i + 1][0];
	base[12][0] = level;
	for(int i=0;i<15;i++)
		for (int j = 0; j < n; j++) {
			if (hand[j][0] == base[i][0])
				base[i][1] += 1;
		}
}