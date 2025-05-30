#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> pb) {
    bool answer = true;
    unordered_map<string, int> s;
    
    for(auto c : pb)
        s[c] = 1;
    
    for(int i=0; i<pb.size();i++)
    {
        string str = "";
        for(int j=0; j<pb[i].length()-1; j++)
        {
            str += pb[i][j];
            if(s[str])
            {
                return false;
            }
        }
    }
    
    return answer;
}