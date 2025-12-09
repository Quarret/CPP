#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int compareVersion(string version1, string version2) {
    string s = "";
    vector<int> v1, v2;
    for (char c : version1) {
        if (c == '.') {
            v1.push_back(stoi(s));
            s.clear();
        } else s += c;
    }
    v1.push_back(stoi(s));
    s.clear(); 
    
    for (char c : version2) {
        if (c == '.') {
            v2.push_back(stoi(s));
            s.clear();
        } else s += c;
    }
    v2.push_back(stoi(s));
    s.clear();
    
    int a = v1.size(), b = v2.size();
    for (int i = 0; i < max(a, b); i++) {
        int num1 = i >= a ? 0 : v1[i];
        int num2 = i >= b ? 0 : v2[i];

        if (num1 != num2) return num1 > num2 ? 1 : -1;
    }

    return 0;
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
