#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int check(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1, mid = 0;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (letters[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return l;
}
char nextGreatestLetter(vector<char>& letters, char target) {
        int ans = check(letters, (char)(target + 1));

        if (ans == letters.size()) return letters[0];
        return letters[ans];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
