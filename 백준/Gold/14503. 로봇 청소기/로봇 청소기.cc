#include <iostream>

using namespace std;

int ans, N, M;
int map[50][50];
int r, c;

void input();
void sv();
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int d;

int main(void) {
	input();
	sv();
	return 0;
}

void input() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			cin >> map[n][m];
		}
	}
}
void sv() {

	for (;;) {
		if (!map[r][c]) {
			map[r][c] = 2;
			++ans;
		}
		bool check = false;
		for (int i = 3; i >= 0; --i) {
			int dy = r + dir[(d+i)%4][0];
			int dx = c + dir[(d+i)%4][1];
			if (dy < 0 || dx < 0 || dy >= N || dx >= M || map[dy][dx]) continue;
			check = true;
			r = dy;
			c = dx;
			d = (d + i) % 4;
			break;
		}
		if (!check) {
			int dy = r + dir[(d + 2) % 4][0];
			int dx = c + dir[(d + 2) % 4][1];
			if (dy < 0 || dx < 0 || dy >= N || dx >= M || map[dy][dx] == 1) break;
			r = dy;
			c = dx;
		}

	}

	cout << ans;
}