#include <stdio.h>

#define MAX 1005

int main() {
	int n;
	int N;
	int V;
	int values[MAX];
	int weight[MAX];
	int dp[MAX][MAX];

	int i,j;
	int t1,t2;

	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &N, &V);

		for (i = 1;i <= N;i++)
			scanf("%d", &values[i]);

		for (i = 1;i <= N;i++) 
			scanf("%d", &weight[i]);

		for (j = 0;j < MAX;j++) {
			dp[0][j] = 0;
		}

		for (i = 1;i <= N;i++) {
			for (j = 0;j <= V;j++) {
				if (weight[i] > j) {
					dp[i][j] = dp[i-1][j];
				}
				else {
					t1 = dp[i-1][j];
					t2 = dp[i-1][j-weight[i]] + values[i];

					if (t1 > t2)
						dp[i][j] = t1;
					else 
						dp[i][j] = t2;
				}
			}
		}

		printf("%d\n",dp[N][V]);

	}

	return 0;
}
