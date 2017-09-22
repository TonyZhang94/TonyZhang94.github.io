#include <stdio.h>

#define MAX 1000
#define INF 1000000

int T, S, D;
int dis[MAX+1];
int vis[MAX+1];
int m[MAX+1][MAX+1];

int total;

int queue[MAX+1];
int front;
int tail;

void push(int x) {
	queue[tail] = x;
	tail = (tail+1) % (MAX+1);
}

int pop() {
	int x = queue[front];
	front = (front+1) % (MAX+1);
	return x;
}

int empty() {
	if (front == tail)
		return 1;
	else 
		return 0;
}

void spfa() {
	int transfer;
	int i, j, k;

	while (!empty()) {
		transfer = pop();
		vis[transfer] = 0;
		for (i = 1;i <= total;i++) {
			if (dis[i] > dis[transfer]+m[transfer][i]) {
				dis[i] = dis[transfer] + m[transfer][i];

				if (vis[i] == 0) {
					vis[i] = 1;
					push(i);
				}
			}
		}
	}
}

int main() {
	int i, j, k;
	int a, b, t;
	int min;

	while (scanf("%d%d%d", &T, &S, &D) != EOF) {
		for (i = 0;i <= MAX;i++)
			for (j = 0;j <= MAX;j++)
				m[i][j] = INF;

		total = 0;
		for (i = 0;i < T;i++) {
			scanf("%d%d%d", &a, &b, &t);
			if (a > total) total = a;
			if (b > total) total = b;
			if (m[a][b] > t)
				m[a][b] = m[b][a] = t;
		}

		for (i = 0;i <= MAX;i++)
			vis[i] = 0;

		for (i = 0;i <= MAX;i++)
			dis[i] = INF;

		front = tail = 0;
		for (i = 0;i < S;i++) {
			scanf("%d", &k);
			dis[k] = 0;
			vis[k] = 1;
			push(k);
		}

		spfa();

		min = INF;
		for (i = 0;i < D;i++) {
			scanf("%d", &k);
			if (min > dis[k])
				min = dis[k];
		}

		printf("%d\n", min);
	}

	return 0;
}
