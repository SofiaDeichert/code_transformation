main ( ) { int n , i , m , j ; scanf ( "%d" , & n ) ; while ( n -- ) { scanf ( "%d" , & m ) ; int z [ m ] [ m ] ; for ( i = 0 ; i < m ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & z [ i ] [ j ] ) ; } for ( i = m - 2 ; i >= 0 ; i -- ) { for ( j = 0 ; j <= i ; j ++ ) { if ( z [ i + 1 ] [ j ] > z [ i + 1 ] [ j + 1 ] ) z [ i ] [ j ] += z [ i + 1 ] [ j ] ; else z [ i ] [ j ] += z [ i + 1 ] [ j + 1 ] ; } } printf ( "%d\n" , z [ 0 ] [ 0 ] ) ; } }