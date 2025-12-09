#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> cnt;
    unordered_set<int> st;

    auto cmp = [&](int x, int y) -> bool {
        if (cnt[x] > cnt[y]) return true;
        else if (cnt[x] == cnt[y]) {
            return x > y;
        }
        return false;
    };

    for (int r = 0, l = 0; r < n; r++) {
        if (cnt[nums[r]] == 0) st.insert(nums[r]);
        cnt[nums[r]]++;

        if (r < k - 1) continue;
        vector<int> res(st.begin(), st.end());
        sort(res.begin(), res.end(), cmp);

        int tot = 0;
        for (int i = 0; i < min(x, (int)res.size()); i++) {
            tot += res[i] * cnt[res[i]];
        }

        ans.push_back(tot);
        if (cnt[nums[l]] == 1) {
            st.erase(nums[l]);
        }
        cnt[nums[l]]--;
        l++;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
