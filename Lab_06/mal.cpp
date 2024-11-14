#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> tree, lazy;
    int size;

    SegmentTree(int n) : size(n) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, -1);
    }

    void propagate(int currId, int currL, int currR) {
        int v = lazy[currId];
        if (v == 0){
            tree[currId] = 0;

        } else if (v == 1){
            tree[currId] = currR - currL + 1;
        }


        if (currL != currR && v != - 1) {
            lazy[currId * 2 + 1] = v;
            lazy[currId * 2 + 2] = v;
        }

        lazy[currId] = -1;
    }

    void updateRangeUtil(int currId, int currL, int currR, int targetL, int targetR, int value) {
        propagate(currId, currL, currR);

        if (currL > currR || currL > targetR || currR < targetL)
            return;

        if (currL >= targetL && currR <= targetR) {
            if (value == 0){
                tree[currId] = 0;
            } else {
                tree[currId] = currR - currL + 1;
            }
            if (currL != currR) {
                lazy[currId * 2 + 1] = value;
                lazy[currId * 2 + 2] = value;
            }
            return;
        }

        if (currL != currR) {
            int mid = (currL + currR) / 2;
            updateRangeUtil(currId * 2 + 1, currL, mid, targetL, targetR, value);
            updateRangeUtil(currId * 2 + 2, mid + 1, currR, targetL, targetR, value);
            tree[currId] = tree[currId * 2 + 1] + tree[currId * 2 + 2];
        } else {
            tree[currId] = value;
            lazy[currId] = -1;
        }
    }

    void updateRange(int n, int targetL, int targetR, int value) {
        updateRangeUtil(0, 0, n - 1, targetL - 1, targetR - 1, value);
    }

    int getSum(int n){
        propagate(0, 0, n - 1);
        return (int) tree[0];
    }

};

int main() {
    int n, k;
    cin >> n >> k;
    SegmentTree tree(n);

    int l, r;
    char c;
    for (int i = 0; i < k; i++){
        cin >> l >> r >> c;
        if (c == 'C'){
            tree.updateRange(n, l, r, 0);
        } else {
            tree.updateRange(n, l, r, 1);
        }
        cout << tree.getSum(n) << endl;
    }


    return 0;
}