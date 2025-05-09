#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	deque<int> dq;
	
	int num, value;
	string s;
	
	cin >> num;
	while(num--)
	{
		cin >> s;
		if(s.compare("push_back") == 0)
		{
			cin >> value;
			dq.push_back(value);
		}
		else if(s.compare("push_front") == 0)
		{
			cin >> value;
			dq.push_front(value);
		}
		else if(s.compare("pop_front") == 0)
		{
			if(dq.empty()) cout << -1 << '\n';
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if(s.compare("pop_back") == 0)
		{
			if(dq.empty()) cout << -1 << '\n';
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if(s.compare("front") == 0)
		{
			if(dq.empty()) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else if(s.compare("back") == 0)
		{
			if(dq.empty()) cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
		else if(s.compare("size") == 0)
		{
			cout << dq.size() << '\n';
		}
		else
		{
			if(dq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
	
	return 0;
}