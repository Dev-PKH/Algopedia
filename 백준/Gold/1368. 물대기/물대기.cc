#include <bits/stdc++.h>
using namespace std;

#define tp tuple<int,int,int>
#define X first
#define Y second

priority_queue<tp, vector<tp>, greater<tp>> pq; // cost, i, j
vector<pair<int,int>> adj[302]; // cost, nearVertex
bool vis[302];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		int c;
		cin >> c;
		adj[n+1].push_back({c,i});
		adj[i].push_back({c,n+1});
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			int c;
			cin >> c;
			adj[i].push_back({c,j});
		}
	}
	
	vis[1] = 1;
	for(auto cur : adj[1])
		pq.push({cur.X, 1, cur.Y});
		
	int ans=0,cnt=0;
	
	while(cnt < n)
	{
		int cost, a, b;
		tie(cost,a,b) = pq.top(); pq.pop();
		if(vis[b]) continue;
		cnt++;
		ans += cost;
		vis[b] = 1;
		for(auto cur : adj[b])
			if(!vis[cur.Y]) pq.push({cur.X,b, cur.Y});
	}
	
	cout << ans;
	
	return 0;
}