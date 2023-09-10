#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(int i=0;i<timePoints.size();i++){
            int h1=timePoints[i][0]-'0';
            int h2=timePoints[i][1]-'0';
            int hr=h1*10+h2;

            int m1=timePoints[i][3]-'0';
            int m2=timePoints[i][4]-'0';
            int min=m1*10+m2;

            int totalMinutes=hr*60+min;
            minutes.push_back(totalMinutes);
        }
        
        int mini=INT_MAX;
        sort(minutes.begin(),minutes.end());

        for(int i=0;i<minutes.size()-1;i++){
            mini=min(mini,abs(minutes[i]-minutes[i+1]));
        }

        //The GAME DECIDER
        mini=min(mini,abs(minutes[0]+1440-minutes[minutes.size()-1]));
        return mini;
    }
};