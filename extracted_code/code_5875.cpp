int main ( ) { int i , j , T , k , lines ; int a [ 100 ] [ 100 ] , maxsum [ 100 ] [ 100 ] , x ; scanf ( "%d" , & T ) ; for ( i = 0 ; i < T ; i ++ ) { scanf ( "%d" , & lines ) ; for ( j = 0 ; j < lines ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) scanf ( "%d" , & a [ j ] [ k ] ) ; } for ( j = lines - 1 ; j >= 0 ; j -- ) { for ( k = 0 ; k <= j ; k ++ ) { if ( j == lines - 1 ) { maxsum [ j ] [ k ] = a [ j ] [ k ] ; } else { if ( maxsum [ j + 1 ] [ k ] > maxsum [ j + 1 ] [ k + 1 ] ) x = maxsum [ j + 1 ] [ k ] ; else x = maxsum [ j + 1 ] [ k + 1 ] ; maxsum [ j ] [ k ] = a [ j ] [ k ] + x ; } } } printf ( "%d\n" , maxsum [ 0 ] [ 0 ] ) ; } }