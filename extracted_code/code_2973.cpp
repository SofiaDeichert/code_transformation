int main ( ) { int t , row , i , j ; int s [ 100 ] [ 100 ] , a [ 100 ] [ 100 ] ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & row ) ; for ( i = 0 ; i < row ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ i ] [ j ] ) ; } } s [ 0 ] [ 0 ] = a [ 0 ] [ 0 ] ; int max = a [ 0 ] [ 0 ] ; for ( i = 1 ; i < row ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { if ( j == 0 ) { s [ i ] [ j ] = s [ i - 1 ] [ j ] + a [ i ] [ j ] ; } else if ( j == i ) { s [ i ] [ j ] = s [ i - 1 ] [ j - 1 ] + a [ i ] [ j ] ; } else { if ( s [ i - 1 ] [ j ] > s [ i - 1 ] [ j - 1 ] ) { s [ i ] [ j ] = a [ i ] [ j ] + s [ i - 1 ] [ j ] ; } else { s [ i ] [ j ] = a [ i ] [ j ] + s [ i - 1 ] [ j - 1 ] ; } } if ( max < s [ i ] [ j ] ) max = s [ i ] [ j ] ; } } printf ( "%d\n" , max ) ; } return 0 ; }