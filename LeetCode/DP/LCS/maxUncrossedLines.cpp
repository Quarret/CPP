#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<int> f(m + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int topleft = f[0];
        for (int j = 0; j < m; j++) {
            int tmp = f[j + 1];
            f[j + 1] = nums1[i] == nums2[j] ? topleft + 1 : max(f[j], f[j + 1]);
            topleft = tmp;
        }
    }

    return f[m];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
