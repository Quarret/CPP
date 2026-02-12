#include <bits/stdc++.h>
using ll = long long;
using namespace std;


// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
class UnionFind
{
    vector<int> fa; // 代表元
    vector<int> sz; // 集合大小

public:
    int cc; // 连通块个数

    UnionFind(int n) : fa(n), sz(n, 1), cc(n)
    {
        // 一开始有 n 个集合 {0}, {1}, ..., {n-1}
        // 集合 i 的代表元是自己，大小为 1
        iota(fa.begin(), fa.end(), 0);
    }

    // 返回 x 所在集合的代表元
    // 同时做路径压缩，也就是把 x 所在集合中的所有元素的 fa 都改成代表元
    int find(int x)
    {
        // 如果 fa[x] == x，则表示 x 是代表元
        if (fa[x] != x)
        {
            fa[x] = find(fa[x]); // fa 改成代表元
        }
        return fa[x];
    }

    // 判断 x 和 y 是否在同一个集合
    bool is_same(int x, int y)
    {
        // 如果 x 的代表元和 y 的代表元相同，那么 x 和 y 就在同一个集合
        // 这就是代表元的作用：用来快速判断两个元素是否在同一个集合
        return find(x) == find(y);
    }

    // 把 from 所在集合合并到 to 所在集合中
    // 返回是否合并成功
    bool merge(int from, int to)
    {
        int x = find(from), y = find(to);
        if (x == y)
        { // from 和 to 在同一个集合，不做合并
            return false;
        }
        fa[x] = y;      // 合并集合。修改后就可以认为 from 和 to 在同一个集合了
        sz[y] += sz[x]; // 更新集合大小（注意集合大小保存在代表元上）
        // 无需更新 sz[x]，因为我们不用 sz[x] 而是用 sz[find(x)] 获取集合大小，但 find(x) == y，我们不会再访问 sz[x]
        cc--; // 成功合并，连通块个数减一
        return true;
    }

    // 返回 x 所在集合的大小
    int get_size(int x)
    {
        return sz[find(x)]; // 集合大小保存在代表元上
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    UnionFind dsu(n);
    unordered_map<int, int> cnt;
    vector<int> color(n);
    unordered_map<int, int> left, right;
    for (int i = 0; i < n; i++) {
        cnt[i]++;
        color[i] = i;
        left[i] = i;
        right[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int op = 0, x = 0, c = 0;
        cin >> op;

        if (op == 1) {
            cin >> x >> c;
            x--;
            c--;

            int fa = dsu.find(x);
            int sz = dsu.get_size(fa);
            cnt[color[fa]] -= sz;

            cnt[c] += sz;
            
            int l = left[fa], r = right[fa];
            if (l != 0) {
                int fa1 = dsu.find(l - 1);
                if (color[fa1] == c) {
                    l = left[fa1];
                }
                dsu.merge(x, l);
            }

            if (r != n - 1) {
                int fa2 = dsu.find(r + 1);
                if (color[fa2] == c) {
                    r = right[fa2];
                }
                dsu.merge(x, r);
            }

            fa = dsu.find(x);
            color[fa] = c;
            left[fa] = l;
            right[fa] = r;
        } else {
            cin >> c;
            c--;

            cout << cnt[c] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}



/*
这道题卡住了? 没事! 冷静下慢慢想, 想了还做不出来就是收获
1. 这道题与位置无关吗? 可以先排序吗?
2. 从特殊到一般, 试试控制一些题目变量来找一些性质
3. 看到一些熟悉的性质? 试试从性质中的变量出发
4. 试着从循环不变量着手思考
5. 正面难做难想吗? 要不试试反面? 正逆序都试试
6. 此题有单调性吗? 可以二分答案吗?
7. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
8. 贡献法可以做吗?
9. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化 
*/