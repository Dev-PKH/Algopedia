#include <bits/stdc++.h>
using namespace std;

#define mx 100005

int vis[mx];

int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<int> q;
	fill(vis, vis+mx, -1);
	
	cin >> n >> k;
  
	q.push(n);
	vis[n] = 0;
	
	while(vis[k] == -1)
	{
		int cur = q.front(); q.pop();
		for(int i: {cur-1, cur+1, cur*2})
		{
			if(i<0 || i > mx) continue;
			if(vis[i] != -1) continue;

			vis[i] = vis[cur] + 1;
			q.push(i);
		}
	}
	
	cout << vis[k];
	
	return 0;
}