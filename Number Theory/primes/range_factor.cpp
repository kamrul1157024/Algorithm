
const int sz=1000;
typedef pair<int, int> PII;
vector<int> primes;
vector<bool> prime(sz, true);
void genPrime(int n) {
 
  for (int i = 2; i <= n; i++) {
    if (prime[i]) {
      for (int j = i * 2; j <= n; j += i) {
          prime[j]=false;
      }
      primes.push_back(i);
    }
  }
}
 
vector<PII> factor[sz];
void genFactor(int n)
{
    for(int i=2;i<=n;i++)
    {
        int temp=i;
        for(int j=0;j<primes.size();j++)
        {
            int cnt=0;
            while(temp%primes[j]==0)
            {
                cnt++;
                temp/=primes[j];
            }
            if(cnt!=0)
            factor[i].push_back(make_pair(primes[j],cnt));
        }
    }
}

