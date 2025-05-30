#include <bits/stdc++.h>

using namespace std;

bool check(int i, vector<int>& v)
{
    for(auto c : v)
        if((c & i) == c) return false;
    return true;
}

int solution(vector<vector<string>> r) {
    int row = r.size();
    int col = r[0].size();
    int cnt = 1 << col;
    vector<int> v;
    
    for(int a=1; a<cnt; a++)
    {
        set<string> str;
        for(int i=0; i<row; i++)
        {  
            string temp = "";
            for(int j=0; j<col; j++)
                if((1<<j) & a) temp += r[i][j];
            if(temp != "") str.insert(temp);
        }
        if(str.size() == row && check(a,v)) {v.push_back(a);} 
    }

    return v.size();
}