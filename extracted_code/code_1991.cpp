int main ( ) { unsigned int test_case , sizeOfMatrix ; int i , j ; scanf ( "%d" , & test_case ) ; while ( test_case -- ) { scanf ( "%d" , & sizeOfMatrix ) ; unsigned int matrix [ sizeOfMatrix ] [ sizeOfMatrix ] ; for ( i = 0 ; i < sizeOfMatrix ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & matrix [ i ] [ j ] ) ; } } for ( i = sizeOfMatrix - 1 ; i > 0 ; i -- ) { for ( j = 0 ; j < i ; j ++ ) { if ( matrix [ i ] [ j ] > matrix [ i ] [ j + 1 ] ) matrix [ i - 1 ] [ j ] = matrix [ i - 1 ] [ j ] + matrix [ i ] [ j ] ; else matrix [ i - 1 ] [ j ] = matrix [ i - 1 ] [ j ] + matrix [ i ] [ j + 1 ] ; } } printf ( "%d\n" , matrix [ 0 ] [ 0 ] ) ; } return 0 ; }