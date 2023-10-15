#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input();
void bfs();
void sv();


int N, M; // Node, Edge
int S, E; // 관계 구할 사람
vector<int>adj[101]; // graph
int visited[101]; //방문 배열
int main(void) {
	input();
	sv();
}


void input(){
	cin >> N >> S >> E;
	cin >> M;
	int x, y;
	for (int m = 0; m < M; ++m) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	return;
}

void bfs() {
	queue<int>q;
	q.push(S);
	visited[S] = 1;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < adj[now].size(); ++i) {
			if (visited[adj[now][i]]) continue;
			visited[adj[now][i]] = visited[now] + 1;
			q.push(adj[now][i]);
			if (adj[now][i] == E) return; 
		}
	}

}

void sv() {
	bfs();
	if (visited[E] == 0) {
		cout << -1;
	}
	else {
		cout << visited[E] - 1;
	}
	return;
}