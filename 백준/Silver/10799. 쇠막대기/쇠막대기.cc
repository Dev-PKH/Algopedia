#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	stack<char> st;
	
	bool left = false; // left '('
	int result = 0;
	
	getline(cin, s);
	
	for(auto i : s)
	{
		if(i == '(') 
		{
			st.push(i);
			left = true;
		}
		else
		{
			if(left) // laser
			{
				left = false;
				st.pop();
				result += st.size();
			}
			else // barMax
			{
				result++;
				st.pop();
			}
		}
	}
	
	cout << result;
	
	return 0;
}