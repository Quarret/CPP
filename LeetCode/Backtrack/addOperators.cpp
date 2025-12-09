#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<string> addOperators(string num, int target) {
    int n = num.size();
    string path(n - 1, ' ');
    vector<char> op = {'+', '-', '*'};
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n - 1) {
            string tmp = path;


        }

        for (int j = 0; j < 3; j++) {
            path[i] = op[j];
            dfs(i + 1);
        }
    };
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
