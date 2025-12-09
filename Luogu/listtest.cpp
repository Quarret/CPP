#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    list<int> l;
    l.emplace_back(1);
    l.emplace_back(2);
    list<int>::iterator it;
    it = l.begin();
    l.insert(it, 1);
    for(it = l.begin(); it != l.end(); it++) {
        cout << *it << ' ';
    }
}
