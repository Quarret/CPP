#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int videoStitching(vector<vector<int>>& clips, int time) {
    sort(clips.begin(), clips.end(), [](auto &x, auto& y) {
        if (x[0] < y[0]) return true;
        else if (x[0] == y[0]) {
            return x[1] > y[1];
        }

        return false;
    });
    
    int ans = 0, cur_r = 0, next_r = 0;
    int j = 0, n = clips.size();
    for (int i = 0; i < time; i++) {
        while (j < n && clips[j][0] <= i) {
            next_r = max(next_r, clips[j][1]);
            j++;
        }

        if (i == cur_r) {
            if (cur_r == next_r) {
                return -1;
            }

            ans++;
            cur_r = next_r;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
