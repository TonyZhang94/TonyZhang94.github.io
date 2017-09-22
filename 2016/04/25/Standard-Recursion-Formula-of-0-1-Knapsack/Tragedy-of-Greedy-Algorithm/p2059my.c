#include <stdio.h>

#define MAX 100

int main() {
	int L;
	int N, C, T;
	int VR, VT1, VT2;
	int dis[MAX], a, b;
	int remain;

	double TT, TR, t;
	int flag;

	int i ,j, inx;

	while (scanf("%d%d%d%d%d%d%d", &L, &N, &C, &T, &VR, &VT1, &VT2) != EOF) {
		a = b = 0;
		for (i = 0;i < N;i++) {
			scanf("%d", &b);
			dis[i] = b-a;
			a = b;
		}
		dis[i] = L-a;

		for (i = 1;i < N-1;i++) {
			inx = i;
			for (j = i+1;j < N;j++) {
				if (dis[inx] > dis[j])
					inx = j;
			}

			if (inx != i) {
				dis[inx] = dis[i] + dis[inx];
				dis[i] = dis[inx] - dis[i];
				dis[inx] = dis[inx] - dis[i];
			}
		}

		for (i = 0;i <= N;i++)
// printf("%d=%d\n", i, dis[i]);

		TR = L*1.0 / VR;
// printf("TR=%.2lf\n",TR);
		flag = 0;

		for (i = 0;i <= N;i++) {
			TT = 0.0;
			remain = C;
			if (dis[0] < remain) {
				TT = TT + dis[0]*1.0/VT1;
				remain -= dis[0];
			}
			else {
				TT = TT + remain*1.0/VT1 + (dis[0]-remain)*1.0/VT2;
				remain = 0;
			}
// printf("0TT=%.2lf\n",TT);

			for (j = 1;j <= i;j++) {
				if (dis[j] < remain) {
					TT = TT + dis[j]*1.0/VT1;
					remain -= dis[j];
				}
				else {
					TT = TT + remain*1.0/VT1 + (dis[j]-remain)*1.0/VT2;
					remain = 0;
				}
// printf("%d-TT=%.2lf\n", j, TT);
			}

			if (i != N) {
				TT += T;
				remain = C;
			}

			for (j = i+1;j < N;j++) {
				if (dis[j] < C) {
					TT = TT + dis[j]*1.0/VT1;
				}
				else {
					TT = TT + C*1.0/VT1 + (dis[j]-C)*1.0/VT2;
				}

				TT += T;
// printf("%dTT=%.2lf\n", j, TT);
			}

			if (i != N) {
				if (dis[j] < C) {
					TT = TT + dis[j]*1.0/VT1;
				}
				else {
					TT = TT + C*1.0/VT1 + (dis[j]-C)*1.0/VT2;
				}
// printf("**TT=%.2lf\n",TT);
				
				if (TT < TR) {
					printf("What a pity rabbit!\n");
					flag = 1;
				}
			}

			if (flag == 1) 
				break;
		}

		if (flag != 1)
			printf("Good job,rabbit!\n");
	}

	return 0;
}
