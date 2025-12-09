#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximumScore(vector<int>& cards, int cnt) {
    int n = cards.size(), num1 = INT_MAX / 2, num2 = INT_MAX / 2;
    sort(cards.begin(), cards.end(), greater());

    if (n < cnt) return 0;
    long long ans = 0;

    for (int i = 0; i < cnt; i++) {
        ans += cards[i];
        if (cards[i] % 2) {
            num1 = min(num1, cards[i]);
        } else {
            num2 = min(num2, cards[i]);
        }
    }
    if (ans % 2 == 0) return ans;

    int x = INT_MIN / 2, y = INT_MIN / 2;
    for (int i = cnt; i < n; i++) {
        if (cards[i] % 2) {
            x = max(x, cards[i]);
        } else {
            y = max(y, cards[i]);
        }
    }

    ans += max(x - num2, y - num1);
    return ans <= 0 ? 0 : ans;
}

int maximumScore(vector<int>& cards, int cnt) {
    int n = cards.size();
    sort(cards.begin(), cards.end(), greater());
    int s = reduce(cards.begin(), cards.begin() + cnt);
    if (s % 2 == 0) {
        return s;
    }

    auto replaced_sum = [&](int x) -> int {
        for (int i = cnt; i < n; i++) {
            if (x % 2 != cards[i] % 2) {
                return s - x + cards[i];
            }
        }

        return 0;
    };

    int x = cards[cnt - 1];
    int ans = replaced_sum(x);
    for (int i = cnt - 2; i >= 0; i--) {
        if (cards[i] % 2 != x % 2) {
            ans = max(ans, replaced_sum(cards[i]));
            break;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
