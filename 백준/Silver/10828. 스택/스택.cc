#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> st;
	int num;
	string s;
	int value;
	cin >> num;
	
	while(num--)
	{
		cin >> s;
		
		if(s.compare("push") == 0)
		{
			cin >> value;
			st.push(value);
		}
		else if(s.compare("pop") == 0)
		{
			if(st.empty()) cout << -1 << '\n';
			else{
				cout << st.top() << '\n';
			st.pop();
			}
		}
		else if(s.compare("size") ==0)
		{
			cout << st.size() << '\n';
		}
		else if(s.compare("empty") == 0)
		{
			if(st.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else
		{
			if(st.empty()) cout << -1 <<'\n';
			else cout << st.top() << '\n';
		}
	}
	
	return 0;
}