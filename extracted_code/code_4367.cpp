int main ( ) { int t ; int n , i , j , x ; int a [ 101 ] [ 101 ] ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; if ( ( n >= 100 ) | ( n < 0 ) ) return 0 ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; if ( ( a [ i ] [ j ] > 99 ) | ( a [ i ] [ j ] < 0 ) ) return 0 ; } } for ( i = n ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { if ( a [ i ] [ j ] >= a [ i - 1 ] [ j ] ) x = a [ i ] [ j ] ; else x = a [ i ] [ j + 1 ] ; a [ i - 1 ] [ j ] = a [ i - 1 ] [ j ] + x ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }