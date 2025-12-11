#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int MX = 1e9 + 1;
int d[MX];
int init = [] {
    d[1] = 1;
    for (int i = 2; i < MX; i++) {
        if (d[i]) continue;;
        for (int j = i; j < MX; j += 2) {
            d[j] = i;
        }
    }

    return 0;
}();

class Solution {
public:
    bool completePrime(int num) {
        string s = to_string(num);
        string pre = "", suf = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            pre.push_back(s[i]);
            int x = stoi(pre);
            if (d[x] != x) {
                return false;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            suf.push_back(s[i]);
            int x = stoi(suf);
            if (d[x] != x) {
                return false;
            }
        }

        return true;
    }
};


bool completePrime(int num) {
    string s = to_string(num);
    string pre = "", suf = "";
    int n = s.size();
    
    auto isPrime = [&](int x) -> bool {
        if (x == 1) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }

        return true;
    };

    for (int i = 0; i < n; i++) {
        pre.push_back(s[i]);
        int x = stoi(pre);
        if (x == 1) return false;
        if (!isPrime(x)) {
            return false;
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        suf.insert(0, 1, s[i]);
        int x = stoi(suf);
        if (x == 1) return false;
        if (!isPrime(x)) {
            return false;
        }
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
