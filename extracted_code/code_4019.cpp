int main ( int argc , char const * argv [ ] ) { freopen ( "input.txt" , "r" , stdin ) ; freopen ( "output.txt" , "w" , stdout ) ; int i , k , j , t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & k ) ; int array [ k ] [ k ] ; for ( i = 0 ; i < k ; i ++ ) { for ( j = 0 ; j < i + 1 ; j ++ ) { scanf ( "%d" , & array [ i ] [ j ] ) ; } } for ( i = k - 1 ; i >= 0 ; i -- ) { for ( j = 0 ; j < i + 1 ; j ++ ) { if ( array [ i ] [ j ] > array [ i ] [ j + 1 ] ) array [ i - 1 ] [ j ] += array [ i ] [ j ] ; else array [ i - 1 ] [ j ] += array [ i ] [ j + 1 ] ; } } printf ( "%d\n" , array [ 0 ] [ 0 ] ) ; } return 0 ; }