#include <stdio.h>

#define MAXP 10000
#define MAXN 100000

int nblack, nwhite;
int blackMwhite[MAXN];
int blacks[MAXN][2], whites[MAXN][2];
int bond[MAXP][MAXP];
int matching[MAXN];

int find(int x) {
	int i;
	for (i = 0;i < nblack;i++) {
		if (bond[i][x] == 1 && matching[i] == -1) {
			matching[i] = 1;
			if (blackMwhite[i] == -1 || find(blackMwhite[i]) == 1) {
				blackMwhite[i] = x;
				return 1;
			}
		}
	}

	return 0;
}

int main() {
	int T;
	int cnt;

	int i, j, k;

	scanf("%d", &T);
	while (T--) {
		cnt = 0;

		scanf("%d%d", &nblack, &nwhite);

		for (i = 0;i < MAXP;i++)
			for (j = 0;j < MAXP;j++)
				bond[i][j] = -1;

		for (i = 0;i < MAXN;i++) 
			blackMwhite[i] = -1;

		for (i = 0;i < nblack;i++)
			scanf("%d%d", &blacks[i][0], &blacks[i][1]);

		for (i = 0;i < nwhite;i++) 
			scanf("%d%d", &whites[i][0], &whites[i][1]);

		for (i = 0;i < nblack;i++) {
			for (j = 0;j < nwhite;j++) {
				if (blacks[i][0] <= whites[j][0] 
				 && blacks[i][1] <= whites[j][1]) {
					bond[i][j] = 1;
				}
			}
		}

		for (i = 0;i < nwhite;i++) {
			for (j = 0;j < MAXN;j++)
				matching[j] = -1;
			if (find(i) == 1)
				cnt++;
		}

		printf("%d\n", cnt);

	}

	return 0;
}
