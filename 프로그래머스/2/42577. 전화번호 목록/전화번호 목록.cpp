#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> pb) {
    bool answer = true;
    
    sort(pb.begin(), pb.end());
    
    for(int i=0; i<pb.size()-1; i++)
        if(pb[i].compare(pb[i+1].substr(0, pb[i].length())) == 0)
            return false;

    
    return answer;
}