#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> pos = {3,5,2,6}, heal = {10,10,15,12};
/*
灵神思路:
不变动positon，用id数组记录position大小关系的序列号，直接改动heal，不另外创建其他数组
sort(id.begin(), id.end(), [&](int x, int y) {
    return positons[x] < positions[y];
});
*/
vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    unordered_map<int, pair<int, char>> mp;
    vector<int> st, nums;
    for (int i = 0; i < n; i++) {
        mp[positions[i]].first = healths[i];
        mp[positions[i]].second = directions[i];
        nums.push_back(positions[i]);
    }
    sort(nums.begin(), nums.end());
    
    for (auto& it : nums) {
        st.push_back(it);
        //cout << it.first << ' ';

        while (st.size() > 1) {
            int hp1 = mp[st.back()].first, hp2 = mp[st[st.size() - 2]].first;
            char dir1 = mp[st.back()].second, dir2 = mp[st[st.size() - 2]].second;

            if (dir1 == 'L' && dir2 == 'R') {
                if (hp2 > hp1) {
                    mp[st.back()].first = 0;
                    st.pop_back();
                    mp[st.back()].first--;
                } else if (hp1 == hp2) {
                    mp[st.back()].first = 0;
                    st.pop_back();
                    mp[st.back()].first = 0;
                    st.pop_back();
                } else {
                    int num = st.back();
                    mp[st.back()].first--;
                    st.pop_back();
                    mp[st.back()].first = 0;
                    st.pop_back();
                    st.push_back(num);
                }
            } else break;
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (mp[positions[i]].first) ans.push_back(mp[positions[i]].first);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    survivedRobotsHealths(pos, heal, "RLRL");

    return 0;
}
