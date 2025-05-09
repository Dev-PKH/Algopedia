#include <bits/stdc++.h>
using namespace std;

bool isused1[32]; // 열
bool isused2[32]; // 양의 대각
bool isused3[32]; // 음의 대각

int n, cnt;

void Queen(int cur) // 퀸의 개수이자 행을 의미
{
	if(cur == n)
	{
		cnt++;
		return;
	}
	for(int i=0; i<n; i++)
	{
		if(isused1[i] || isused2[i+cur] || isused3[i-cur+n-1]) continue;
		isused1[i] = true;
		isused2[i+cur] = true;
		isused3[i-cur+n-1] = true;
		Queen(cur +1);
		isused1[i] = false;
		isused2[i+cur] = false;
		isused3[i-cur+n-1] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	Queen(0);
	cout << cnt;
	
	return 0;
}