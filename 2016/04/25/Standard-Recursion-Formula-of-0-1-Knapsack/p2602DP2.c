#include <stdio.h>

#define MAX 1005

int main() {
	int n;
	int N, V;
	int values[MAX];
	int weight[MAX];
	int fn[MAX];

	int i, j;

	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &N, &V);

		for (i = 1;i <= N;i++)
			scanf("%d", &values[i]);

		for (i = 1;i <= N;i++)
			scanf("%d", &weight[i]);

		for (i = 0;i < MAX;i++)
			fn[i] = 0;

		for (i = 1;i <= N;i++) {
			for (j = V;j >= weight[i];j--) {
				if (fn[j-weight[i]]+values[i] > fn[j])
					fn[j] = fn[j-weight[i]] + values[i];
			}
		}

		printf("%d\n",fn[V]);
	}

	return 0;
}
