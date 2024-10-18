#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<long long> keys(n, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            keys[temp - 1] <<= 1;
            if (j < n / 2){
                keys[temp - 1] += 1;
            }
        }
    }

    unordered_map<long long, int> frequencyMap;

    for (long long num : keys) {
        frequencyMap[num]++;
    }

    int maxFrequency = 0;
    for (const auto& entry : frequencyMap) {
        maxFrequency = max(maxFrequency, entry.second);
    }

    cout << maxFrequency << endl;
    return 0;
}



