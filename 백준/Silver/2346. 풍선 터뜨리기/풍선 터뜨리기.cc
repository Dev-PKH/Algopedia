#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

deque<pair<int,int>> dq;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		int num;
		cin >> num;
		dq.push_back({num,i});
	}
	
	while(!dq.empty())
	{
		auto cur = dq.front(); dq.pop_front();
		cout << cur.Y << ' ';
		
		if(cur.X > 0)
		{
			for(int i=0; i<cur.X-1; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			for(int i=cur.X; i<0; i++)
			{	
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	
	return 0;
}