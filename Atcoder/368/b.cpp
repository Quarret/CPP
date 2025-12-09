#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, num;
    cin >> n;
    priority_queue<int, vector<int>, less<> > pq;

    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }

    ll pos = 0;
    while (1) {
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        //cout << num1 << ' ' << num2 << '\n';
        pq.pop();   
        if (!(num1 > 0 && num2 > 0)) {
            break;
        }
        num1--, num2--;
        pos++;
        pq.push(num1), pq.push(num2);
    }

    cout << pos << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
