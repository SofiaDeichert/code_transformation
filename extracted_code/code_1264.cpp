int main ( ) { int n , i , j , k , a [ 100 ] [ 100 ] , lines ; scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { scanf ( "%d" , & lines ) ; for ( j = 0 ; j < lines ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) { scanf ( "%d" , & a [ j ] [ k ] ) ; } } for ( j = lines - 2 ; j >= 0 ; j -- ) { for ( k = 0 ; k <= j ; k ++ ) { if ( a [ j + 1 ] [ k ] > a [ j + 1 ] [ k + 1 ] ) { a [ j ] [ k ] = a [ j ] [ k ] + a [ j + 1 ] [ k ] ; } else { a [ j ] [ k ] = a [ j + 1 ] [ k + 1 ] + a [ j ] [ k ] ; } } } printf ( "\n%d" , a [ 0 ] [ 0 ] ) ; } return 0 ; }