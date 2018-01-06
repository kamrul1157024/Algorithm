#include <bits/stdc++.h>
using namespace std;
const int sz = 1000000 + 3;
typedef long long ll;

template <class T> T bigmod(T a, T b, T M) {
  if (b == 0)
    return 1 % M;
  T x = bigmod(a, b / 2, M);
  x = (x * x) % M;
  if (b % 2)
    x = (x * a % M) % M;
  return x;
}

ll f[sz], invf[sz];
void fact(ll n, ll mod) {
  f[0] = 1, invf[0] = 1;
  for (ll i = 1; i <= n; i++) {
    f[i] = (i % mod * f[i - 1] % mod) % mod;
  }
}

ll ncr(ll n, ll r, ll mod) {
  ll ans = (f[n] % mod * bigmod(f[r],mod-2,mod) % mod * bigmod(f[n-r],mod-2,mod)% mod) % mod;
  return ans;
}

int main() {
  int t, cs = 1;
  fact(sz, 1000003);
  scanf("%d", &t);
  while (t--) {
    ll n, r;
    scanf("%lld %lld", &n, &r);
    printf("Case %d: %lld\n", cs++, ncr(n, r, 1000003));
  }
}
