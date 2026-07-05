#include <bits/stdc++.h>
using namespace std;

vector<int> primes(5e5 + 1, true);
void pre() {
    primes[1] = false;
    for (int p = 2; p <= 5e5; p++) {
        if (!primes[p]) continue;
        for (int i = p * p; i <= 5e5; i += p) {
            primes[i] = false;
        }   
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> divs(n + 1);
    
    for (int i = 1; i < n; i++) {
        int num = a[i];
        while (num > 1) {
            for (int i = 2; i * i <= n; i++) {
                if (num % i == 0) {
                    num /= i;
                    divs[i]++;
                }
            }
        }
    }
}

int main() {
    pre();

}