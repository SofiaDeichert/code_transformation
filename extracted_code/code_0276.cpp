int main ( void ) { int a , b , c , d , e , f , i , j ; int sum = 0 ; int x [ 101 ] [ 101 ] ; scanf ( "%d" , & a ) ; printf ( "\n" ) ; while ( a -- ) { scanf ( "%d" , & c ) ; for ( i = 0 ; i < c ; i ++ ) { for ( j = 0 ; j < i ; j ++ ) { scanf ( "%d" , & x [ i ] [ j ] ) ; } } } for ( i = a - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { x [ i ] [ j ] += ( ( x [ i + 1 ] [ j ] > x [ i + 1 ] [ j + 1 ] ) ? x [ i + 1 ] [ j ] : x [ i + 1 ] [ j + 1 ] ) ; } } printf ( "%d\n" , x [ 0 ] [ 0 ] ) ; return 0 ; }