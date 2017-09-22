#include <stdio.h>

#define MAXSCORE 40 
#define MAXSUB 8

int main() {
	int T;
	int n, kk;
	int a[MAXSUB], b[MAXSUB];

	int i, j, k;
	int c1[MAXSCORE+1], c2[MAXSCORE+1];

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &kk);

		for (i = 0;i <= MAXSCORE;i++)
			c1[i] = c2[i] = 0;

		for (i = 0;i < kk;i++)
			scanf("%d%d", &a[i], &b[i]);

		for (i = 0;i <= a[0]*b[0] && i <= n;i+=a[0])
			c1[i] = 1;

		for (i = 1;i < kk;i++) {
			for (j = 0;j <= n;j++)
				for (k = 0;k <= a[i]*b[i] && k+j <= n;k+=a[i])
					c2[k+j] += c1[j];

			for (j = 0;j <= n;j++) {
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}

		printf("%d\n", c1[n]);
	}

	return 0;
}
