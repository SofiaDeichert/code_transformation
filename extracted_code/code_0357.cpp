int main ( ) { int n , i , r , j ; scanf ( "%d" , & n ) ; while ( n ) { scanf ( "%d" , & r ) ; int a [ r ] [ r ] ; for ( i = 0 ; i < r ; i ++ ) { for ( j = 0 ; j < i + 1 ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = r - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j < i + 1 ; j ++ ) { if ( a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ) { a [ i ] [ j ] = a [ i ] [ j ] + a [ i + 1 ] [ j ] ; } else a [ i ] [ j ] = a [ i ] [ j ] + a [ i + 1 ] [ j + 1 ] ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; n -- ; } return ( 0 ) ; }