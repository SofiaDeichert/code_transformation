int main ( void ) { int n , i , t , j , k ; int x [ 99 ] [ 99 ] ; scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { scanf ( "%d" , & t ) ; for ( j = 1 ; j <= t ; j ++ ) { for ( k = 1 ; k <= j ; k ++ ) { scanf ( "%d" , & x [ j ] [ k ] ) ; } } for ( j = t - 1 ; j >= 1 ; j -- ) { for ( k = 1 ; k <= j ; k ++ ) { x [ j ] [ k ] = x [ j ] [ k ] + ( x [ j + 1 ] [ k ] > x [ j + 1 ] [ k + 1 ] ) ? x [ j + 1 ] [ k ] : x [ j + 1 ] [ k + 1 ] ; } } printf ( "%d \n" , x [ 1 ] [ 1 ] ) ; } }