main ( ) { int i , j , t , n , p [ 99 ] [ 99 ] ; s ( t ) ; while ( t -- ) { s ( n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) s ( p [ i ] [ j ] ) ; for ( i = n - 1 ; i >= 0 ; i -- ) for ( j = 0 ; j <= i ; j ++ ) p [ i ] [ j ] += p [ i + 1 ] [ j ] > p [ i + 1 ] [ j + 1 ] ? p [ i + 1 ] [ j ] : p [ i + 1 ] [ j + 1 ] ; printf ( "%d\n" , p [ 0 ] [ 0 ] ) ; } }