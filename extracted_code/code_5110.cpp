int main ( ) { int t , n , i , j , k , a [ 100 ] [ 100 ] ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d" , & n ) ; for ( j = 0 ; j < n ; j ++ ) for ( k = 0 ; k <= j ; k ++ ) scanf ( "%d" , & a [ j ] [ k ] ) ; for ( j = n - 2 ; j >= 0 ; j -- ) for ( k = 0 ; k <= i ; k ++ ) if ( a [ j + 1 ] [ k ] < a [ j + 1 ] [ k + 1 ] ) a [ j ] [ k ] += a [ j + 1 ] [ k + 1 ] ; else a [ j ] [ k ] += a [ j + 1 ] [ k ] ; printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }