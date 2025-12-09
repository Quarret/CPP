#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    unordered_map<string, int> mp{{"X--", -1}, {"--X", -1}, {"X++", 1}, {"++X", 1}};
    
    int x = 0;
    for (string s : operations) {
        x += mp[s];
    }

    return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
