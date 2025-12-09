#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maxWeight(vector<int>& pizzas) {
    int n = pizzas.size();
    int m2 = n / 4 / 2, m1 = n / 4 - m2;
    sort(pizzas.begin(), pizzas.end(), greater());

    long long ans = 0;
    for (int i = 0; i < m1 + 2 * m2; i++) {
        if (i < m1) {
            ans += 1LL * pizzas[i];
        } else {
            if ((i - m1) % 2 == 1) {
                ans += 1LL * pizzas[i];
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
