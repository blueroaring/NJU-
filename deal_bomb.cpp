int deal_bomb(int(*base)[2], int(*bomb)[2], int(*king)[2], int(*hand)[2], int(*hand_temp)[2], int n) {
	int cnt=0;//临时表的计数
	bool found=false;
	for (int i = 4; i <= 8; i++)//将最小炸弹放入bomb
	{
		if(!found)
			for (int j = 0; j < 13; j++) {
				if(!found&&base[j][1]==i)//张数匹配
					for(int k=0;k<n;k++)
						if (hand[k][0] == base[j][0])//寻找其在hand的位置,存入bomb
						{
							bomb[0][0] = hand[k][0];
							bomb[0][1] = base[j][1];
							found = true;
							break;
						}
			}
	}
	if ((!found) && base[13][1] == 2 && base[14][1] == 2)//没有普通炸弹,找四大天王存入king
	{
		int p = 0;
		for (int i = 14; i >= 13; i--) {
			king[p][0] = i;
			king[p][1] = 4;
			p++;
			king[p][0] = i;
			king[p][1] = 4;
		}
	}
	if (base[13][1] != 2 || base[14][1] != 2) {//不是四大天王将王写入临时表hand_temp
		int k = 0;
		for (int i = 14; i >= 13; i--) {
			if(base[i][1]>0)
				for (int j = 0; j < base[i][1]; j++) {
					hand_temp[k][0] = i;
					hand_temp[k][1] = 4;
					k++;
				}
		}
		cnt = base[13][1] + base[14][1];
	}
	for (int i = 12; i >= 0; i--) {//将不包含炸弹的数据写入临时表hand_temp
		if (base[i][1] > 0 && base[i][1] < 4) {
			for (int j = 0; j < n; j++)
				if (hand[j][0] == base[i][0]) {
					hand_temp[cnt][0] = hand[j][0];
					hand_temp[cnt][1] = hand[j][1];
					cnt++;
				}
		}
	}
	return cnt;
}