#include <bits/stdc++.h>
using namespace std;

char s[20];
char vow[5] = {'a','e','i','o','u'};
int l, c;

bool check(string s)
{
	int x=0, y=0; // 자음, 모음
	for(auto k : s)
	{
		bool isVow = false;
		
		for(int i=0; i<5; i++)
		{
			if(k == vow[i])
			{
				isVow = true;
				y++;
				break;
			}
		}
		if(!isVow) x++;
	}

	return (x >=2 && y>=1);
}

void tracking(string pass, int len, int index)
{
	if(len == l)
	{
		if(check(pass)) cout << pass << '\n';
		return;	
	}
	
	if(index >= c) return;
	
	tracking(pass + s[index], len +1,  index +1);
	tracking(pass, len, index+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> c;
	for(int i=0; i<c; i++)
		cin >> s[i];
	
	sort(s, s+c);
	
	tracking("", 0, 0);
	

	return 0;
}