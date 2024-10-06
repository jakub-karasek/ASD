#include <iostream>
#include <vector>

using namespace std;


void printArray(vector<long long> vec, int len){
    for (int i = 0; i < len; i++){
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

int main() {
    long long n;

    cin >> n;

    vector<long long> ceny(n,0);
    vector<long long> NP(n, 0);
    vector<long long> P(n, 0);
    vector<long long> wynik(n, -1);
    long long suma = 0;
    long long minP = 0;
    long long minNP = 0;

    for (int i = 1; i <= n; i++) {
        long long element;
        cin >> element;
        ceny[i] = element;
        wynik[i] = -1;

        if (ceny[i] % 2 == 1) {
            NP[i] = ceny[i];
            P[i] = P[i - 1];
        } else {
            P[i] = ceny[i];
            NP[i] = NP[i - 1];
        }
    }

    for (int i = n; i; i--) {
        suma += ceny[i];

        if (ceny[i] % 2 == 1) {
            minNP = ceny[i];
        } else {
            minP = ceny[i];
        }

        if (suma % 2 == 1) { // mamy wynik
            wynik[n + 1 - i] = suma;
        } else {
            if (P[i - 1] > 0LL && minNP > 0) {
                wynik[n + 1 - i] = max(suma + P[i - 1] - minNP, wynik[n + 1 - i]);
            }

            if (NP[i - 1] > 0LL && minP > 0) {
                wynik[n + 1 - i] = max(suma + NP[i - 1] - minP, wynik[n + 1 - i]);
            }
        }
    }

    cin >> n;

    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        cout << wynik[k] << endl;
    }

    return 0;
}
