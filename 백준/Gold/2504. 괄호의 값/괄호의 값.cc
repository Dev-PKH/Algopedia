#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	stack<char> st;
	
	cin >> s;
	
	int result = 0, tmp = 1;
	
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] == '(') 
		{
			st.push(s[i]);
			tmp *= 2;
		}
		else if(s[i] == '[')
		{
			st.push(s[i]);
			tmp *= 3;
		}
		else if(s[i] == ')')
		{
			if(st.empty() || st.top() != '(')
			{
				result = 0;
				break;
			}
			else
			{
				st.pop();
				if(s[i-1] == '(') result += tmp;
				tmp /= 2;
			}
		}
		else
		{
			if(st.empty() || st.top() != '[')
			{
				result = 0;
				break;
			}
			else
			{
				st.pop();
				if(s[i-1] == '[') result += tmp;
				tmp /= 3;
			}
		}
	}
	
	if(!st.empty()) cout << 0;
	else cout << result;
	
	return 0;
}