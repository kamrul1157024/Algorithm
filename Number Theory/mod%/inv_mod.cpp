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
    dxy = extendedEuclid(b, a%b);
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

