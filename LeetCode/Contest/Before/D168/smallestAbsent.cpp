#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int smallestAbsent(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int sum = 0;
    for (int x : nums) {
        mp[x]++;
        sum += x;
    }
    
    int avg = sum % n ? (sum + n - 1) / n : sum / n + 1;
    avg = max(avg, 1);
    while (mp[avg]) {
        avg++;    
    }

    return avg;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
