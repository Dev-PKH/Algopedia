#include <iostream>
#include <queue>

using namespace std;

bool visit[100009] = {false,};

void bfs(int n, int k)
{
	queue<pair<int, int>> q;
	q.push(make_pair(n,0));
	
	while(!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		
		q.pop();
		if(x == k)
		{
			cout << cnt << '\n';
			break;
		}
		
		if(x+1 >=0 && x+1 <=100000)
		{
			if(!visit[x+1])
			{
				q.push(make_pair(x+1, cnt +1));
				visit[x+1] = true;
			}
		}
		
		if(x-1 >=0 && x-1 <=100000)
		{
			if(!visit[x-1])
			{
				q.push(make_pair(x-1, cnt +1));
				visit[x-1] = true;
			}
		}
		
		if(x*2 >=0 && x*2 <=100000)
		{
			if(!visit[x*2])
			{
				q.push(make_pair(x*2, cnt +1));
				visit[x*2] = true;
			}
		}
		
		if(x+1 >=0 && x+1 <=100000)
		{
			if(!visit[x+1])
			{
				q.push(make_pair(x+1, cnt +1));
				visit[x+1] = true;
			}
		}
	}
}

using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	visit[n] = true;
	bfs(n, k);
	
	return 0;
}