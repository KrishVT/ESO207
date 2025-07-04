#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll poly_eval(const vector<ll>& coeffs, ll x) {
    ll res = 0, power = 1;
    for(ll c : coeffs) {
        res += c * power;
        power *= x;
    }
    return res;
}

bool identity_test(const vector<ll>& p1, const vector<ll>& p2, int trials = 5) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);

    for(int i = 0; i < trials; ++i) {
        int x = dist(gen);
        if(poly_eval(p1, x) != poly_eval(p2, x)) return false;
    }
    return true;
}

int main() {
    vector<ll> p1 = {1,2,3}; // 1 + 2x + 3x^2
    vector<ll> p2 = {1,2,3};
    cout << "Polynomials are" << (identity_test(p1, p2) ? " " : " not ") << "identical\n";
    return 0;
}