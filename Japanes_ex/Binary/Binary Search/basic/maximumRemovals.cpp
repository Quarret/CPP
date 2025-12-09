#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
对于这类要对某个字符串或者数组进行删减操作的
可以用一个数组来记录被删减的信息，不必真实进行操作，这样做会增大时间复杂度
*/
int maximumRemovals(string s, string p, vector<int>& removable) {
    int n = removable.size(), l = 0, r = n + 1, mid = 0, m = p.size(), pos = 0;
    
    vector<int> cnt(removable.begin(), removable.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (removable[j] < removable[i]) cnt[i]--;
        }
    }

    unordered_map<int, string> mp;
    string tmp = s;
    mp[0] = tmp;
    for (int i = 0; i < n; i++) {
        tmp.erase(cnt[i], 1);
        mp[i + 1] = tmp; 
    }

    auto check = [&](int k) -> bool {
        
        tmp = mp[k];

        pos = 0;
        for (int i = 0; i < m; i++) {
            if (i == 0) pos = tmp.find(p[i], pos);
            else pos = tmp.find(p[i], pos + 1);
            if (pos == string::npos) return 0;
        }

        return 1;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return l;
}

int maximumRemovals(string s, string p, vector<int>& removable) {
    int n = removable.size(), m = p.size();
    int l = 0, r = n + 1, mid = 0;

    auto check = [&](int k) -> bool {
        //根据mid值实时跟新del信息
        vector<int> del(s.size(), 0);
        for (int i = 0; i < k; i++) {
            del[removable[i]] = 1;
        }

        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (!del[j] && s[j] == p[i]) i++;
            if (i == m) return 1;
        }

        return 0;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
