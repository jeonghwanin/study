#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
	int n;
	int y, x;
} Node;

Node s, e;
Node c[101];
int visited[102];
int N;
int B = 20;
int T;

void input();
bool check(Node x);
void sv();

int main(void) {
	cin >> T;
	for (int t = 0; t < T; ++t) {
		input();
		sv();
	}
}

void input() {
	cin >> N;
	cin >> s.y >> s.x;
	for (int n = 1; n <= N; ++n) {
		cin >> c[n].y >> c[n].x;
		visited[n] = 0;
	}
	cin >> e.y >> e.x;
}

bool check(Node x) {
	int dif = e.y - x.y;
	if (dif < 0) dif = -1 * dif;
	int dif2 = e.x - x.x;
	if (dif2 < 0) dif2 = -1 * dif2;
	int sum = dif + dif2;
	if (sum <= 1000) {
		cout << "happy" << '\n';
		return true;
	}
	else {
		return false;
	}
			
}

void sv() {
	queue<Node>q;
	q.push(s);
	visited[0] = 1;
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (check(now)) return;
		for (int n = 1; n <= N; ++n) {
			if (visited[n]) continue;
			int dy = now.y - c[n].y > 0 ? now.y - c[n].y : -1 * (now.y - c[n].y);
			int dx = now.x - c[n].x > 0 ? now.x - c[n].x : -1 * (now.x - c[n].x);
			if (dy + dx > 1000) continue;
			visited[n] = 1;
			q.push(c[n]);
		}
	}
	cout << "sad" << '\n';
	return;
}

