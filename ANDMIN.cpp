#include <bits/stdc++.h>
using namespace std;

int arr[100005], tree[400005], lazy[400005];

void build_tree(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(node * 2, l, mid);
    build_tree(node * 2 + 1, mid + 1, r);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    return;
}

void update(int node, int l, int r, int l, int r, int x)
{
    if(lazy[node])
    {
        
    }
}
int main()
{
    int n, i, q, x, l, r, a;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
}