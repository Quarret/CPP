#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    queue<int> q1, q2;

    for (int i = 0; i < 10; i++) {
        q1.push(i);
    }

    int k, num = 0;
    cin >> k;
    int n = q1.size();
    for (int i = 0; i < n; i++) {
        if (k != num) {
            int num1 = q1.front();
            q1.pop();//不知道为什么queue里面没enqueue和dequeue,有push pop
            q2.push(num1);
        } else {
            q1.pop();
        }
        num++;
    }
    n = q2.size();
    for (int i = 0; i < n; i++) {
        int num1 = q2.front();
        cout << num1 << ' ';
        q2.pop();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
