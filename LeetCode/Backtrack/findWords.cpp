#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int m = board.size(), n = board[0].size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    unordered_map<string, int> mp;

    int maxlen = 0;
    for (string s : words) {
        maxlen = max(maxlen, (int)s.size());
        mp[s] = 1;
    }

    unordered_set<string> st;
    auto dfs = [&](this auto&& dfs, int x, int y, string path) -> void {
        char c = board[x][y];
        path += c;
        if (mp[path]) {
            st.insert(path);
        }

        if (path.size() == maxlen) {
            return;
        }
        
        board[x][y] = ' ';
        for (auto &[dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || board[nx][ny] == ' ') continue;
            dfs(nx, ny, path);
        }
        board[x][y] = c;
    };
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dfs(i, j, "");
        }
    }
    
    vector<string> ans(st.begin(), st.end());
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
