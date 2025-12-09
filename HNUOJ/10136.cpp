#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, s1;
    while (cin >> s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            s[i] = tolower(s[i]);
        }

        s1 = s;
        reverse(s.begin(), s.end());

        cout << (s == s1 ? "yes\n" : "no\n");
    }

    return 0;
}
