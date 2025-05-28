#include <bits/stdc++.h>

using namespace std;

int solution(int b, int w, vector<int> t) {
    int cur = 0; // 현재 다리 위 무게
    int sec = 0; // 현재 초
    int idx = 0; // 현재 트럭 인덱스
    queue<int> q; // weight

    while(1)
    {
        if(t.size() == idx)
        {
            sec += b;
            break;
        }
        
        if(b <= q.size())
        {
            cur -= q.front(); q.pop();
        }
        
        if(cur + t[idx] <= w)
        {
            q.push(t[idx]);
            cur+= t[idx++];
        }
        else q.push(0);
        sec++;
    }
    
    
    return sec;
}