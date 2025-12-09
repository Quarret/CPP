#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();

    // 计算空格长度
    auto get = [&](int i) -> int {
        if (i == 0) {
            return startTime[0];
        } else if (i == n) {
            return eventTime - endTime[n - 1];
        }

        return startTime[i] - endTime[i - 1];
    };

    // n + 1 个空位, 计算前 3 个
    int a = 0, b = -1, c = -1;
    for (int i = 1; i <= n; i++) {
        int sz = get(i);
        if (sz > get(a)) {
            c = b;
            b = a;
            a = i;
        } else if (b < 0 || sz > get(b)) {
            c = b;
            b = i;
        } else if (c < 0 || sz > get(c)) {
            c = i;
        }
    }

    // 枚举桌子
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sz = endTime[i] - startTime[i];
        if (i != a && i + 1 != a && get(a) >= sz ||
            i != b && i + 1 != b && get(b) >= sz ||
            sz <= get(c)) { // 可以移出去
            ans = max(ans, get(i) + sz + get(i + 1));
        } else {
            ans = max(ans, get(i) + get(i + 1));
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
