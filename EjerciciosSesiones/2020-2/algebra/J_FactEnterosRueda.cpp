#include <bits/stdc++.h>
// Programa para calcular los factores primos de un número
// Complejidad: (log(n) * sqrt(n)) / 3 => O(sqrt(n))
/* Material asociado:
https://drive.google.com/open?id=179OTsXC5rhtMeiNAb6GoFFKfacBa7JRVvP6pc5U3FKI
*/
using namespace std;
typedef long long int lli;

vector<long long> trial_division3(long long n);

int main() {
    lli  n;
    cin >> n;

    auto displayIntFact = [&](vector<lli> factores) {
        int len = factores.size();
        for (int i = 0; i < len-1; i++) {
            cout << factores[i] << ", ";
        }
        cout << factores[len-1] << endl;
    };

    displayIntFact(trial_division3(n));

    return 0;
}



vector<long long> trial_division3(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
