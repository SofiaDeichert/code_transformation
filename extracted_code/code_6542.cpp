int main ( ) { int sum [ 10 ] [ 10 ] , i = 0 , j = 0 , size = 0 , max = 0 , t = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & size ) ; for ( i = 0 ; i < size ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & sum [ i ] [ j ] ) ; } for ( i = 0 ; i < size ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { if ( i == 0 && j == 0 ) sum [ i ] [ j ] = sum [ i ] [ j ] ; else if ( j == 0 ) sum [ i ] [ j ] = sum [ i ] [ j ] + sum [ i - 1 ] [ j ] ; else if ( i == j ) sum [ i ] [ j ] = sum [ i ] [ j ] + sum [ i - 1 ] [ j - 1 ] ; else { if ( sum [ i - 1 ] [ j - 1 ] > sum [ i - 1 ] [ j ] ) sum [ i ] [ j ] = sum [ i ] [ j ] + sum [ i - 1 ] [ j - 1 ] ; else sum [ i ] [ j ] = sum [ i ] [ j ] + sum [ i - 1 ] [ j ] ; } } } for ( i = size - 1 , j = 0 ; j <= i ; j ++ ) { if ( max < sum [ i ] [ j ] ) max = sum [ i ] [ j ] ; } printf ( "%d\n" , max ) ; } return 0 ; }