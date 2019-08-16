#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll arr[50005];

struct tree
{
    ll lSum, rSum, mSum;
} tree[1000005];

void compute(ll node, ll l_node, ll r_node)
{
    tree[node].mSum = max(tree[l_node].rSum + tree[r_node].lSum, max(tree[l_node].mSum, tree[r_node].mSum));
    tree[node].rSum = tree[r_node].lSum;
    tree[node].lSum = tree[l_node].rSum;

    tree[node].mSum = max(tree[node].mSum, max(tree[node].lSum, tree[node].rSum));
}
void make_tree(ll node, ll l, ll r)
{
    if (l == r)
    {
        tree[node].mSum = tree[node].lSum = tree[node].rSum = arr[l];
        return;
    }

    ll mid = (l + r) / 2;

    make_tree(node * 2, l, mid);
    make_tree(node * 2 + 1, mid + 1, r);

    compute(node, node * 2, node * 2 + 1);
    return;
}

ll query(ll node, ll l, ll r, ll x, ll y)
{
    if (x > r || y < l)
        return -1000000007;
    if (l >= x && r <= y)
        return tree[node].mSum;

    ll mid = (l + r) / 2;

    ll l_result = query(node * 2, l, mid, x, y);
    ll r_result = query(node * 2 + 1, mid + 1, r, x, y);

    return max(l_result, r_result);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m, x, y, i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    make_tree(1, 1, n);
    cin >> m;
    while (m--)
    {
        cin >> x >> y;
        cout << query(1, 1, n, x, y) << endl;
    }

    return 0;
}