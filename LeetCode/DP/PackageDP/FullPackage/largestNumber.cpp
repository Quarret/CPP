#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string largestNumber(vector<int>& cost, int target) {
    vector<string> f(target + 1, "");

    auto cmp = [&](string &a, string &b) -> string {
        if (a.size() == b.size()) return a > b ? a : b;
        return a.size() > b.size() ? a : b; 
    };

    for (int i = 1; i < 10; i++) {
        int val = cost[i - 1];
        char c = i + '0';
        for (int j = 0; j <= target; j++) {
            if (j >= val) {
                if (f[j - val] == "" && j - val != 0) continue;
                string s = f[j - val];
                s.push_back(c);
                sort(s.begin(), s.end(), greater());
                f[j] = cmp(f[j], s);
            }
        }
    }

    if (f[target].empty()) return "0";
    return f[target];
}


string largestNumber(vector<int>& cost, int target) {
    vector<string> f(target + 1, ".");

    f[0] = "";
    for (int i = 9; i >= 1; i--) {
        int x = cost[i - 1];
        for (int j = x; j <= target; j++) {
            if (f[j - x] == ".") continue;

            string tmp = f[j - x] + to_string(i);
            if (tmp.size() > f[j].size()) f[j] = tmp;
            else if (tmp.size() == f[j].size()) f[j] = max(tmp, f[j]);
        }
    }

    return f[target] == "." ? "0" : f[target];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
