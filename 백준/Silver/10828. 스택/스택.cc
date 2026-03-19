#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int n;

int main() {
	ios::sync_with_stdio(0);
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
			st.push(num);
		}
		else if(s == "pop")
		{
			if(st.empty()) cout << -1 << '\n';
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if(s == "top")
		{
			if(st.empty()) cout << -1 << '\n';
			else cout << st.top() << '\n';
		}
		else if(s == "size")
		{
			cout << st.size() << '\n';
		}
		else
		{
			if(st.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
	
	
	return 0;
}