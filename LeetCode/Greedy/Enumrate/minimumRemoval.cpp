#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long minimumRemoval(vector<int>& beans) {
    long long takeout = INT64_MAX, n = beans.size(), sum = 0;
    ranges::sort(beans);
    
    for (int i = 0; i < n; i++) {
        sum += beans[i];
    }

    int r = *ranges::max_element(beans);
    for (int i = 0; i <= r; i++) {
        int pos = ranges::lower_bound(beans, i) - beans.begin();
        long long res = sum - (n - pos) * i;
        takeout = min(takeout, res);
    }

    return takeout;
}


long long minimumRemoval(vector<int>& beans) {
    long long sum = 0, max_save = 0, n = beans.size();
    ranges::sort(beans);

    for (int i = 0; i < n; i++) {
        sum += beans[i];
        max_save = max(max_save, (n - i) * beans[i]);
    }

    return sum - max_save;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
