#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pa pair<int,int>

vector<pa> vec[1005]; // cost, Vertex;
priority_queue<pa, vector<pa>, greater<pa>> pq;
int d[1005];
int pre[1005];
int v,e, inf = 0x3fffffff;
int st, en;

void dijkstra(int idx)
{
	pq.push({0,idx});
	
	while(!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if(d[cur.Y] != cur.X) continue;
		for(auto c : vec[cur.Y])
		{
			if(d[c.Y] <= d[cur.Y] + c.X) continue;
			d[c.Y] = d[cur.Y] + c.X;
			pre[c.Y] = cur.Y;
			pq.push({d[c.Y], c.Y});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e;
	
	fill(d, d+v+1, inf);
	
	while(e--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		vec[a].push_back({c,b});
	}
	
	cin >> st >> en;
	d[st] = 0;
	
	dijkstra(st);
	
	cout << d[en] << '\n';
	
	int x = en;
	vector<int> idx(1,x); 
	while(x!=st)
	{
		x = pre[x];
		idx.push_back(x);
	}
	reverse(idx.begin(), idx.end());
	
	cout << idx.size() << '\n';
	for(auto i : idx)
		cout << i << ' ';
	
	return 0;
}