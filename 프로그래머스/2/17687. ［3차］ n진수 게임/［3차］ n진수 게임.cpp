#include <bits/stdc++.h>

using namespace std;

string base = "0123456789ABCDEF";

string haxa(int i, int& n)
{
    if(i<n) return string(1,base[i]);
    else return haxa(i/n,n) + base[i%n];
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int cnt = 0;
    int cur = 0;
    for(int i=0; i<t*m; i++)
    {
        string s = haxa(i,n);
        for(auto c : s)
        {
            cur++;
            if(cur == p) {answer += c; cnt++; if(cnt == t) break;}
            if(cur == m) {cur = 0;}
        }
        if(cnt == t) break;
    }
    
    return answer;
}