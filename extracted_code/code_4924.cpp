int main ( ) { int test , row , i , k , j , t ; scanf ( "%d" , & test ) ; for ( t = 0 ; t < test ; t ++ ) { scanf ( "%d" , & row ) ; int a [ row ] [ row ] ; for ( k = 0 ; k < row ; k ++ ) { for ( j = 0 ; j <= k ; j ++ ) { scanf ( "%d" , & a [ k ] [ j ] ) ; } } for ( i = row - 1 ; i > 0 ; i -- ) { for ( j = 0 ; j < row - 1 ; j ++ ) { if ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) a [ i - 1 ] [ j ] = a [ i - 1 ] [ j ] + a [ i ] [ j ] ; else a [ i - 1 ] [ j ] = a [ i - 1 ] [ j ] + a [ i ] [ j + 1 ] ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }