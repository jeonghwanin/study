#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node {
	int z,y, x;
}Node;

vector<vector<vector<int>>>adj(100, vector<vector<int>>(100, vector<int>(100, 0)));

int M, N, H; // 가로, 세로, 높이
int cnt;
int visited[100][100][100];

void input();
void ff();
void sv();
 
int main(void) {
	input();
	sv();
	return 0;
}

void input() {
	cin >> M >> N >> H;
	for (int h = 0; h < H; ++h) {
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				cin >> adj[h][n][m];
			}
		}
	}
}
void ff() {
	queue<Node>q;
	for (int h = 0; h < H; ++h) {
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				if (adj[h][n][m] == 1) {
					q.push({ h,n,m });
				}
			}
		}
	}
	int dir[6][3] = { -1,0,0,0,1,0,0,0,1,0,-1,0,0,0,-1,1,0,0 };
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 6; ++i) {
			int dz = now.z + dir[i][0];
			int dy = now.y + dir[i][1];
			int dx = now.x + dir[i][2];

			if (dz < 0 || dy < 0 || dx < 0 || \
				dz >= H || dy >= N || dx >= M || \
				adj[dz][dy][dx] || visited[dz][dy][dx]) continue;

			visited[dz][dy][dx] = visited[now.z][now.y][now.x] + 1;
			if (visited[dz][dy][dx] > cnt) cnt = visited[dz][dy][dx];
			adj[dz][dy][dx] = 1;
			q.push({ dz,dy,dx });
		}

		

	}
}
void sv() {
	

	ff();
	for (int h = 0; h < H; ++h) {
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				if (!adj[h][n][m]) {
					cout << -1;
					return;
				}
			}
		}
	}
	cout << cnt;
	return;
}