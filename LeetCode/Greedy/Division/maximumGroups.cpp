#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximumGroups(vector<int>& grades) {
    int ans = 0;
    ranges::sort(grades);
    
    int pre = 0, precnt = 0;
    int sum = 0, cnt = 0;
    for (int x : grades) {
        sum += x;
        cnt++;
        if (sum > pre && cnt > precnt) {
            ans++;
            pre = sum;
            precnt = cnt;
            sum = 0;
            cnt = 0;
        }
    }

    return ans;
}

int maximumGroups(vector<int>& grades) {
    int n = grades.size(), x = sqrt(2 * n);
    return x * (x + 1) > 2 * n ? x - 1 : x; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
