#include <stdio.h>

const int m[5] = {
	50, 25, 10, 5, 1
};

int main() {
	int n;
	int i, j, k, u, v;
	int sum;

	while (scanf("%d" ,&n) != EOF) {
		if (n != 0) {
			sum = 0;
			for (i = n/m[0];i >= 0;i--)
				for (j = (n-i*m[0])/m[1];j >= 0;j--)
					for (k = (n-i*m[0]-j*m[1])/m[2];k >= 0;k--)
						for (u = (n-i*m[0]-j*m[1]-k*m[2])/m[3];u >= 0;u--)
							if (i+j+k+u+(n-i*m[0]-j*m[1]-k*m[2]-u*m[3])/m[4] <= 100)
								sum++;
		}
		else
			sum = 1;

		printf("%d\n", sum);
	}

	return 0;
}
