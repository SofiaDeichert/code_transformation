typedef long long ll ; typedef unsigned long long ull ; ll getnum ( ) { char ch ; ll num = 0 ; while ( ! isdigit ( ch = gc ( ) ) ) ; do { num = num * 10 + ( ch - '0' ) ; } while ( isdigit ( ch = gc ( ) ) ) ; return num ; } void sort ( int a [ ] , int begin , int mid , int end ) { int i = begin , j = mid + 1 , k = 0 , temp [ end - begin + 1 ] ; while ( i <= mid && j <= end ) { if ( a [ i ] >= a [ j ] ) temp [ k ++ ] = a [ i ++ ] ; else temp [ k ++ ] = a [ j ++ ] ; } for ( ; i <= mid ; ++ i ) temp [ k ++ ] = a [ i ] ; for ( ; j <= end ; ++ j ) temp [ k ++ ] = a [ j ] ; for ( i = 0 ; i < k ; ++ i ) a [ begin + i ] = temp [ i ] ; } void partition ( int a [ ] , int begin , int end ) { if ( begin == end ) return ; int mid = ( begin + end ) / 2 ; partition ( a , begin , mid ) ; partition ( a , mid + 1 , end ) ; sort ( a , begin , mid , end ) ; } ll gcd ( ll a , ll b ) { if ( a == 0 ) return b ; return gcd ( b % a , a ) ; } int main ( ) { int t = getnum ( ) , i , j , found ; while ( t -- ) { ll a , b , k ; a = getnum ( ) ; b = getnum ( ) ; k = gcd ( a , b ) ; printf ( "%lld %lld\n" , k , ( a * b ) / k ) ; } return 0 ; }