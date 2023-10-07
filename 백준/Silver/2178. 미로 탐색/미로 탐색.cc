#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void input();
void ff();
void sv();


int N, M; //N 행수 M 열수
string str[101]; // 101*101 맵
vector<vector<int>>visited(101, vector<int>(101, 0)); //방문벡터
pair<int, int>node; //좌표

int main(void) {
	input();
	sv();
}

void input() {
	cin >> N >> M;
	for (int n = 0; n < N; ++n) {
		cin >> str[n];
	}
	return;
}

void sv() {
	ff();
	cout << visited[N-1][M-1] << '\n';
}

void ff() {
	queue<pair<int,int>>q;
	q.push({ 0,0 });
	visited[0][0] = 1;
	int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		if (now.first == N-1 && now.second == M-1) return;
		for (int i = 0; i < 4; ++i) {
			int dy = now.first + dir[i][0];
			int dx = now.second + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= N || dx >= M || visited[dy][dx] || str[dy][dx] == '0') continue;
			visited[dy][dx] = visited[now.first][now.second] + 1;
			q.push({ dy , dx });
		}
	}
}