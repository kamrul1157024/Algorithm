#include <bits/stdc++.h>
using namespace std ;
 
const int N = 1048579 , BLOCK = 501 , K = 201 ;
int freq[K][N]  , a[N] , pre[N] , c[N] ;
int n ;
const int M = 1e5 + 5 ;
int tree[4*M] , lazy[4*M] ;
 
void upd (int idx , int x) {
    int which = idx/BLOCK ;
    for (int i = idx ; i < min( (which + 1)*BLOCK , n ) ; i++) {
        freq[which][a[i]]-- ;
        a[i] ^= x ;
        freq[which][a[i]]++ ;
    }
    for (int i = which + 1 ; i < K ; i++) {
        pre[i] ^= x ;
    }
}
 
int Query(int idx , int x) {
    int which = idx/BLOCK ;
    int ret = 0 ;
    for (int i = which*BLOCK ; i <= idx ; i++) {
        if ( (a[i]^pre[which]^x) == 0 ) {
            ret++ ;
        }
    }
    for (int i = 0 ; i < which ; i++) {
        int y = x^pre[i] ;
        ret += freq[i][y] ;
    }
    return ret ;
}
 
 
int main () {
 
   // freopen ("in.txt" , "r" , stdin) ;
    int Q ;
    scanf ("%d %d" , &n , &Q) ;
    int tot = 0 ;
    for (int i = 0 ; i < n ; i++) {
        scanf ("%d" , &a[i]) ;
        c[i] = a[i] ;
        if (i) a[i] = a[i - 1] ^ a[i] ;
    }
    for (int i = 0 ; i < n ; i++) {
        freq[i/BLOCK][a[i]]++ ;
    }
    while (Q--) {
        int type , idx , x ;
        scanf ("%d %d %d" , &type , &idx , &x) ;
        idx-- ;
        if (type == 1) {
            int y = x^c[idx] ;
            c[idx] = x ;
            upd(idx,y) ;
        }
        else {
            printf ("%d\n" , Query(idx,x)) ;
        }
    }
}