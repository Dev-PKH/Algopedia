#include <bits/stdc++.h>
using namespace std;

string pal(string s)
{
	string p = s;
	int len = p.length();
	
	// 팰린드롭 생성
	for(int i=0; i<len/2; i++)
		p[len-1-i] = p[i];
	
	// 생성된 팰린드롬 수가 원본보다 같거나 작을 경우
	if(p <= s)
	{
		int mid = (len-1)/2;
		
		while(mid >= 0)
		{
			if(p[mid] != '9')
			{
				p[mid]++;
				break;
			}
			else
			{
				p[mid] = '0';
				mid--;
			}
		}
		
		// 변경된 팰린드롬 적용
		for(int i=0; i<len/2; i++)
			p[len-1-i] = p[i];
		
		// 증가한 팰린드롭이 0일 경우 ex)999
		if(p[0] == '0')
		{
			p = "1"+ p;
			p[p.length() -1] = '1';
		}
	}
	
	return p;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	cout << pal(s);
	
	return 0;
}