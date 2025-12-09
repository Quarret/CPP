#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int sum = accumulate(apple.begin(), apple.end(), 0);
    sort(capacity.begin(), capacity.end(), greater());
    
    int m = capacity.size(), pre = 0;
    for (int i = 0; i < m; i++) {
        pre += capacity[i];
        if (pre >= sum) {
            return i + 1;
        }
    }

    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
