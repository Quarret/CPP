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
        ranges::iota(fa, 0); // iota(fa.begin(), fa.end(), 0);
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


class Solution {
public:
    // 从满的水域, 反向添加边来检查连通块, 并查集适合合并, 不适合删除. 
    // 从地 -> 水的角度看, 就是删除地与地之间的边, 从水 -> 地的角度看就是添加地与地之间的边
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        UnionFind dsu(row * col);
        int nxt[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

        // 只要第一行和最后一行有一个联通就行
        for (int i = 0; i < col - 1; i++) {
            dsu.merge(i, i + 1);
            dsu.merge((row - 1) * col + i, (row - 1) * col + i + 1);
        }

        vector ground(row, vector<int>(col, 0));
        for (int i = cells.size() - 1; i >= 0; i--) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;

            ground[x][y] = 1;
            for (auto &[dx, dy] : nxt) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || nx >= row || ny < 0 || ny >= col || !ground[nx][ny]) continue;
                dsu.merge(x * col + y, nx * col + ny);
            }

            if (dsu.is_same(0, (row - 1) * col + (col - 1))) {
                return i;
            }
        }

        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
