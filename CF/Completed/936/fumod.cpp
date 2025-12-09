#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    ll num = -3;
    cout << (num % 2 + 2) % 2 << '\n';
    cout << ((num - 2) % 2 + 2) % 2 << '\n';
}
