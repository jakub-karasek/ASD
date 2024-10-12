#include <iostream>

using namespace std;

const long long mod = 1000 * 1000 * 1000;

void countStep(long long*** arr, int* s, int x, int y) {
    if (s[y + 1] > s[y]) arr[y][x][0] += arr[y + 1][x][0];
    if (s[x] > s[y]) arr[y][x][0] += arr[y + 1][x][1];
    if (s[y] < s[x]) arr[y][x][1] += arr[y][x - 1][0];
    if (s[x - 1] < s[x]) arr[y][x][1] += arr[y][x - 1][1];
    arr[y][x][0] %= mod;
    arr[y][x][1] %= mod;
}

int main() {
    int len;
    cin >> len;

    // Create dynamic arrays for dane and arr
    int* dane = new int[len];

    for (int i = 0; i < len; i++) {
        cin >> dane[i];
    }

    // Create a dynamic 3D array (arr) with dimensions [len][len][2]
    long long*** arr = new long long**[len];
    for (int i = 0; i < len; i++) {
        arr[i] = new long long*[len];
        for (int j = 0; j < len; j++) {
            arr[i][j] = new long long[2];
            if (i == j) {
                arr[i][j][0] = 1;
                arr[i][j][1] = 0;
            } else {
                arr[i][j][0] = 0;
                arr[i][j][1] = 0;
            }
        }
    }

    // Processing steps
    for (int i = 1; i < len; i++) {
        int temp = 0;
        for (int o = i; o < len; o++) {
            countStep(arr, dane, temp + i, temp);
            temp++;
        }
    }

    // Print result
    cout << (arr[0][len - 1][0] + arr[0][len - 1][1]) % mod << endl;

    // Free the dynamically allocated memory
    delete[] dane;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
