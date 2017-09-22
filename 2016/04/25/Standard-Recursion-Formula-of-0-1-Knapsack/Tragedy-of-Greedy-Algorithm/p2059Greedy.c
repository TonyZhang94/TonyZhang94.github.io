#include <stdio.h>

#define MAX 100

int main() {
	int L;
	int N, C, T;
	int VR, VT1, VT2;
	double TR, TT, TT1, TT2;
	int dis[MAX], a, b;

	int remain, r1, r2;

	int i;

	while (scanf("%d%d%d%d%d%d%d", &L, &N, &C, &T, &VR, &VT1, &VT2) != EOF) {
		a = b = 0;
		for (i = 0;i < N;i++) {
			scanf("%d", &b);
			dis[i] = b - a;
			a = b;
		}
		dis[i] = L - a;

		TR = L*1.0/VR;
		
		if (dis[0] < C) {
			TT = dis[0]*1.0/VT1;
			remain = C - dis[0];
		}
		else {
			TT = C*1.0/VT1 + (dis[0]-C)*1.0/VT2;
			remain = 0;
		}

		for (i = 1;i <= N;i++) {
			TT1 = T;
			r1 = C;
			r2 = remain;
			if (dis[i] < C) {
				TT1 = TT1 + dis[i]*1.0/VT1;
				r1 = C - dis[i];
			}
			else {
				TT1 = TT1 + C*1.0/VT1 + (dis[i]-C)*1.0/VT2;
				r1 = 0;
			}

			if (dis[i] < remain) {
				TT2 = dis[i]*1.0/VT1;
				r2 = remain - dis[i];
			}
			else {
				TT2 = remain*1.0/VT1 + (dis[i]-remain)*1.0/VT2;
				r2 = 0;
			}

			if (TT1 < TT2) {
				TT += TT1;
				remain = r1;
			}
			else {
				TT += TT2;
				remain = r2;
			}

			if (TT > TR)
				break;
		}

		if (TT < TR)
			printf("What a pity rabbit!\n");
		else
			printf("Good job,rabbit!\n");
	}

	return 0;
}
