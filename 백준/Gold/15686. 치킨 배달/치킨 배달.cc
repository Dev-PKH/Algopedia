#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int town[52][52];
vector<pair<int,int>> home;
vector<pair<int,int>> shop;
vector<int> si;

int n,m;
int cost = 0x7f7f7f7f;

void simulate()
{
	int value = 0;
	for(auto h : home)
	{
		int temp = 0x7f7f7f7f;
		for(auto s : si)
		{
			temp = min(temp, abs(shop[s].X-h.X)+abs(shop[s].Y-h.Y));
		}
		value += temp;
	}
	cost = min(value, cost);
}

void choose(int num, int cnt)
{
	if(num == m)
	{
		simulate();
		return;
	}
	
	for(int i=cnt; i<shop.size(); i++)
	{
		si.push_back(i);
		choose(num+1, i+1);
		si.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{	
		for(int j=1; j<=n; j++)
		{
			cin >> town[i][j];
			if(town[i][j] == 1) home.push_back({i,j});
			if(town[i][j] == 2) shop.push_back({i,j});
		}
	}
	
	choose(0, 0);
	
	cout << cost;
	
	return 0;
}