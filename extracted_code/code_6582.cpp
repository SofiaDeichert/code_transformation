int main ( ) { int i , j , t , n ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; int a [ n ] [ n ] ; for ( i = 0 ; i <= n - 1 ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = n - 1 ; i >= 0 ; i -- ) { for ( j = 0 ; j < i ; j ++ ) { if ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) { a [ i - 1 ] [ j ] = a [ i ] [ j ] + a [ i - 1 ] [ j ] ; } else { a [ i - 1 ] [ j ] = a [ i ] [ j + 1 ] + a [ i - 1 ] [ j ] ; } } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } }