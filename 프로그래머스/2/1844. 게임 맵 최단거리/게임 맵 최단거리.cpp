#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

bool vis[102][102];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int> > maps)
{
    int X = maps.size();
    int Y = maps[0].size();
    
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
                
            if(nx < 0 || ny < 0 || nx >= X || ny >= Y) continue;
            if(vis[nx][ny] || maps[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
            maps[nx][ny] = maps[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    
    /*for(int x=0; x<X; x++)
    {
        for(int y=0; y<Y; y++){
            cout << maps[x][y] << ' ';
        }
        cout << '\n';
    }*/
    
    if(maps[X-1][Y-1] == 1) return -1;
    else return maps[X-1][Y-1];
}