#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

long long countMajoritySubarrays(vector<int>& nums, int target) {
    // 插入时自增, 保证 st 中元素互不相同
    int idx = 0;
    ordered_set* st = new ordered_set();
    st->insert({0, ++idx});

    long long ans = 0;
    int s = 0;
    for (int x : nums) {
        s += x == target ? 1 : -1;
        // order_of_key(key) 严格小于 key 的元素个数
        ans += st->order_of_key({s, 0});
        st->insert({s, ++idx});
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
