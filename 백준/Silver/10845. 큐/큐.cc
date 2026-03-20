#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int n;

int main() {
	ios::sync_with_stdio();
	cin.tie(0);
	
	cin >> n;
	
	string s;
	int num;
	
	while(n--)
	{
		cin >> s;
		if(s == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if(s == "pop")
		{
			if(q.empty()) cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if(s == "size")
		{
			cout << q.size() << '\n';
		}
		else if(s == "empty")
		{
			if(q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(s == "front")
		{
			if(q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else
		{
			if(q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
	
	return 0;
}