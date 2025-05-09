#include <bits/stdc++.h>
using namespace std;

#define pa pair<int,int>

priority_queue<pa, vector<pa>, greater<pa>> pq;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	while(n--)
	{
		int num;
		cin >> num;
		
		if(num == 0)
		{
			if(pq.empty()) cout << 0 << '\n';
			else 
			{
				auto p = pq.top(); pq.pop();
				cout << p.first * p.second << '\n';
			}
		}
		else
		{
			if(num < 0) pq.push({abs(num), -1});
			else pq.push({num,1});
		}
	}
	
	
	return 0;
}