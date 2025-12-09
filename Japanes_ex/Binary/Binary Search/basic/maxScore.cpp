#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long maxScore(vector<int>& points, int m) {
    int n = points.size();
    long long l = 0, r = *max_element(points.begin(), points.end()) * m + 1, mid = 0;

    auto check = [&](long long k) -> bool {
        long long cnt = 0, num = 0;
        vector<int> score(n, 0); 
        for (int i = 0; i < n - 1; i++) {
            if (score[i] < k) {
                num = (k - score[i] + points[i] - 1) / points[i];
                score[i] += points[i] * num;
                score[i + 1] += points[i + 1] * num;
                cnt += 2 * num - 1;
            }

            if (cnt > m) return 0;
        }

        if (score.back() < k) cnt += 2 * ((k - score.back() + points.back() - 1) / points.back()) - 1;

        if (cnt > m) return 0;

        return 1;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
