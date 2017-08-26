#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

const int maxn = 1005;
int a[maxn], tree[maxn], lazy[maxn];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) >> 1;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int index, int val) {
    if (start == end) {
        a[index] += val;
        tree[node] += val;
        return;
    }
    int mid = (start + end) >> 1;
    if (start <= index && index <= mid)
        update(node * 2, start, mid, index, val);
    else
        update(node * 2 + 1, mid + 1, end, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return 0;
    if (l <= start && end <= r)
        return tree[node];
    int mid = (start + end) >> 1;
    int a = query(node * 2, start, mid, l, r),
        b = query(node * 2 + 1, mid + 1, end, l, r);
    return a + b;
}

// here is the question: if we modify elements in a range, how to do it efficiently?
// naive method
void update_range_naive(int node, int start, int end, int l, int r, int val) {
    if (r < start || end < l)
        return;
    if (start == end) {
        tree[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    update_range_naive(node * 2, start, mid, l, r, val);
    update_range_naive(node * 2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// lazy propagation
void update_range(int node, int start, int end, int l, int r, int val) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) { // not leaf node
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (r < start || end < l)
        return;
    if (start >= l && end <= r) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    int mid = (start + end) >> 1;
    update_range(node * 2, start, mid, l, r, val);
    update_range(node * 2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query_range(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return 0;
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start >= l && end <= r)
        return tree[node];
    int mid = (start + end) >> 1;
    int a = query(node * 2, start, mid, l, r),
        b = query(node * 2 + 1, mid + 1, end, l, r);
    return a + b;
}

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    build(1, 0, n - 1);
    assert(sum == tree[1]);

    update(1, 0, n - 1, n - 1, 1);
    assert(a[n - 2] + a[n - 1] == query(1, 0, n - 1, n - 2, n - 1));
    update(1, 0, n - 1, n - 1, -1);

    update_range(1, 0, n - 1, 0, n - 1, 1);
    assert(sum + n == query_range(1, 0, n - 1, 0, n - 1));

    return 0;
}
