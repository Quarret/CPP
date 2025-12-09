#include <bits/stdc++.h>
#define ll long long
using namespace std;
using it = list<int>::iterator;

void solve() {
    list<int> l1, l2;
    for (int i = 0; i < 10; i ++) {
        l1.emplace_back(i);
    }

    for (auto curr = prev(l1.end()); curr != prev(l1.begin()); curr--) {
        //cout << *curr << '\n';
        l2.emplace_back(*curr);
    }

    for (auto it = l2.begin(); it != l2.end(); it++) {
       cout << *it << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
