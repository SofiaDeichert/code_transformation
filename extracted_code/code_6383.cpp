int main ( ) { int n ; scanf ( "%d" , & n ) ; while ( n -- ) { int i , j , rows ; scanf ( "%d" , & rows ) ; int a [ rows ] [ rows ] ; for ( i = 0 ; i < rows ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } for ( i = rows - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { if ( a [ i + 1 ] [ j ] > a [ i + 1 ] [ j + 1 ] ) a [ i ] [ j ] += a [ i + 1 ] [ j ] ; else a [ i ] [ j ] += a [ i + 1 ] [ j + 1 ] ; } } printf ( "%d\n" , a [ 0 ] [ 0 ] ) ; } return 0 ; }