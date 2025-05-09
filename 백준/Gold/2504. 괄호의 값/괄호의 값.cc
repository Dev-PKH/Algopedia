#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> st;
	string s;
	int sum = 0; // 더해질 값
	int mul = 1; // 곱해질 값
	
	cin >> s;
	
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] == '(')
		{
			st.push(s[i]);
			mul *= 2;
		}
		else if(s[i] == '[')
		{
			st.push(s[i]);
			mul *= 3;
		}
		else if(s[i] == ')')
		{
			if(st.empty() || st.top() != '(')
			{
				cout << 0;
				return 0;
			}
			if(s[i-1] == '(') sum+=mul;
			st.pop();
			mul /= 2;
		}
		else
		{
			if(st.empty() || st.top() != '[')
			{
				cout << 0;
				return 0;
			}
			if(s[i-1] == '[') sum+=mul;
			st.pop();
			mul /= 3;
		}
	}
	
	if(st.empty()) cout << sum;
	else cout << 0;
}