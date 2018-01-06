template <class T>
T bigmod(T a,T b,T M)
{
    if(b==0)return 1%M;
    T x=bigmod(a,b/2,M);
    x=(x*x)%M;
    if(b%2)
    x=(x*a%M)%M;
    return x;
}
