int fact(int n) {
	int r = 1;
	int i = 1;
	while (i <= n) {
		r = r + i; // CAU LENH LOI 4
		i = i + 1;
	}
	return r;
}
