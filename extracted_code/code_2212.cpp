int main ( ) { long long int t , a [ 105 ] [ 105 ] , i , j , n ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j < i + 1 ; j ++ ) scanf ( "%lld" , & a [ i ] [ j ] ) ; } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j < i + 1 ; j ++ ) { if ( a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ) a [ i ] [ j ] += a [ i + 1 ] [ j ] ; else a [ i ] [ j ] += a [ i + 1 ] [ j + 1 ] ; } } printf ( "%lld\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }