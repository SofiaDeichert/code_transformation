int main ( ) { int i , j , t , n , a [ 101 ] [ 101 ] , l = 0 ; scanf ( "%d" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , a [ i ] [ j ] ) ; for ( i = n - 1 ; i >= 0 ; i -- ) { for ( j = 0 ; j < i ; j ++ ) { if ( a [ i ] [ j ] < a [ i ] [ j + 1 ] ) a [ i - 1 ] [ j ] += a [ i ] [ j + 1 ] ; else a [ i - 1 ] [ j ] += a [ i ] [ j ] ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }