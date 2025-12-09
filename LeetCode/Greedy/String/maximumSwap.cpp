#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximumSwap(int num) {
    string ans = to_string(num);        
    string s = to_string(num);
    
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string s1 = s;
            swap(s1[i], s1[j]);
            ans = max(ans, s1);
        }
    }

    return stoi(ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
