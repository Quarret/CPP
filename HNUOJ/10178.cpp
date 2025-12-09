#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    } else return gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, n;
    cin >> n;
    
    while (n--) {
        cin >> a >> b;
        cout << gcd(a,b) << '\n';
    }
    
    return 0;
}
