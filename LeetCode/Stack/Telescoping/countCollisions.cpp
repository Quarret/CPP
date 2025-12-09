#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countCollisions(string directions) {
    int n = directions.size();
    stack<char> st;
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (!st.empty() && directions[i] == 'L') {
            if (st.top() == 'S') {
                ans++;
                st.pop();

                while (!st.empty() && st.top() == 'R') {
                    ans++;
                    st.pop();
                }

                st.push('S');
            } else if (st.top() == 'R') {
                ans += 2;
                st.pop();

                while (!st.empty() && st.top() == 'R') {
                    ans++;
                    st.pop();
                }
                st.push('S');
            } else st.push('L');
        } else if (!st.empty() && directions[i] == 'S') {
            while (!st.empty() && st.top() == 'R') {
                ans++;
                st.pop();
            }
            st.push('S');
        } else st.push(directions[i]);
    }

    return ans;
}

/*
灵神思路：反想
题目答案会撞车的数量（非S的）

有哪些车永远不会被撞
答：在左侧向左的车，在右侧向右的车

中间车辆减去S的车辆便是主动撞车的数量
*/
int countCollisions(string directions) {
    int n = directions.size(), l = 0, r = n - 1, ans = 0;

    while (l <= r && directions[l] == 'L') l++;
    while (l <= r && directions[r] == 'R') r--;//注意判定l <= r，不然后续for循环会出问题
    for (int i = l ; i <= r; i++) if (directions[i] != 'S') ans++;

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
