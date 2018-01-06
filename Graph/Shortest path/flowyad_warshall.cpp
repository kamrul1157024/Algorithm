#include<bits/stdc++.h>
using namespace std;
const int sz=1000+3;
#define INF 1234567;
int mat[sz][sz];
int next[sz][sz];
void fw(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mat[i][j]=INF;
            next[i][j]=j;
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(mat[i][j]>mat[i][k]+mat[k][j])
                {
                  mat[i][j] = mat[i][k] + mat[k][j];
                  next[i][j]=next[i][k];
                }
            }
        }
    }
}

vector<int> getPath(int i,int j)
{
    vector<int> path;
    while(i!=j)
    {
        i=next[i][j];
        path.push_back(i);
    }
    return path;
}


