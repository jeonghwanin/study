#include <iostream>
#include <queue>

using namespace std;

void input();
void bfs();
void sv();

int N, K; //수빈점, 동생점

int visited[100001];

int main(void) {
	input();
	sv();
}

void input() {
	cin >> N >> K;
}
void bfs() {
	queue<int>q;
	q.push(N);
	visited[N] = 1;
	while (!q.empty()) {
		int now = q.front();q.pop();
		if (now == K) { cout << visited[now] - 1; return; }
		int d = now + 1;
		if (d >= 0 && d <= 100000 && !visited[d]) {
			visited[d] = visited[now] +  1;
			q.push(d);
		}
		d = now - 1;
		if (d >= 0 && d <= 100000 && !visited[d]) {
			visited[d] = visited[now] + 1;
			q.push(d);
		}
		d = now * 2;
		if (d >= 0 && d <= 100000 && !visited[d]) {
			visited[d] = visited[now] + 1;
			q.push(d);
		}
	}
	
}
void sv() {
	bfs();
}