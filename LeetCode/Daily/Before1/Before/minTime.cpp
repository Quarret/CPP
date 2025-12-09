#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minTime(vector<int>& skill, vector<int>& mana) {
    int n = skill.size(), m = mana.size();
    vector<long long> last_finish(n); 

    for (int m : mana) {
        long long sum_t = 0;
        for (int i = 0; i < n; i++) {
            sum_t = max(sum_t, last_finish[i]) + skill[i] * m;
        }

        last_finish[n - 1] = sum_t;
        for (int i = n - 2; i >= 0; i--) {
            last_finish[i] = last_finish[i + 1] - skill[i + 1] * m;
        }
    }

    return last_finish[n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
