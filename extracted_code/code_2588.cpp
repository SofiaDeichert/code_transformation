main ( ) { int test , row , i , j ; int num [ 100 ] [ 100 ] = { { 0 } } ; scanf ( "%d" , & test ) ; while ( test -- ) { scanf ( "%d" , & row ) ; for ( i = 0 ; i < row ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & num [ i ] [ j ] ) ; for ( i = row - 2 ; i >= 0 ; i -- ) for ( j = 0 ; j <= i ; j ++ ) { if ( num [ i + 1 ] [ j ] < num [ i + 1 ] [ j + 1 ] ) num [ i ] [ j ] += num [ i + 1 ] [ j + 1 ] ; else num [ i ] [ j ] += num [ i + 1 ] [ j + 1 ] ; } printf ( "%d" , num [ 0 ] [ 0 ] ) ; } }