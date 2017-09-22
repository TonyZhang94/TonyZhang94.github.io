#include <stdio.h>

#define MAX 8

int main() {
	int T;
	int n, k;
	int a[MAX], b[MAX];
	int cnt;

	int i, j;
	int x0, x1, x2, x3, x4, x5, x6, x7;

	scanf("%d", &T);
	while (T--) {
		cnt = 0;

		scanf("%d%d", &n, &k);

		for (i = 0;i < k;i++)
			scanf("%d%d", &a[i], &b[i]);

		for (i = k;i < MAX;i++)
			a[i] = b[i] = 0;

		for (x0 = 0;x0 <= b[0];x0++)
			for(x1 = 0;x1 <= b[1];x1++)
				for (x2 = 0;x2 <= b[2];x2++)
					for (x3 = 0;x3 <= b[3];x3++)
						for (x4 = 0;x4 <= b[4];x4++)
							for (x5 = 0;x5 <= b[5];x5++)
								for (x6 = 0;x6 <= b[6];x6++)
									for (x7 = 0;x7 <= b[7];x7++) {
										if (x0*a[0]+x1*a[1]+x2*a[2]+x3*a[3]+x4*a[4]+x5*a[5]+x6*a[6]+x7*a[7] == n)
											cnt++;
									}

		printf("%d\n", cnt);
	}

	return 0;
}
