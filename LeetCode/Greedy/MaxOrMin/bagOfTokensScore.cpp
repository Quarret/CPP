#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    
    int ans = 0, n = tokens.size();
    int i = 0, j = n - 1, score = 0;
    while (i <= j) {
        if (power >= tokens[i]) {
            power -= tokens[i++];
            score++;
        } else {
            if (score == 0) break;
            power += tokens[j--];
            score--;
        }
        ans = max(ans, score);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
