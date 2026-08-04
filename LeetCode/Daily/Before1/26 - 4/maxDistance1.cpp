#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxDistance(vector<int>& colors) {
    int n = colors.size();
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (colors[i] != colors[j]) ans = max(ans, abs(i - j));
        }
    }

    return ans;
}

// 两不同房子一定包含 0 和 n - 1
int maxDistance(vector<int>& colors) {
    int n = colors.size();
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i] != colors[0]) ans = max(ans, i);
    }

    for (int i = 0; i < n; i++) {
        if (colors[i] != colors[n - 1]) ans = max(ans, n - 1 - i);
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}