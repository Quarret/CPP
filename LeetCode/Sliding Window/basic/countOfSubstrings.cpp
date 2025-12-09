#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long func(string word, int k) {
    long long n = word.size(), l = 0, num = 0, cnt = 0, ans = 0;
    unordered_map<char, long long> mp;

    for (int r = 0; r < n; r++) {
        if (!mp[word[r]] && (word[r] == 'a' || word[r] == 'e' || word[r] == 'i' || word[r] == 'o' || word[r] == 'u')) num++;
        if (!(word[r] == 'a' || word[r] == 'e' || word[r] == 'i' || word[r] == 'o' || word[r] == 'u')) {
            cnt++;
        }
        mp[word[r]]++;

        while (cnt >= k && num >= 5) {
            mp[word[l]]--;
            if (!mp[word[l]] && (word[l] == 'a' || word[l] == 'e' || word[l] == 'i' || word[l] == 'o' || word[l] == 'u')) num--;
            if (!(word[l] == 'a' || word[l] == 'e' || word[l] == 'i' || word[l] == 'o' || word[l] == 'u')) cnt--;
            l++;
        }

        ans += l;
    }

    return ans; 
}

long long countOfSubstrings(string word, int k) {
    return func(word, k) - func(word, k + 1);
}
long long countOfSubstrings(string word, int k) {
    long long n = word.size(), l1 = 0, l2 = 0, num1 = 0, num2 = 0, ans1 = 0, ans2 = 0, cnt1 = 0, cnt2 = 0;

    unordered_map<char, long long> mp1,mp2;
    for (int r = 0; r < n; r++) {
        if (!mp1[word[r]] && (word[r] == 'a' || word[r] == 'e' || word[r] == 'i' || word[r] == 'o' || word[r] == 'u')) num1++;
        if (!mp2[word[r]] && (word[r] == 'a' || word[r] == 'e' || word[r] == 'i' || word[r] == 'o' || word[r] == 'u')) num2++;
        if (!(word[r] == 'a' || word[r] == 'e' || word[r] == 'i' || word[r] == 'o' || word[r] == 'u')) {
            cnt1++;
            cnt2++;
        }
        mp1[word[r]]++;
        mp2[word[r]]++;

        while (cnt1 >= k && num1 >= 5) {
            mp1[word[l1]]--;
            if (!mp1[word[l1]] && (word[l1] == 'a' || word[l1] == 'e' || word[l1] == 'i' || word[l1] == 'o' || word[l1] == 'u')) num1--;
            if (!(word[l1] == 'a' || word[l1] == 'e' || word[l1] == 'i' || word[l1] == 'o' || word[l1] == 'u')) cnt1--;
            l1++;
        }

        while (cnt2 >= k + 1 && num2 >= 5) {
            mp2[word[l2]]--;
            if (!mp2[word[l2]] && (word[l2] == 'a' || word[l2] == 'e' || word[l2] == 'i' || word[l2] == 'o' || word[l2] == 'u')) num2--;
            if (!(word[l2] == 'a' || word[l2] == 'e' || word[l2] == 'i' || word[l2] == 'o' || word[l2] == 'u')) cnt2--;
            l2++;
        }

        ans1 += l1;
        ans2 += l2;
    }

    return ans1 - ans2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
