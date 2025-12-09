#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
    ranges::sort(processorTime);        
    ranges::sort(tasks, greater());
    
    int ans = 0, n = processorTime.size();
    for (int i = 0; i < n; i++) {
        ans = max(ans, processorTime[i] + tasks[4 * i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
