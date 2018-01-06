#include <bits/stdc++.h>
using namespace std;
#define what(c) cout << #c << " -> " << c << endl;
typedef long long ll;
const int sz = 100000 * 2 + 5;
vector<ll> tree(4 * sz, 0);
int n, q;
void init(int l, int r, int node = 1) {
  if (l == r) {
    if (l <= n)
      tree[node] = 1;
    else
      tree[node] = 0;
    return;
  }
  int mid = (l + r) / 2;
  int left = node * 2;
  int right = node * 2 + 1;
  init(l, mid, left);
  init(mid + 1, r, right);
  tree[node] = tree[left] + tree[right];
}
void update(int l, int r, int i, ll val, int node = 1) {
  if (i < l || i > r)
    return;
  if (l == r && l == i) {
    tree[node] = val;
    return;
  }
 
  int mid = (l + r) / 2;
  int left = node * 2;
  int right = node * 2 + 1;
  update(l, mid, i, val, left);
  update(mid + 1, r, i, val, right);
 
  tree[node] = tree[left] + tree[right];
}
 
int query(int l, int r, int val, int node = 1) {
  if (l == r)
    return l;
 
  int mid = (l + r) / 2;
  int left = node * 2;
  int right = node * 2 + 1;
 
  if (tree[left] < val)
    return query(mid + 1, r, val - tree[left], right);
  else
    return query(l, mid, val, left);
}
 
int main() {
  //freopen("in", "r", stdin);
  int t, cs = 1;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &q);
    init(1, n + q + 1);
    int a[n + q + 2];
    memset(a, -1, sizeof a);
    int i;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    printf("Case %d:\n", cs++);
    for (int j = 0; j < q; j++) {
      char c[3];
      scanf("%s", c);
      // cout<<c<<endl;
      if (c[0] == 'c') {
        int val;
        scanf("%d", &val);
        int x = query(1, n + q + 1, val);
        update(1, n + q + 1, x, 0);
        // what(x);
        if (a[x] != -1)
          printf("%d\n", a[x]);
        else
          printf("none\n");
 
      } else {
        scanf("%d", &a[i]);
        update(1, n + q + 1, i, 1);
        i++;
      }
    }
  }
}