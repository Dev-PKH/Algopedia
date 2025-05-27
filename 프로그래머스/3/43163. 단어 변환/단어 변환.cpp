#include <bits/stdc++.h>

using namespace std;


bool vis[52];
int result = 0x7fffffff;
int row = 0; // word 단어 개수
int col = 0; // word의 길이

void DFS(const vector<string>& s, string b, string& t, int idx, int cnt)
{
    if(t == b) 
    {
        result = min(result, cnt);
        return;
    }
    
    for(int i=0; i<row; i++)
    {
        if(vis[i]) continue;
        
        int temp = 0;
        for(int j=0; j<col; j++)
            if(b[j] != s[i][j]) temp++;
        
        if(temp == 1)
        {
            vis[i] = 1;
            DFS(s, s[i],t,idx+1, cnt+1);
            vis[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    row = words.size();
    col = words[0].length();

    DFS(words, begin, target, 0, 0);
    
    if(result == 0x7fffffff) result = 0;
    return result;
}