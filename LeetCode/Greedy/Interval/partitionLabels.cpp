#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> partitionLabels(string s) {
    int cnt[26]{};
    for (char c : s) {
        cnt[c - 'a']++;
    }
    
    int n = s.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        unordered_set<int> st;
        for (int j = i; j < n; j++) {
            int c = s[j] - 'a';
            if (!st.contains(c)) {
                sum += cnt[c];
                st.insert(c);
            }
            sum--;

            if (sum == 0) {
                ans.push_back(j - i + 1);
                i = j;
                break;
            }
        }
    }

    return ans;
}

vector<int> partitionLabels(string s) {
    int n = s.size();
    int last[26]{};
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] = i;
    }
    
    vector<int> ans;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        end = max(end, last[s[i] - 'a']);

        if (i == end) {
            ans.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
