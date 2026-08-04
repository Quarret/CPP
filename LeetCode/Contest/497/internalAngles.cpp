#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<double> internalAngles(vector<int>& sides) {
    ranges::sort(sides);
    int a = sides[0], b = sides[1], c = sides[2];
    if (a + b <= c) return {};

    const double rad = 180 / acos(-1);
    double A = acos(1.0 * (b * b + c * c - a * a) / (2 * b * c)) * rad;
    double B = acos(1.0 * (a * a + c * c - b * b) / (2 * a * c)) * rad;
    return {A, B, 180 - A - B};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}