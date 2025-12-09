#include <bits/stdc++.h>
using ll = long long;
using namespace std;


vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    const int VOWEL_MASK = 0x104111;
    vector<char> vowels = {'a', 'i', 'e', 'u', 'o'};
    unordered_map<string, string> mp1, mp2, mp3;
    for (string s : wordlist) {
        mp1[s] = s;

        string toLowerS = "";
        for (char c : s) toLowerS.push_back(tolower(c));
        if (mp2[toLowerS] == "") mp2[toLowerS] = s;

        queue<string> q;
        q.push(toLowerS);
        unordered_map<string, int> vis;

        while (!q.empty()) {
            string s1 = q.front();
            q.pop();
            vis[s1] = 1;

            for (int i = 0; i < s1.size(); i++) {
                int val = s1[i] - 'a';
                if ((VOWEL_MASK >> val) & 1 == 0) continue;
                for (char c : vowels) {
                    string tmp = s1;
                    s1[i] = c;
                    if (mp3[tmp] == "") {
                        mp3[tmp] = s1;
                        vis[tmp] = 1;
                        q.push(tmp);
                    } 
                 }
            }
        }
    }

    
    for (auto [s, s1] : mp3) {
        cout << s << ' ' << s1 << '\n';
    }
    
    vector<string> ans;
    for (string s : queries) {
        if (mp1[s] != "") {
            ans.push_back(mp1[s]);
            continue;
        }
        
        int t = s.size();
        for (int i = 0; i < t; i++) {
            s[i] = tolower(s[i]);
        }

        if (mp2[s] != "") {
            ans.push_back(mp2[s]);
            continue;
        }
        

        
        queue<string> q;
        q.push(s);
        unordered_map<string, int> vis;
        vis[s] = 1;
        string res = "";

        while (!q.empty()) {
            string s = q.front();
            q.pop();
            vis[s] = 1;

            for (int i = 0; i < t; i++) {
                int val = s[i] - 'a';
                if (VOWEL_MASK >> val & 1 == 0) continue;
                for (char c : vowels) {
                    string tmp = s;
                    tmp[i] = c;
                    if (vis[tmp]) continue;
                    if (mp3[tmp] != "" && res != "") {
                        res = mp3[tmp];
                    }
                    vis[tmp] = 1;
                    q.push(tmp);
                } 
            }
        }

        ans.push_back(res);
    }

    return ans;
}


vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    auto lower = [&](string s) -> string {
        string res = "";
        for (char c : s) {
            res += tolower(c);
        }

        return res;
    };
    
    auto vowel_to_sample = [&](string s) -> string {
        string res = "";
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o') res += '?';
            else res += c;
        }

        return res;
    };

    unordered_map<string, string> mp1, mp2, mp3;
    for (string s : wordlist) {
        if (mp1[s] == "") mp1[s] = s;

        string s1 = lower(s);
        if (mp2[s1] == "") mp2[s1] = s;
        
        string s2 = vowel_to_sample(s1);
        if (mp3[s2] == "") mp3[s2] = s;
    }

    vector<string> ans;
    for (string s : queries) {
        if (mp1[s] != "") {
            ans.push_back(mp1[s]);
            continue;
        }
        
        string s1 = lower(s);
        if (mp2[s1] != "") {
            ans.push_back(mp2[s1]);
            continue;
        }

        string s2 = vowel_to_sample(s1);
        ans.push_back(mp3[s2]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
