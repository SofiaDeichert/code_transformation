short int sum [ 2 ] [ 10000002 ] ; short int curr [ 10000002 ] ; int main ( ) { int test , lines , i = 0 , prsnt = 1 , j = 0 ; scanf ( "%d" , & test ) ; while ( test -- > 0 ) { prsnt = 1 ; j = 0 ; i = 0 ; scanf ( "%d" , & lines ) ; for ( i = 0 ; i < 10000002 ; i ++ ) { sum [ 0 ] [ i ] = sum [ 1 ] [ i ] = curr [ i ] = - 1 ; } while ( lines >= prsnt ) { for ( i = 0 ; curr [ i ] > - 1 ; i ++ ) { curr [ i ] = - 1 ; } for ( i = 0 ; i < prsnt ; i ++ ) scanf ( "%hd" , & curr [ i ] ) ; i = 0 ; if ( prsnt == 1 ) { while ( curr [ i ] != - 1 ) { sum [ 0 ] [ i ] = curr [ i ] ; i ++ ; } } else { j = 0 ; for ( i = 0 ; sum [ 0 ] [ i ] != - 1 ; i ++ ) { sum [ 1 ] [ j ] = sum [ 0 ] [ i ] + curr [ i ] ; j ++ ; sum [ 1 ] [ j ] = sum [ 0 ] [ i ] + curr [ i + 1 ] ; j ++ ; } } prsnt ++ ; for ( i = 0 ; sum [ 1 ] [ i ] != - 1 ; i ++ ) { sum [ 0 ] [ i ] = sum [ 1 ] [ i ] ; sum [ 1 ] [ i ] = - 1 ; } } int max = sum [ 0 ] [ 0 ] ; ; for ( i = 0 ; sum [ 0 ] [ i ] > - 1 ; i ++ ) { if ( sum [ 0 ] [ i ] > max ) max = sum [ 0 ] [ i ] ; } printf ( "%hd\n" , max ) ; } return 0 ; }