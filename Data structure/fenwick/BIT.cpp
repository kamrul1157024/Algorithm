#include<bits/stdc++.h>
using namespace std;
struct BIT
{
	int n;
    vector<int> tree;
    BIT(int sz)
    {
    	tree=vector<int>(sz,0);
    	n=sz;
    }
    void update(int x,int val)
    {
    	for(;x<=n;x+=x&-x)
			tree[x]+=val;
    }

    int query(int x)
    {
    	int sum=0;
    	for(;x>0;x-=x&-x)
			sum+=tree[x];
		return sum;
    }

    int rangeSum(int L,int R)
    {
    	return query(R)-query(L-1);
    }

};
int main()
{
	BIT b(12345);
	b.update(1,1);
	b.update(2,2);
	b.update(3,3);
	cout<<b.rangeSum(2,3);
}
