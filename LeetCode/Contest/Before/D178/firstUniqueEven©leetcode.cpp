#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int firstUniqueEven(vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (int x : nums) {
        cnt[x]++;
    }
    
    for (int x : nums) {
        if (x % 2 == 0 && cnt[x] == 1) {
            return x;
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}