#include <stdio.h>

#define MAX 1005

int N;
int stu[MAX];
int bond[MAX][MAX];
int matching[MAX];

int find(int stuNo) {
	int i;
	for (i = 0;i < N;i++) {
		if (bond[stuNo][i] == 1 && matching[i] == -1){
			matching[i] = 1;
			if (stu[i] == -1 || find(stu[i]) == 1) {
				stu[i] = stuNo;
				return 1;
			}
		}
	}

	return 0;
}

int main() {
	int cnt;
	int i, j, k, n;

	while (scanf("%d", &N) != EOF) {
		cnt = 0;

		for (i = 0;i < MAX;i++) {
			stu[i] = -1;
			for (j = 0;j < MAX;j++)
				bond[i][j] = -1;
		}

		for (i = 0;i < N;i++) {
			scanf("%d: (%d)", &j, &n);
			while (n--) {
				scanf("%d", &k);
				bond[j][k] = 1;
				bond[k][j] = 1;
			}
		}

for (i = 0;i < N;i++)
	for (j = 0;j < N;j++)
		for (i = 0;i < N;i++) {
			for (j = 0;j < N;j++) {
				matching[j] = -1;
			}

			if (find(i) == 1) {
				cnt++;
			}
		}

		printf("%d\n", N-cnt/2);
	}

	return 0;
}
