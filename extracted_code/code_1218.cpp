int main ( ) { int t , n , max ; scanf ( "%d" , & t ) ; while ( t -- ) { int i , a [ n ] [ n ] , j ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; for ( j = i + 1 ; j < n ; j ++ ) a [ i ] [ j ] = 0 ; } max = a [ 0 ] [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) for ( j = 0 ; j < n ; j ++ ) { if ( j == 0 ) a [ i ] [ j ] = a [ i ] [ j ] + a [ i - 1 ] [ j ] ; else { if ( a [ i - 1 ] [ j - 1 ] > a [ i - 1 ] [ j ] ) a [ i ] [ j ] = a [ i ] [ j ] + a [ i - 1 ] [ j - 1 ] ; else a [ i ] [ j ] = a [ i ] [ j ] + a [ i - 1 ] [ j ] ; } if ( a [ i ] [ j ] > max ) max = a [ i ] [ j ] ; } printf ( "%d" , max ) ; } }