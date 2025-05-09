#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		
		queue<pair<int,int>> q;
		vector<int> v;
		for(int i=0; i<n; i++)
		{
			int num;
			cin >> num;
			v.push_back(num);
			q.push({num, i});
		}
		
		sort(v.begin(), v.end(), greater<>());
		
		int cnt = 0;
		while(!q.empty())
		{
			auto a = q.front();
			q.pop();
			if(v[0] == a.X)
			{
				cnt++;
				if(a.Y == m)
				{
					cout << cnt << '\n';
					break;
				}
				else v.erase(v.begin());
			}
			else q.push(a);
		}
	}
	
	
	return 0;
}