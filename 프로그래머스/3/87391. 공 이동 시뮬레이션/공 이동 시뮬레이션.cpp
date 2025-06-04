#include <bits/stdc++.h>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long sx = x, sy = y, ex = x, ey = y; // s : 0에 가까운 좌표, e : n,m에 가까운 좌표
    
    // 역방향으로 추적
    for(int i=queries.size()-1; i>=0; i--)
    {
        long long dir = queries[i][0];
        long long dist = queries[i][1];
        
        if(dir == 0) // 왼쪽 방향이니 오른쪽에서 추적
        {
            if(sy != 0) // 왼쪽 벽에 붙은 상태(=ex만 이동)가 아니라면 이동
                sy += dist;
            
            ey += dist;
            if(ey >= m) ey = m-1;
        }
        else if(dir == 1) // 오른쪽 방향, 왼쪽에서 추격
        {
            if(ey != m-1) ey -= dist;   
            sy -= dist;
            if(sy < 0) sy = 0;
        }
        else if(dir == 2)
        {
            if(sx != 0) sx += dist;
            ex += dist;
            if(ex >= n) ex = n-1;
        }
        else
        {
            if(ex != n-1) ex -= dist;
            sx -= dist;
            if(sx < 0) sx = 0;
        }
        
        // 범위를 벗어나는 경우 예외처리 ex) n=1, m=5, x=0, y=2, queries = [[0,5],[1,5]]
        if(sx >= n || ex < 0 || sy >=m || ey <0) return 0;
    }
    
    return (ex-sx+1) * (ey-sy+1);
}