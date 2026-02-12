#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countVowels(string word) {
    using ll = long long;
    ll ans = 0;
    
    int n = word.size();
    for (int i = 0; i < n; i++) {
        if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') continue;
        ll l = i + 1, r = n - i;
        ans += l * r;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}