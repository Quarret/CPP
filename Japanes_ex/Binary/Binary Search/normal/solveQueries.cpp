#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct node {
    int num;
    int index;
};

int check(vector<node> nodes, int k) {
    int l = 0, r = nodes.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nodes[mid].num < k) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}

vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size(), m = queries.size(), num1 = 0, num2 = 0;
    vector<node> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i].num = nums[i];
        nodes[i].index = i;
    }

    sort(nodes.begin(), nodes.end(), [&] (node x, node y) {
        if (x.num == y.num) return x.index < y.index;
        return x.num < y.num;
    });

    vector<int> ans(m, 0);
    for (int i = 0; i < m; i++) {
        num1 = check(nodes, nums[queries[i]]);
        num2 = check(nodes, nums[queries[i]] + 1) - 1;

        int minn = 1e9;
        for (int j = num1; j <= num2; j++) {
            if (nodes[j].index != queries[i]) {
                minn = min(minn, min((nodes[j].index - queries[i] + n) % n, (queries[i] - nodes[j].index + n) % n));
            }
        }

        ans[i] = (minn == 1e9 ? -1 : minn);
    }

    return ans;
}

/*
取模解决循环做法
TLE
*/
int check(vector<int> indexs, int k) {
    int l = 0, r = indexs.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (indexs[mid] < k) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size(), m = queries.size(), minn = 0;
    unordered_map<int, vector<int> > mp;
    vector<int> ans(m, 0);

    for (int i = 0; i < n; i++) {
        mp[nums[i]].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int num = nums[queries[i]], t = mp[num].size();
        minn = 1e9;
        
        if (t == 1) {
            ans[i] = -1;
            continue;
        }

        int pos = check(mp[num], queries[i]);
        int pos1 = mp[num][(pos - 1 + t) % t], pos2 = mp[num][(pos + 1 + t) % t];
        minn = min(minn, min((pos1 - queries[i] + n) % n, (queries[i] - pos1 +n) % n));
        minn = min(minn, min((pos2 - queries[i] + n) % n, (queries[i] - pos2 + n) % n));

        ans[i] = minn;
    }

    return ans;
}

/*
灵神 加2个烧饼做法
TLE
*/
vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size(), m = queries.size(), minn = 0;
    unordered_map<int, vector<int> > mp;
    vector<int> ans(m, 0);

    for (int i = 0; i < n; i++) {
        mp[nums[i]].push_back(i);
    }

    for (auto& it : mp) {
        auto& p = it.second;
        p.insert(p.begin(), p.back() - n);
        p.push_back(p[1] + n);

    }

    for (int i = 0; i < m; i++) {
        int num = nums[queries[i]];
        auto& p = mp[num];

        if (p.size() == 3) {
            ans[i] = -1;
        } else {
            int pos = check(p, queries[i]);
            ans[i] = min(queries[i] - p[pos - 1], p[pos + 1] - queries[i]);
        }
    }

    return ans;
}

/*
left[i] 表示在 i 左边的等于 nums[i] 的最近元素下标
从 -n 到 n - 1更新， 保证遍历一次原nums

right[i] ...右边...
从2 * n - 1 到 n更新, ...

pos[num][index] 实时跟新num元素的最新位置
123

*/

vector<int> solveQueries1(vector<int>& nums, vector<int>& queries) {
    int n = nums.size(), m = queries.size();
    vector<int> left(n, 0), right(n, 0), ans(m, 0);
    unordered_map<int, int> pos;
    
    for (int i = -n; i < n; i++) {
        if (i >= 0) {
            left[i] = pos[nums[i]];
        }
        pos[nums[(i + n) % n]] = i;
    }

    pos.clear();

    for (int i = 2 * n - 1; i >= 0; i--) {
        if (i < n) {
            right[i] = pos[nums[i]];
        }

        pos[nums[i % n]] = i;
    }

    for (int i = 0; i < m; i++) {
        int num = queries[i];
        int l = left[num], r = right[num];
        ans[i] = (num - l == n ? - 1 : min(num - l, r - num));
    }
    
    return ans;
}

/*
枚举右维护左做法
*/
vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
   int n = nums.size(), m = queries.size();
   unordered_map<int, int> mp;
   vector<int> cnt(n, 1e9);

   for (int i = 0; i < 2 * n; i++) {
        int num = nums[i % n];
        if (mp.find(num) != mp.end() && i - mp[num] < n) {
            cnt[mp[num] % n] = min(cnt[mp[num] % n], i - mp[num]);
            cnt[i % n] = min(cnt[i % n], i - mp[num]);
        }
        mp[num] = i;
   }

   vector<int> ans;
   for (int i = 0; i < m; i++) {
        int num = queries[i];
        if (cnt[num] != 1e9) ans.push_back(cnt[num]);
        else ans.push_back(-1);
   }

   return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
