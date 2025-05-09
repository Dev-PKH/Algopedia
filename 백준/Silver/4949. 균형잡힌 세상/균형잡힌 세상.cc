#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s = "test";
	
	while(1)
	{
		stack<char> st;
		getline(cin, s);
		
		if(s.compare(".") == 0) break;
		
		bool check = true;
		
		for(auto i : s)
		{
			if(i == '(' || i == '[') st.push(i);
			else if(i == ')')
			{
				if(st.empty() || st.top() != '(') {
					check = false;
					break;
				}
				else st.pop();
			}
			else if(i == ']')
			{
				if(st.empty() || st.top() != '[') { 
					check = false;
					break;
				}
				else st.pop();
			}
		}
		
		if(!st.empty()) check = false;
		
		if(check) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	
	return 0;
}