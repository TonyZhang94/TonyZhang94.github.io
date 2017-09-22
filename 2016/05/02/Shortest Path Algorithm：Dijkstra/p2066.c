#include <stdio.h>

#define MAX 1000
#define INF 1000000

int T, S, D;
int total;

int Dj[MAX+1];
int vis[MAX+1];
int m[MAX+1][MAX+1];

void Dijkstra() {
	int i, j, k;
	int inx;
	int min;

	for (i = 1;i < total;i++) {
		min = MAX;
		for (j = 1;j <= total;j++) {
			if (vis[j] == 0 && Dj[j] < min) {
				inx = j;
				min = Dj[j];
			}
		}

		vis[inx] = 1;

		for (j = 1;j <= total;j++) {
			if (vis[j] == 0 && Dj[inx]+m[inx][j] < Dj[j])
				Dj[j] = Dj[inx] + m[inx][j];
		}
	}
}

int main() {
	int i, j, k;
	int a, b, t;
	int shortest;

	while (scanf("%d%d%d", &T, &S, &D) != EOF) {
		for (i = 0;i <= MAX;i++)
			for (j = 0;j <= MAX;j++)
				m[i][j] = INF;

		total = 1;
		for (i = 1;i <= T;i++) {
			scanf ("%d%d%d", &a, &b, &t);
			if (a > total) total = a;
			if (b > total) total = b;
			if (m[a][b] > t)
				m[a][b] = m[b][a] = t;
		}

		for (i = 0;i <= MAX;i++) {
			vis[i] = 0;
			Dj[i] = MAX;
		}

		vis[0] = 1;
		m[0][0] = 0;
		for (i = 0;i < S;i++) {
			scanf("%d", &k);
			m[0][k] = m[k][0] = 0;
			Dj[k] = 0;
		}
		
		Dijkstra();

		shortest = INF;
		for (i = 0;i < D;i++) {
			scanf("%d", &k);
			if (shortest > Dj[k])
				shortest = Dj[k];
		}

		printf("%d\n", shortest);
	}

	return 0;
}
