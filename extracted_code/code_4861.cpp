int main ( ) { int a [ 5 ] [ 10 ] , i , j , n ; scanf ( "%d" , & n ) ; while ( n -- ) { for ( i = 0 ; i > n ; i -- ) for ( j = 0 ; j < i - 1 ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = 0 ; i > n ; i -- ) { for ( j = 0 ; j < i - 1 ; j ++ ) { if ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) { a [ i - 1 ] [ j ] = a [ i - 1 ] [ j ] + a [ i ] [ j ] ; } else { a [ i - 1 ] [ j ] = a [ i - 1 ] [ j ] + a [ i ] [ j + 1 ] ; } printf ( "%d" , a [ i ] [ j ] ) ; } } } }