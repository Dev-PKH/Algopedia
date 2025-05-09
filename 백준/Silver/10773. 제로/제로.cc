#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> st;
	int num, sum =0,value;
	
	cin >> num;
	
	while(num--)
	{
		cin >> value;
		
		if(value != 0){
			st.push(value);
		}
		else
		{
			if(!st.empty()) st.pop();
		}
	}
	
	while(!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	
	cout << sum;
	
	return 0;
}