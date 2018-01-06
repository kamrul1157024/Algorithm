#include <bits/stdc++.h>
using namespace std;
const int sz = 1000000 + 3;
typedef long long ll;

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
    dxy = extendedEuclid(b,a%b);
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
  ll ans = (f[n] % mod * invMod(f[r], mod) * invMod(f[n - r], mod)) % mod;
  return ans;
}

int lucas(int n, int r, int p) {
  if (r == 0)
    return 1;
  return (lucas(n / p, r / p, p) * ncr(n % p, r % p, p)) % p;
}
int main() {
  int t,cs=1;
  scanf("%d",&t);
  fact(sz, 1000003);

  while(t--)
  {
      int n,r;
      scanf("%d %d",&n,&r);
      printf("Case %d: %d\n", cs++, lucas(n, r, 1000003));
  }
}

