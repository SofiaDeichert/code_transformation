int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , i , j ; int a [ n ] [ n ] ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = n - 1 ; i >= 0 ; i -- ) for ( j = 0 ; j < i ; j ++ ) { if ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) a [ i - 1 ] [ j ] += a [ i ] [ j ] ; else a [ i - 1 ] [ j ] += a [ i ] [ j + 1 ] ; } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } }