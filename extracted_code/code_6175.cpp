int main ( ) { long long int n , a [ 200000 ] , sum , k = 0 , i , j , t ; scanf ( "%lld" , & t ) ; while ( t ) { scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%lld" , & a [ i ] ) ; k = 0 ; for ( i = 0 ; i < n - 1 ; i ++ ) { for ( j = i ; j < n - 1 ; j ++ ) { if ( a [ j ] > a [ j + 1 ] ) break ; else k ++ ; } } sum = k + n ; printf ( "%lld\n" , sum ) ; t -- ; } }