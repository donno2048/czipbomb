#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int f(long long x[], long long y) {
	int output = 0;
	for (int i = 0; i < 33; i++) output ^= x[i] * (y >> i & 1);
	return output;
}
int main(int argc, char *argv[]) {
	int i, j;
	long long A = (1LL << 32) - 1, B = strtoll(argv[1], 0, 10), C = strtoll(argv[2], 0, 10), D[33], d[33], E[8], F = C * 1032 - 14447, G[33], g[33], H = F;
	for (i = 0; i < 33; i++) D[i] = 1LL << i;
	for (i = 0; i < 8; i++) {
		E[i] = 0;
		for (j = 0; j < 8; j++) E[i] = E[i] >> 1 ^ 3988292384 * ((1 << i >> j ^ E[i]) & 1);
		G[i] = E[i];
	}
	for (i = 0; i < 24; i++) G[i + 8] = 1LL << i;
	G[32] = A + 1;
	while (F) {
		for (i = 0; i < 33; i++) d[i] = D[i];
		for (i = 0; i < 33; i++) g[i] = G[i];
		if (F & 1) for (i = 0; i < 33; i++) D[i] = f(d, G[i]);
		for (i = 0; i < 33; i++) G[i] = f(g, G[i]);
		F >>= 1;
	}
	int I = ~f(D, 2 * A + 1) & A;
	long long J = printf("PK\3\4\x14%c%c%c\x08%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\1%c%c%c0\xed\xc0\x81\x08%c%c%c\xc0\xb0\xfbS_d\x0b", 0, 0, 0, 0, 0, 0, 0, 0, I & 255, I >> 8 & 255, I >> 16 & 255, I >> 24 & 255, C & 255, C >> 8 & 255, C >> 16 & 255, C >> 24 & 255, H & 255, H >> 8 & 255, H >> 16 & 255, H >> 24 & 255, 0, 0, 0, 0, 0, 0);
	for (i = 0; i < C - 15; i++) J += printf("%c", 0);
	J += printf("`");
	long long K = J;
	for (i = 0; i < B; i++) {
		char num[100];
		sprintf(num, "%d", i);
		int size = strlen(num);
		J += printf("PK\1\2\x14%c\x14%c%c%c\x08%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0, 0, 0, 0, 0, 0, 0, 0, 0, I & 255, I >> 8 & 255, I >> 16 & 255, I >> 24 & 255, C & 255, C >> 8 & 255, C >> 16 & 255, C >> 24 & 255, H & 255, H >> 8 & 255, H >> 16 & 255, H >> 24 & 255, size & 255, size >> 8 & 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) + printf(num);
	}
	printf("PK\5\6%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0, 0, 0, 0, B & 255, B >> 8 & 255, B & 255, B >> 8 & 255, J - K & 255, J - K >> 8 & 255, J - K >> 16 & 255, J - K >> 24 & 255, K & 255, K >> 8 & 255, K >> 16 & 255, K >> 24 & 255, 0, 0);
	return 0;
}