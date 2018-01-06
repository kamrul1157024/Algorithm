#include <bits/stdc++.h>
using namespace std;
const int sz = 1000000+3;
typedef long long ll;

int mod(int a, int b) { return a % b; }
struct three {
  int one, two, three;
};
three extendedEuclid(int a, int b) {
  three dxy;
  if (b == 0) {
    dxy.one = a;
    dxy.two = 1;
    dxy.three = 0;

    return dxy;
  } else {
    int t, t2;
    dxy = extendedEuclid(b, mod(a, b));
    t = dxy.two;
    t2 = dxy.three;
    dxy.two = dxy.three;
    dxy.three = t - a / b * t2;

    return dxy;
  }
}

int invMod(int num, int mod) {
  three ptr;
  ptr = extendedEuclid(num, mod);
  return ptr.two + mod;
}

ll f[sz], invf[sz];
void fact(ll n, ll mod) {
  f[0] = 1, invf[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = (i % mod * f[i - 1] % mod) % mod;
 //   invf[i] = (invMod(i, mod) * invf[i - 1] % mod) % mod;
  }
}

ll ncr(ll n, ll r, ll mod) {
  ll ans = (f[n] % mod * invMod(f[r],mod) * invMod(f[n-r],mod)) % mod;
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
