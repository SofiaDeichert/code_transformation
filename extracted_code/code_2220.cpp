int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t ) { int n ; scanf ( "%d" , & n ) ; int a [ n + 1 ] [ n + 1 ] , dp [ n + 1 ] [ n + 1 ] ; int i ; int j ; for ( i = 1 ; i <= n ; i ++ ) for ( j = 1 ; j <= n ; j ++ ) { a [ i ] [ j ] = 0 ; dp [ i ] [ j ] = 0 ; } for ( i = 1 ; i <= n ; i ++ ) for ( j = 1 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = 1 ; i <= n ; i ++ ) dp [ i ] [ 0 ] = 0 ; dp [ 1 ] [ 1 ] = a [ 1 ] [ 1 ] ; for ( i = 2 ; i <= n ; i ++ ) for ( j = 1 ; j <= i ; j ++ ) dp [ i ] [ j ] = max ( dp [ i - 1 ] [ j ] , dp [ i - 1 ] [ j - 1 ] ) + a [ i ] [ j ] ; int ans = dp [ n ] [ 1 ] ; for ( i = n , j = 2 ; j < n ; j ++ ) ans = dp [ i ] [ j ] > ans ? dp [ i ] [ j ] : ans ; printf ( "%d\n" , ans ) ; t -- ; } return 0 ; }