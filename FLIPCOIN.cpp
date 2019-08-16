#include <bits/stdc++.h>
using namespace std;
int n, q, arr[100005], tree_h[300010], tree_t[300010], dirty[300010];
void build_tree(int node, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        tree_h[node] = 0;
        tree_t[node] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build_tree(node * 2 + 1, l, mid);
    build_tree(node * 2 + 2, mid + 1, r);
    tree_h[node] = tree_h[node * 2 + 1] + tree_h[node * 2 + 2];
    tree_t[node] = tree_t[node * 2 + 1] + tree_t[node * 2 + 2];
    return;
}
void update(int node, int l, int r, int x, int y)
{
    if (dirty[node])
    {
        if (dirty[node] % 2 == 1)
        {
            int temp = tree_t[node];
            tree_t[node] = tree_h[node];
            tree_h[node] = temp;
        }

        if (l != r)
        {
            dirty[node * 2 + 1] += dirty[node] % 2;
            dirty[node * 2 + 2] += dirty[node] % 2;
        }
        dirty[node] = 0;
    }
    if (l > y || r < x)
        return;
    if (l >= x && r <= y)
    {
        int temp = tree_t[node];
        tree_t[node] = tree_h[node];
        tree_h[node] = temp;
        if (l != r)
        {
            dirty[node * 2 + 1] += 1;
            dirty[node * 2 + 2] += 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2 + 1, l, mid, x, y);
    update(node * 2 + 2, mid + 1, r, x, y);
    tree_h[node] = tree_h[node * 2 + 1] + tree_h[node * 2 + 2];
    tree_t[node] = tree_t[node * 2 + 1] + tree_t[node * 2 + 2];
    return;
}
int query(int node, int l, int r, int x, int y)
{
    if (l > y || r < x)
        return 0;
    if (dirty[node])
    {
        if (dirty[node] % 2 == 1)
        {
            int temp = tree_t[node];
            tree_t[node] = tree_h[node];
            tree_h[node] = temp;
        }

        if (l != r)
        {
            dirty[node * 2 + 1] += dirty[node] % 2;
            dirty[node * 2 + 2] += dirty[node] % 2;
        }
        dirty[node] = 0;
    }
    if (l >= x && r <= y)
    {
        return tree_h[node];
    }
    int left_h, right_h, mid = (l + r) / 2;
    left_h = query(node * 2 + 1, l, mid, x, y);
    right_h = query(node * 2 + 2, mid + 1, r, x, y);
    return left_h + right_h;
}
int main()
{
    int i, x, a, b;
    memset(tree_h, 0, sizeof tree_h);
    memset(tree_t, 0, sizeof tree_t);
    memset(dirty, 0, sizeof dirty);
    cin >> n >> q;
    for (i = 0; i < n; i++)
        arr[i] = 1;
    build_tree(0, 0, n - 1);
    while (q--)
    {
        cin >> x >> a >> b;
        if (x == 0)
        {
            update(0, 0, n - 1, a, b);
            //cout<<"updated\n";
        }
        else
        {
            cout << query(0, 0, n - 1, a, b)<<endl;
        }
    }
    return 0;
}