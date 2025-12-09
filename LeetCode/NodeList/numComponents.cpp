#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

int numComponents(ListNode* head, vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int x : nums) {
        mp[x] = 1;
    }

    int ans = 0, pre = -1;
    for (auto cur = head; cur; cur = cur -> next) {
        int val = cur -> val;
        ans += mp[val] && (mp[pre] == 0);
        pre = val;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
