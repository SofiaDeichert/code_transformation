int main ( void ) { int a [ 100 ] [ 100 ] , i , j , t , n , p , q ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; } for ( i = n - 1 ; i >= 0 ; i -- ) { for ( j = 0 ; j < i ; j ++ ) { p = a [ i - 1 ] [ j ] + a [ i ] [ j ] ; q = a [ i - 1 ] [ j ] + a [ i ] [ j + 1 ] ; if ( p > q ) a [ i - 1 ] [ j ] = p ; else a [ i - 1 ] [ j ] = q ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }