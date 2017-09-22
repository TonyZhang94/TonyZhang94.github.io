#include <stdio.h>

#define MAX 1000
#define INF 1000000

int T, S, D;
int dis[MAX+1][MAX+1];
int total;

void floyd() {
	int i, j, k;
	int tmp;
	
	for (i = 0;i <= total;i++) {
		for (j = 0;j <= total;j++) {
			if (dis[i][j] == INF) 
				continue;

			for (k = 0;k <= total;k++) {
				tmp = dis[i][j] + dis[j][k];
				if (tmp < dis[i][k])
					dis[i][k] = dis[k][i] = tmp;
			}
		}
	}
}

int main() {
	int i, j, k;
	int a, b, t;
	int min;

	while (scanf("%d%d%d", &T, &S, &D) != EOF) {
		for (i = 0;i <= MAX;i++)
			for (j = 0;j <= MAX;j++)
				dis[i][j] = INF;

		for (i = 0;i <= MAX;i++)
			dis[i][i] = 0;

		total = 0;
		for (i = 1;i <= T;i++) {
			scanf("%d%d%d", &a, &b, &t);
			if (a > total) total = a;
			if (b > total) total = b;
			if (dis[a][b] > t)
				dis[a][b] = dis[b][a] = t;
		}

		for (i = 0;i < S;i++) {
			scanf("%d", &k);
				dis[0][k] = dis[k][0] = 0;
		}

		floyd();

		min = INF;
		for (i = 0;i < D;i++) {
			scanf("%d", &k);
			if (min > dis[0][k])
				min = dis[0][k];
		}

		printf("%d\n", min);
	}

	return 0;
}
