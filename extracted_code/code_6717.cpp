int n [ 100 ] [ 100 ] ; int main ( void ) { int t , j , i , l ; scanf ( "%d" , & t ) ; while ( t != 0 ) { scanf ( "%d" , & l ) ; for ( j = 0 ; j < l ; j ++ ) { for ( i = 0 ; i <= j ; i ++ ) { scanf ( "%d" , & n [ j ] [ i ] ) ; } } for ( i = l - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { if ( n [ i + 1 ] [ j ] >= n [ i + 1 ] [ j + 1 ] ) n [ i ] [ j ] += n [ i + 1 ] [ j ] ; else n [ i ] [ j ] += n [ i + 1 ] [ j + 1 ] ; } } printf ( "%d\n" , n [ 0 ] [ 0 ] ) ; t -- ; } return 0 ; }