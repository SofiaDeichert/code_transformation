int main ( ) { int a [ 101 ] [ 101 ] , t , l , i , j ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & l ) ; for ( i = 0 ; i < l ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = l - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { a [ i ] [ j ] += a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ? a [ i + 1 ] [ j ] : a [ i + 1 ] [ j + 1 ] ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }