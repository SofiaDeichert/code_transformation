int main ( ) { int t , n , i , j ; char a [ 100 ] [ 100 ] ; scanf ( "%d" , & t ) ; for ( ; t > 0 ; t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; } for ( i = n - 1 ; i >= 0 ; i -- ) { for ( j = 0 ; j < i ; j ++ ) { if ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) a [ i - 1 ] [ j ] = a [ i - i ] [ j ] + a [ i ] [ j ] ; else a [ i - 1 ] [ j ] = a [ i - 1 ] [ j ] + a [ i ] [ j + 1 ] ; } } printf ( "%d" , a [ 0 ] [ 0 ] ) ; } return 0 ; }