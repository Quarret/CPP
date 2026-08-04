#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int n = landStartTime.size(), m = waterDuration.size();
    
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int land_end = landStartTime[i] + landDuration[i];
        
        for (int j = 0; j < m; j++) {
            int water_end = waterStartTime[j] + waterDuration[j];
            ans = min(ans, max(land_end, waterStartTime[j]) + waterDuration[j]);
            ans = min(ans, max(water_end, landStartTime[i]) + landDuration[i]);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}