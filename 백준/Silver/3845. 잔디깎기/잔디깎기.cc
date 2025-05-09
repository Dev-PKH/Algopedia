#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(1)
	{
		int x,y;
		float w;
		bool check = true;
		float lx = -1, ly =-1, rx =0, ry=0;
		
		cin >> x >> y >> w;
		if(x==y && w == 0.0f) break;
		
		vector<float> vx;
		vector<float> vy;
		float num;
		
		for(int i =0; i<x; i++)
		{
			cin >> num;
			vx.push_back(num);
		}
		
		sort(vx.begin(), vx.end());
		lx = vx[0]-w/2;
		rx = vx[0]+w/2;
		
		for(int i=0; i<y; i++)
		{
			cin >> num;
			vy.push_back(num);
		}
		
		sort(vy.begin(),vy.end());
		ly = vy[0]-w/2;
		ry = vy[0]+w/2;
		
		for(int i=0; i<vx.size(); i++)
		{
			if(lx > 0) break;
			
			if(vx[i]- w/2 <= rx)
			{
				rx = vx[i] + w/2;
			}
		}
		
		if(rx < 75) check = false;
		if(check)
		{
			for(int i=0; i<vy.size(); i++)
			{
				if(ly > 0) break;
				
				if(vy[i] - w/2 <= ry)
				{
					ry = vy[i] + w/2;
				}
			}
			
			if(ry < 100) check = false;
		}
		
		
		if(check) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	
	return 0;
}