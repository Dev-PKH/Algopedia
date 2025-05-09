#include <bits/stdc++.h>
using namespace std;

int arr[22];
int n,s,cnt;

void tracking(int idx, int sum)
{
    if(idx == n) // 모든 원소를 다 탐지
	{
		if(sum == s) cnt++;
		return;
	}
	
	tracking(idx+1, sum + arr[idx]); // 현재 원소를 추가
	tracking(idx+1, sum); // 현재 원소를 추가하지 않음
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	for(int i=0; i<n; i++) cin >> arr[i];
	tracking(0,0);
	if(s == 0) cnt--;
	cout << cnt;
	
	return 0;
}