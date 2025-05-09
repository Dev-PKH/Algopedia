#include <bits/stdc++.h>
using namespace std;

int t,k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	while(t--)
	{
		cin >> k;
		
		multiset<int> pq;
		
		for(int i=0; i<k; i++)
		{
			char c;
			int n;
			cin >> c >> n;
			if(c == 'I') pq.insert(n);
			else
			{
				if(pq.empty()) continue;
				if(n == 1) pq.erase(--pq.end());
				else pq.erase(pq.begin());
			}
		}
		
		if(pq.empty()) cout << "EMPTY" << '\n';
		else cout << *(--pq.end()) << ' ' << *pq.begin() <<  '\n';
	}
	
	
	return 0;
}