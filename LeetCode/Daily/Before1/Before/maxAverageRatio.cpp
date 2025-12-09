#include <bits/stdc++.h>
using ll = long long;
using namespace std;

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    using DII = tuple<double, int, int>;
    // get<N> get the N th of pair or tuple
    auto cmp = [](const DII& a, const DII& b) {
        return get<0>(a) > get<0>(b);
    };
    priority_queue<DII, vector<DII>, decltype(cmp)> pq;
    
    for (auto &c : classes) {
        int a = c[0], b = c[1];
        pq.emplace(1.0 * (a - b) / (1LL * b * (b + 1)), a, b);
    }

    while (extraStudents--) {
        auto [_, a, b] = pq.top();
        pq.pop();

        a++;
        b++;
        pq.emplace(1.0 * (a - b) / (1LL * b * (b + 1)), a, b);
    }

    double sum = 0;
    int n = pq.size();
    while (!pq.empty()) {
        auto [_, a, b] = pq.top();
        pq.pop();

        sum += 1.0 * a / b;
    }

    return sum / n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
