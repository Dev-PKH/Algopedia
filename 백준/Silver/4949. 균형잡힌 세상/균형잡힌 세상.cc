#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(1)
	{
		string s;
		stack<char> st;
		
		getline(cin, s);
		
		if(s[0] == '.') break;
		
		for(auto i:s)
		{
			if(i=='(' || i=='[') st.push(i);
			else if(i == ')')
			{
				if(st.empty() || st.top() != '(') 
				{
					st.push(1);
					break;	
				}
				else st.pop();
			}
			else if(i == ']')
			{
				if(st.empty() || st.top() != '[') 
				{
					st.push(1);
					break;	
				}
				else st.pop();
			}
		}
		
		if(st.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';
 	}
	
	return 0;
}