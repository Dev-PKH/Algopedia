#include <bits/stdc++.h>
using namespace std;

bool isused[10];
int arr[10];
int n,m;

void tracking(int cnt)
{
	if(m == cnt)
	{
		for(int i=0; i<m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	for(int i=1; i<=n; i++)
	{
		if(!isused[i])
		{
			isused[i] = true;
			arr[cnt] = i;
			tracking(cnt+1);
			isused[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	tracking(0);
	
	return 0;
}