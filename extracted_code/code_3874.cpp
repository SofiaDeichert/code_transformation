int main ( ) { int t , i , j , n , a [ 100 ] [ 100 ] ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i <= n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = n - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { if ( a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ) a [ i ] [ j ] = a [ i ] [ j ] + a [ i + 1 ] [ j ] ; else a [ i ] [ j ] = a [ i ] [ j ] + a [ i + 1 ] [ j + 1 ] ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }