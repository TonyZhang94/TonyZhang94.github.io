#include <stdio.h>

#define MAX 105
#define INF 1000000

int main() {
	int L;
	int N, C, T;
	int VR, VT1, VT2;
	int dis[MAX], map[MAX][MAX];
	double dp[MAX];

	int i, j;
	double t;

	while (scanf("%d%d%d%d%d%d%d", &L, &N, &C, &T, &VR, &VT1, &VT2) != EOF) {
		dis[0] = 0;
		for (i = 1;i <= N;i++) {
			scanf("%d", &dis[i]);
		}
		dis[i] = L;

		for (i = 0;i <= N+1;i++) {
			for (j = i+1;j <= N+1 ;j++) {
				map[i][j] = dis[j] - dis[i];
			}
		}

		for (i = 1;i <= N+1;i++) {
			dp[0] = 0.0;
			dp[i] = INF*1.0;

			for (j = 0;j < i;j++) {
				if (map[j][i] < C)
					t = map[j][i]*1.0/VT1;
				else
					t = C*1.0/VT1 + (map[j][i]-C)*1.0/VT2;

				if (j != 0)
					t += T;

				if (dp[i] > dp[j] + t)
					dp[i] = dp[j] + t;
			}
		}

		printf(dp[N+1]<L*1.0/VR ? "What a pity rabbit!\n":"Good job,rabbit!\n");
	}

	return 0;
}
