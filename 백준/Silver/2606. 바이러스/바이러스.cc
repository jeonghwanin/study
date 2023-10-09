#include <iostream>
#include <vector>

using namespace std;

void input();
void dfs();
void sv();


int N, E; //컴퓨터수, 간선수
vector<int>adj[101];
vector<int>visited(101,0); // 방문벡터
int cnt; // 감염수

int main() {
	input();
	sv();
}

void input() {
	cin >> N >> E;
	for (int e = 0; e < E; ++e) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

}

void dfs(int n) {
	visited[n] = 1;
	++cnt;
	for (int i = 0; i < adj[n].size(); ++i) {
		if (!visited[adj[n][i]]) dfs(adj[n][i]);
	}
	return;
}

void sv() {
	dfs(1);
	cout << cnt-1;
}

