#include <iostream>
using namespace std;

int cnt=0;

void dfs(int m, int x, int y){
	if(m > 1){
		int x_area = (x < m/2 ? 0 : 1);
		int y_area = (y < m/2 ? 0 : 1);
		cnt = cnt + (m * m)/4 * (y_area * 2 + x_area);
		
		dfs(m/2, x-m/2 * x_area, y- m/2 * y_area);
	}
}

int main() {
	
	int n, x, y;
	int max=1;
	
	cin >> n >> y >> x;
	
	for(int i=0; i<n; i++)
		max *= 2;
	
	dfs(max, x, y);
	
	cout << cnt;
	
	return 0;
}