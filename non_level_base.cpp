void non_level_base(int(*base)[2], int level) {
	int temp[1][2];
	for(int i=11;i>=0;i--)//ð�ݽ�������ԭ��ԭ��λ��
		if (base[i][0] > level) {
			temp[0][0] = base[i][0];
			temp[0][1] = base[i][1];
			base[i][0] = base[i + 1][0];
			base[i][1] = base[i + 1][1];
			base[i + 1][0] = temp[0][0];
			base[i + 1][1] = temp[0][1];
}

}
