#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Node {
	int y, x;
} Node;

void input();
void ff(Node start);
void sv();

int N; // 지도 크기
string map[25]; //맵
int cnt; //섬 개수
vector<int>ans; //섬 오름차순
vector<vector<int>>visited(25, vector<int>(25, 0));



int main(void) {
	input();
	sv();
}

void input() {
	cin >> N;
	for (int n = 0; n < N; ++n) cin >> map[n];
}

void ff(Node start) {
	queue<Node>q;
	q.push(start);
	visited[start.y][start.x] = 1;
	int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
	int sum = 0;
	while (!q.empty()) {
		Node from = q.front(); q.pop();
		++sum;
		for (int i = 0; i < 4; ++i) {
			int dy = from.y + dir[i][0];
			int dx = from.x + dir[i][1];
			if (dy < 0 || dx < 0 || dy >= N || dx >= N || visited[dy][dx] || map[dy][dx] == '0') continue;
			visited[dy][dx] = visited[from.y][from.x] + 1;
			q.push({ dy,dx });
		}
	}
	ans.push_back(sum);
}

void sv() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (visited[y][x] || map[y][x] == '0') continue;
			ff({ y,x });
			++cnt;
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt<<"\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << '\n';
	}
}