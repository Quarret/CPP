#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxDiff(int num) {
    string s1 = to_string(num);        
    string s2 = to_string(num);
    int n = s1.size();
    
    for (int i = 0; i < n; i++) {
        if (s1[i] != '9') {
            char c = s1[i];
            for (; i < n; i++) {
                if (s1[i] == c) {
                    s1[i] = '9';
                }
            }
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s2[i] != '1' && s2[i] != '0') {
            char c = s2[i]; 
            for (int j = i; j < n; j++) {
                if (s2[j] == c) {
                    s2[j] = i ? '0' : '1';
                }
            }
            break;
        }
    }

    return stoi(s1) - stoi(s2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
