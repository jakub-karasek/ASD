#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9;

struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(int size) : n(size), tree(2 * size, 0) {}

    void update(int idx, long long value) {
        idx += n;
        tree[idx] = value;
        for (idx /= 2; idx > 0; idx /= 2) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
        }
    }

    long long query(int l, int r) {
        long long result = 0;
        l += n;
        r += n;
        while (l < r) {
            if (l % 2 == 1) {
                result += tree[l];
                l++;
            }
            if (r % 2 == 1) {
                r--;
                result += tree[r];
            }
            l /= 2;
            r /= 2;
        }
        return result % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<int> perm(n);

    vector<SegmentTree> trees(k, SegmentTree(n));

    long long result = 0;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        trees[0].update(x - 1,1);
        for (int j = 1; j < k; j++){
            long long pom = trees[j - 1].query(x, n);
            trees[j].update(x - 1, pom);
            if (j == k - 1) result += pom % MOD;
        }
    }

    cout << result % MOD << endl;

}