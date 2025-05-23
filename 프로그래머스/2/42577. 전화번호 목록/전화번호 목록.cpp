#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> pb) {
    bool answer = true;
    unordered_map<string, int> m;
    
    for(int i=0; i<pb.size(); i++)
        m[pb[i]] = 1;
    
    for(int i=0; i<pb.size(); i++)
    {
        string str = "";
        for(int j=0; j<pb[i].length(); j++)
        {
            str += pb[i][j];
            if(m[str] && str != pb[i]) return false;
        }
    }
    
    return answer;
}