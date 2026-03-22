#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	
	stack<char> st;
	int cnt = 0;
	
	bool isLeft = false;
	
	for(auto i:s)
	{
		if(i == '(') 
		{
			st.push(i);
			isLeft = true;
		}
		else
		{
			st.pop();
			if(isLeft)
			{
				cnt += st.size();
				isLeft = false;
			}
			else cnt++; // 끝 점 마무리
		}
	}
	
	cout << cnt;
	
	return 0;
}