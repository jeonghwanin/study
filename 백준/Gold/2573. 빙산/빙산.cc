#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
	int y, x;
}Node;

int N, M;
int map[300][300];
int next_map[300][300];
int cnt, ans;
bool is_finish;

void input();
void check(int n, int m);
void check2();
void sv();

int main(void) {
	input();
	sv();
}

void input() {
	cin >> N >> M;
	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			cin >> map[n][m];
			next_map[n][m] = map[n][m];
		}
	}
}
void check(int n, int m) {
	int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
	int dif = 0;
	for (int i = 0; i < 4; ++i) {
		int dy = n + dir[i][0];
		int dx = m + dir[i][1];
		if (dy < 0 || dx < 0 || dy >= N || dx >= M || map[dy][dx]) continue;
		++dif;
	}
	next_map[n][m] = map[n][m] - dif;
	if (next_map[n][m] < 0) next_map[n][m] = 0;
}

void check2() {
	int f = 0;
	int visited[300][300];
	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			visited[n][m] = 0;
		}
	}
	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			if (map[n][m] && !visited[n][m]) {
				++f;
				queue<Node>q;
				q.push({ n,m });
				visited[n][m] = 1;
				int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
				while (!q.empty()) {
					Node now = q.front(); q.pop();
					for (int i = 0; i < 4; ++i) {
						int dy = now.y + dir[i][0];
						int dx = now.x + dir[i][1];
						if (dy < 0 || dx < 0 || dy >= N || dx >= M || visited[dy][dx] || !map[dy][dx]) continue;
						visited[dy][dx] = 1;
						q.push({ dy, dx });
					}
				}
			}
		}
	}
	if (f >= 2) {
		ans = cnt;
		is_finish = true;
	}
}
void sv() {
	for (;;) {
		is_finish = true;
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				if (!map[n][m]) continue;
				is_finish = false;
				check(n, m);
			}
		}
		if (!is_finish) {
			for (int n = 0; n < N; ++n) {
				for (int m = 0; m < M; ++m) {
					map[n][m] = next_map[n][m];
				}
			}
			++cnt;
			check2();
		}
	
		
		if (is_finish) break;
	}
	cout << ans;

}




