#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

class CombinationIterator {
public:
    vector<string> ans;
    int N = 0;
    int idx = 0;

    CombinationIterator(string characters, int combinationLength) {
        int n = characters.size();
        string path;

        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (path.size() == combinationLength) {
                ans.push_back(path);
                return;
            }

            if (i == n) {
                return;
            }

            for (int j = i; j < n; j++) {
                path.push_back(characters[j]);
                dfs(j + 1);
                path.pop_back();
            }
        };

        dfs(0);
        N = ans.size();
    }
    
    string next() {
        return ans[idx++];
    }
    
    bool hasNext() {
        return idx < N;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
