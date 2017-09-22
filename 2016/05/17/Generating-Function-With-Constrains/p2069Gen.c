#include <stdio.h>

#define POWER 250
#define MAX 100
#define NCOINS 5

int c1[POWER+1][MAX+1], c2[POWER+1][MAX+1];
int table[POWER+1];

const int coins[NCOINS+1] = {
	0, 1, 5, 10, 25, 50
};

void InitTable() {
	int i, j, k, u, v;

	for (i = 0;i <= POWER;i++) 
		for (j = 0;j <= MAX;j++)
			c1[i][j] = c2[i][j] = 0;

	c1[0][0] = 1;
	for (i = 1;i <= NCOINS;i++) { 
		for (j = 0;j <= POWER;j++) 
			for (k = 0;k*coins[i]+j <= POWER;k++)
				for (u = 0;u+k <= MAX;u++)
					c2[j+k*coins[i]][k+u] += c1[j][u];

		for (j = 0;j <= POWER;j++) {
			for (k = 0;k <= MAX;k++) {
				c1[j][k] = c2[j][k];
				c2[j][k] = 0;
			}
		}
	}

	table[0] = 1;
	for (i = 1;i <= POWER;i++) {
		table[i] = 0;
		for (j = 0;j <= POWER;j++)
			table[i] += c1[i][j];
	}
}

int main() {
	int n;

	InitTable();

	while (scanf("%d", &n) != EOF) {
		printf("%d\n", table[n]);
	}

	return 0;
}
