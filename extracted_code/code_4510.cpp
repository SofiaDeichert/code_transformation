int main ( ) { int num , i , j ; int trail ; scanf ( "%d" , & trail ) ; while ( trail -- ) { int a [ 100 ] [ 100 ] ; scanf ( "%d" , & num ) ; for ( i = 0 ; i < num ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( i = num - 1 ; i >= 0 ; i -- ) { for ( j = 0 ; j < i ; j ++ ) { if ( a [ i ] [ j ] > a [ i ] [ j + 1 ] ) a [ i - 1 ] [ j ] += a [ i ] [ j ] ; else a [ i - 1 ] [ j ] += a [ i ] [ j + 1 ] ; } } printf ( "\n%d" , a [ 0 ] [ 0 ] ) ; } return 0 ; }