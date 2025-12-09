#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {
    int n = answerKey.size(), l = 0, numT = 0, numF = 0, ans = 0;
    
    for (int r = 0; r < n; r++) {
        numT += answerKey[r] == 'T';
        numF += answerKey[r] == 'F';

        while (min(numT, numF) > k) {
            numT -= answerKey[l] == 'T';
            numF -= answerKey[l] == 'F';
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
