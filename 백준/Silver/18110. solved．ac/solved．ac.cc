#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n, cnt;
	float sum = 0, check;
	vector<int> v;
	//int value[300009];
	
	cin >> n;
	
	if(n != 0){
	
	for(int i=1; i<=n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	check = floor(n * 0.15 + 0.5f);
	
	for(int i=check ; i< n-check; i++)
	sum += v[i];
	
	cout << floor((sum/(n- check*2)) + 0.5f) << '\n';
	}
	else cout << 0 << '\n';
	
	return 0;
}