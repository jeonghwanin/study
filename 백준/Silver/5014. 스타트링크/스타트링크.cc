#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D; // 총층, 시작층, 도착층, 위층, 아래층
int visited[1000001];

void input();
void bfs();
void sv();

int main(void) {
	input();
	sv();
}

void input() {
	cin >> F >> S >> G >> U >> D;
}

void bfs() {
	queue<int>q;
	q.push(S);
	visited[S] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == G) return;
		int d = now + U;
		if (!(d <= 0 || d > F || visited[d])) {
			q.push(d);
			visited[d] = visited[now] + 1;
		}
		d = now - D;
		if (!(d <= 0 || d > F || visited[d])) {
			q.push(d);
			visited[d] = visited[now] + 1;
		}
	}
}

void sv() {
	bfs();
	if (!visited[G]) cout << "use the stairs";
	else cout << visited[G]-1;
}