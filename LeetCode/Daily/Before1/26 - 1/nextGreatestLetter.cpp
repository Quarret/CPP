#include <bits/stdc++.h>
using ll = long long;
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int n = letters.size();
    int idx = ranges::lower_bound(letters, target + 1) - letters.begin();

    if (idx == n) return letters[0];
    return letters[idx];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}