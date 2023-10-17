#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
	int y, x;
}Node;

int map[100][100];
int visited[100][100];
int N;
int cnt = 1;

void input();
void init();
void ff(int y, int x, int h);
void sv();

int main(void) {
	input();
	sv();
	cout << cnt;
}


void input() {
	cin >> N;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> map[y][x];
		}
	}
}

void init() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			visited[y][x] = 0;
		}
	}
}

void ff(int y, int x, int h) {
	queue<Node>q;
	q.push({ y,x });
	visited[y][x] = 1;
	int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int dy = now.y + dir[i][0];
			int dx = now.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= N || dx >= N || map[dy][dx] <= h || visited[dy][dx]) continue;
			visited[dy][dx] = 1;
			q.push({ dy,dx });
		}
	}
	return;
}

void sv(){
	for (int i = 1; i < 100; ++i) {
		init();
		int sum = 0;
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				if (!visited[y][x] && map[y][x] > i ) {
					ff(y, x, i);
					++sum;
				}
			}
		}
		if (cnt < sum) cnt = sum;
	}
}
