#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;

    cin >> n;

    vector<long long> prices(n,0);
    vector<long long> odd(n, 0);
    vector<long long> even(n, 0);
    vector<long long> result(n, -1);
    long long sum = 0;
    long long minP = 0;
    long long minNP = 0;

    for (int i = 1; i <= n; i++) {
        long long element;
        cin >> element;
        prices[i] = element;
        result[i] = -1;

        if (prices[i] % 2 == 1) {
            odd[i] = prices[i];
            even[i] = even[i - 1];
        } else {
            even[i] = prices[i];
            odd[i] = odd[i - 1];
        }
    }

    for (int i = n; i; i--) {
        sum += prices[i];

        if (prices[i] % 2 == 1) {
            minNP = prices[i];
        } else {
            minP = prices[i];
        }

        if (sum % 2 == 1) {
            result[n + 1 - i] = sum;
        } else {
            if (even[i - 1] > 0LL && minNP > 0) {
                result[n + 1 - i] = max(sum + even[i - 1] - minNP, result[n + 1 - i]);
            }

            if (odd[i - 1] > 0LL && minP > 0) {
                result[n + 1 - i] = max(sum + odd[i - 1] - minP, result[n + 1 - i]);
            }
        }
    }

    cin >> n;

    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        cout << result[k] << endl;
    }

    return 0;
}
