main ( ) { int t , n , i , j ; int a [ 105 ] [ 105 ] ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) scanf ( "%lld" , & a [ i ] [ j ] ) ; } for ( i = n - 1 ; i > 0 ; i -- ) { for ( j = i ; j > 0 ; j -- ) { if ( a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ) a [ i ] [ j ] += a [ i + 1 ] [ j ] ; else a [ i ] [ j ] += a [ i + 1 ] [ j + 1 ] ; } } printf ( "%d\n" , a [ 1 ] [ 1 ] ) ; } return 0 ; }