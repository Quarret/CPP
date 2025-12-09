#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int removeAlmostEqualCharacters(string word) {
    int n = word.size(), ans = 0;
    for (int i = 1; i < n; i++) {
        if (abs(word[i] - word[i - 1]) <= 1) {
            ans++;
            // 修改的数字保证与 word[i + 1] 不同
            i++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
