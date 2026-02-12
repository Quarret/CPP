#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    string RES = "restaurant", GRO = "grocery", PHA = "pharmacy", ELE = "electronics";
    auto check = [&](int i) {
        if (!isActive[i]) return false;

        if (businessLine[i] != RES && businessLine[i] != GRO 
                && businessLine[i] != PHA && businessLine[i] != ELE) {
            return false;
        }

        if (code[i].empty()) return false;
        for (char c : code[i]) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') 
                || c == '_' || (c >= '0' && c <= '9')) continue;
            return false;
        }

        return true;
    };
    
    int n = code.size();
    vector<vector<int>> ans_type(4);
    for (int i = 0; i < n; i++) {
        if (!check(i)) continue;
        if (businessLine[i] == ELE) ans_type[0].push_back(i);
        else if (businessLine[i] == GRO) ans_type[1].push_back(i);
        else if (businessLine[i] == PHA) ans_type[2].push_back(i);
        else ans_type[3].push_back(i);
    }

    ranges::sort(ans_type[0], {}, [&](int &i) {
        return code[i];
    });

    ranges::sort(ans_type[1], {}, [&](int &i) {
        return code[i];
    });

    ranges::sort(ans_type[2], {}, [&](int &i) {
        return code[i];
    });

    ranges::sort(ans_type[3], {}, [&](int &i) {
        return code[i];
    });

    vector<string> ans;
    for (auto arr : ans_type) {
        for (int idx : arr) {
            ans.push_back(code[idx]);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
