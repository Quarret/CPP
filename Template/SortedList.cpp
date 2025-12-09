#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    // 插入时自增, 保证 st 中元素互不相同
    int idx = 0;
    ordered_set* st = new ordered_set();
    st->insert({0, ++idx});

    int num = 0;
    // order_of_key(key) 严格小于 key 的元素个数
    int ans = st->order_of_key({num, 0});

    return 0;
}