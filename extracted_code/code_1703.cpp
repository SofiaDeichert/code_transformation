int main ( ) { int t , max , n , ar [ 1000 ] [ 1000 ] , b [ 1000 ] [ 1000 ] , i , j ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & ar [ i ] [ j ] ) ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) { if ( i == 0 && j == 0 ) b [ 0 ] [ 0 ] = ar [ 0 ] [ 0 ] ; else { if ( j == 0 ) b [ i ] [ j ] = b [ i - 1 ] [ j ] + ar [ i ] [ j ] ; else if ( j == i ) b [ i ] [ j ] = b [ i - 1 ] [ j - 1 ] + ar [ i ] [ j ] ; else { if ( b [ i - 1 ] [ j ] > b [ i - 1 ] [ j - 1 ] ) b [ i ] [ j ] = b [ i - 1 ] [ j ] + ar [ i ] [ j ] ; else b [ i ] [ j ] = b [ i - 1 ] [ j - 1 ] + ar [ i ] [ j ] ; } } } i = n - 1 ; max = b [ i ] [ 0 ] ; for ( j = 1 ; j < n ; j ++ ) if ( max < b [ i ] [ j ] ) max = b [ i ] [ j ] ; printf ( "%d\n" , max ) ; } return 0 ; }