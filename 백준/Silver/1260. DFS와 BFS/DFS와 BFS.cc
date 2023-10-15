#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void input();
void sv();
void dfs();
void bfs();

int N, M, V; // 정점수,간선수,시작정점번호
int dfs_visited[1001], bfs_visited[1001]; //dfs,bfs 방문정점
vector<int> dfs_ans, bfs_ans; //dfs 경로, bfs 경로
vector<vector<int>>adj(1001, vector<int>(1001, 0)); //1001*1001 인접행렬 그래프
queue<int>q;

int main(void) {
	input();
	sv();
}

void input() {
	cin >> N >> M >> V;
	int from, to;
	for (int n = 0; n < M; ++n) {
		cin >> from >> to;
		adj[from][to] = 1;
		adj[to][from] = 1;
	}
}

void dfs(int start) {
	if (dfs_visited[start]) return;
	dfs_visited[start] = 1;
	dfs_ans.push_back(start);
	for (int i = 1; i < 1001; ++i) {
		if (adj[start][i]) dfs(i);
	}
	return;
}

void bfs(int start) {
	q.push(start);
	bfs_visited[start] = 1;
	
	while (!q.empty()) {
		int from = q.front();q.pop();
		bfs_ans.push_back(from);
		for (int i = 1; i < 1001; ++i) {
			if (adj[from][i] && !bfs_visited[i]) {
				bfs_visited[i] = 1;
				q.push(i);
			}
		}
	}
	return;
}

void sv() {
	dfs(V);
	bfs(V);
	for (int i = 0; i < dfs_ans.size(); ++i) {
		cout << dfs_ans[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < bfs_ans.size(); ++i) {
		cout << bfs_ans[i] << ' ';
	}
	cout << '\n';
}