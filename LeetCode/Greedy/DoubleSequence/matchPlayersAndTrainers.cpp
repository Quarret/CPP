#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    int n = players.size(), m = trainers.size();
    sort(players.begin(), players.end());        
    sort(trainers.begin(), trainers.end());        

    int j = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && trainers[j] < players[i]) {
            j++;
        }

        if (j == m) {
            break;
        } else {
            j++;
            ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
