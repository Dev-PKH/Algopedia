#include <bits/stdc++.h>
using namespace std;

int adj_matrix[1002][1002]; // 노드의 연결 상태
bool vis[1002]; // 해당 정점의 방문 여부
int n,m, cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	int u,v;
	for(int i=0; i<m; i++)
	{
		cin >> u >> v;
		adj_matrix[u][v] = 1;
		adj_matrix[v][u] = 1;
	}
	
	for(int i=1; i<=n; i++)
	{
		if(vis[i]) continue;
		cnt++;
		queue<int> q;
		q.push(i);
		vis[i] = true;
		
		while(!q.empty())
		{
			int cur = q.front(); q.pop();
			for(int j=1; j<=n; j++)
			{
				if(adj_matrix[cur][j] == 1 && !vis[j]){
					q.push(j);
					vis[j] = true;
				}
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}