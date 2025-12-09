#include <bits/stdc++.h>
using ll = long long;
using namespace std;
long long total(vector<int>& time, int t) {
    long long num = 0, n = time.size();
    for (int i = 0; i < n; i++) {
        num += t / time[i];
    }

    return num;
}
long long check(vector<int>& time, int l, int r, int totalTrips) {
    long long mid = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (total(time, mid) < totalTrips) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
// total + check 合体版
long long check(vector<int>& time, int l, int r, int totalTrips) {
    long long mid = 0;

    auto total = [&](long long t) -> long long {
        long long num = 0, n = time.size();
        for (int i = 0; i < n; i++) {
            num += t / time[i];
        }
    
        return num;
    };
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (total(mid) < totalTrips) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}

long long minimumTime(vector<int>& time, int totalTrips) {
    long long minn = 1, maxx = 1e9, ans = 0, n = time.size();

    for (int i = 0; i < n; i++) {
        maxx = min(maxx, (long long)time[i]);
    }
    maxx *= totalTrips;

    ans = check(time, minn, maxx, totalTrips);

    return (ans == maxx + 1 ? maxx : ans);
}

// 3合1版本
// 相对于三个分离函数，运行时间快一点，空间大一点
long long minimumTime(vector<int>& time, int totalTrips) {
    long long minn = 1, maxx = 1e9, n = time.size(), mid = 0;

    for (int i = 0; i < n; i++) {
        maxx = min(maxx, (long long)time[i]);
    }
    maxx *= totalTrips;

    auto check = [&](long long t) -> long long {    
        long long num = 0, n = time.size();
        for (int i = 0; i < n; i++) {
            num += t / time[i];
        }
    
        return num;
    };

    long long l = minn, r = maxx;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid) < totalTrips) l = mid + 1;
        else r = mid - 1;
    }

    return (l == maxx + 1 ? maxx : l);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
