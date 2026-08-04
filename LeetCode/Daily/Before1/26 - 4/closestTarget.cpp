#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int closestTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size();

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (words[i] != target) continue;
        if (i <= startIndex) {
            ans = min({ans, startIndex - i, n - (startIndex - i)});
        } else {
            ans = min({ans, i - startIndex, n - (i - startIndex)});
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}