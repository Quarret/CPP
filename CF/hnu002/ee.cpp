#include <bits/stdc++.h>
using namespace std;
 
using i64 = int64_t;
using u64 = uint64_t;
 
struct IO;
 
struct ContainerIO {
    const IO &io;
    int n;
    ContainerIO(int n, const IO &io) : n(n), io(io) {}
    template <typename T> operator std::vector<T>() const {
        std::vector<T> t(n);
        for (auto &ti : t) {
            ti = io;
        }
        return t;
    }
};
 
struct IO {
    IO() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    template <typename T> operator T() const {
        T t;
        std::cin >> t;
        return t;
    }
    template <typename T> const IO &operator<<(const T &t) const {
        std::cout << t;
        return *this;
    }
    template <typename T> bool operator==(const T &t) const {
        return T(*this) == t;
    }
    ContainerIO operator()(int n) const { return ContainerIO(n, *this); }
};
 
void repeat(int n, std::function<void()> &&f) {
    for (int i = 0; i < n; i += 1) {
        f();
    }
}
 
void repeat(int n, std::function<void(int)> &&f) {
    for (int i = 0; i < n; i += 1) {
        f(i);
    }
}
 
void repeat(int l, int r, std::function<void(int)> &&f) {
    for (int i = l; i < r; i += 1) {
        f(i);
    }
}
 
void choose(int n, std::vector<std::function<void()>> &&vf) { vf[n](); }
 
int main() {
    IO io;
    repeat(io, [&]() {
        int n = io, m = io;
        vector<vector<int>> a(n);
        for (auto &ai : a) {
            ai = io(m);
        }
        int ans = 0;
        vector<int> di = {-1, 1, 0, 0};
        vector<int> dj = {0, 0, -1, 1};
        auto rec = [&](auto &rec, int i, int j) -> int {
            if (a[i][j] == 0) {
                return 0;
            }
            int res = a[i][j];
            a[i][j] = 0;
            for (int k = 0; k < 4; k += 1) {
                int x = i + di[k], y = j + dj[k];
                if (x >= 0 and x < n and y >= 0 and y < m) {
                    res += rec(rec, x, y);
                }
            }
            return res;
        };
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                ans = max(ans, rec(rec, i, j));
            }
        }
        io << ans << "\n";
    });
}