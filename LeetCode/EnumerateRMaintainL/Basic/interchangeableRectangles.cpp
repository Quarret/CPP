#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    int n = rectangles.size();
    unordered_map<double, int> mp;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        double num = (double)rectangles[i][0] / (double) rectangles[i][1];
        ans += mp[num];
        mp[num]++; 
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
