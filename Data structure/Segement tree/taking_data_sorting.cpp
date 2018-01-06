#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int sz = 100000 + 5;
const ll mod = 1000000007;
vector<ll> tree(4 * sz, 0);
 
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
 
ll query(int l, int r, int i, int j, int node = 1) {
  if (j < l || i > r)
    return 0;
  if (l >= i && r <= j)
    return tree[node];
  int mid = (l + r) / 2;
  int left = node * 2;
  int right = node * 2 + 1;
  ll x = query(l, mid, i, j, left);
  ll y = query(mid + 1, r, i, j, right);
  return x + y;
}
 
int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  int t, cs = 1;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > a;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      a.push_back(make_pair(x, i));
    }
    sort(a.begin(), a.end());
    ll sum = 0, prev = 0, cnt = 0;
    for (int i = 0; i < a.size(); i++) {
      // cout << a[i].first << " " << a[i].second << endl;
 
      ll x = (1 + query(1, n, 1, a[i].second - 1));
      x%=mod;
      //cout<<x<<endl;
      if (i > 0) {
        if (a[i - 1].first == a[i].first) {
          x = (x - prev);
          prev =( prev%mod + x%mod)%mod;
        } else {
          prev = x;
        }
      } else {
        prev = x;
      }
      update(1, n, a[i].second, x);
      sum = (sum % mod + x % mod) % mod;
      //  cout << sum << endl;
    }
    printf("Case %d: %lld\n", cs++, sum);
    tree.clear();
    tree.resize(4 * sz, 0);
  }
}
