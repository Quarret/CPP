#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string largestNumber(vector<int>& nums) {
    vector<string> str;
    int ok = 0;
    for (int num : nums) {
        if (num) {
            ok = 1;
        }
        str.push_back(to_string(num));
    }
    if (!ok) return "0";

    sort(str.begin(), str.end(), [&](string &a, string &b) {
        return a + b > b + a;
    });
    
    string ans = "";
    for (string s : str) {
        ans += s;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
