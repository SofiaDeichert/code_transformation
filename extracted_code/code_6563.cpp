int main ( ) { int n , i , j , k , a [ 100 ] [ 100 ] , b ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & b ) ; for ( j = 0 ; j < b ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) { scanf ( "%d" , & a [ j ] [ k ] ) ; } } for ( j = ( b - 1 ) ; j >= 0 ; j -- ) { for ( k = 0 ; k <= j - 1 ; k ++ ) { if ( a [ j ] [ k ] > a [ j ] [ k + 1 ] ) { a [ j - 1 ] [ k ] = a [ j - 1 ] [ k ] + a [ j ] [ k ] ; } else { a [ j - 1 ] [ k ] = a [ j - 1 ] [ k ] + a [ j ] [ k + 1 ] ; } } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }