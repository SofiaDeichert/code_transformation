int main ( ) { int test , n , i , j , a [ 1000 ] [ 1000 ] ; scanf ( "%d" , & test ) ; while ( test -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { a [ i ] [ j ] = ( a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ) ? a [ i + 1 ] [ j ] : a [ i + 1 ] [ j + 1 ] ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }