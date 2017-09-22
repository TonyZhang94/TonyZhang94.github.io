#include <stdio.h>

#define MAX 501

int ngirls, nboys;
int girls[MAX], boys[MAX];
int bond[MAX][MAX];
int marching[MAX];

int find(int girlNo) {
	int i;
	for (i = 1;i <= nboys;i++) {
		if (bond[girlNo][i] == 1 && marching[i] == -1) {
			marching[i] = 1;
			if (boys[i] == -1 || find(boys[i]) == 1) {
				boys[i] = girlNo;
				return 1;
			}
		}
	}

	return 0;
}

int main() {
	int K;
	int cnt;

	int i, j, k;

	while (scanf("%d", &K) != EOF && K) {
		cnt = 0;

		scanf("%d%d", &ngirls, &nboys);
		
		for (i = 0;i < MAX;i++)
			for (j = 0;j < MAX;j++)
				bond[i][j] = -1;

		for (k = 1;k <= K;k++) {
			scanf("%d%d", &i, &j);
			bond[i][j] = 1;
		}

		for (i = 0;i < MAX;i++) {
			boys[i] = -1;
			girls[i] = -1;
		}

		for (i = 1;i <= ngirls;i++) {
			for (j = 0;j < MAX;j++)
				marching[j] = -1;

			if (find(i) == 1) {
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
