static int sum [ 99 ] [ 99 ] , num [ 99 ] [ 99 ] , check , row , max ; int main ( void ) { int t , i , j , ans ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & row ) ; for ( i = 0 ; i < row ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & num [ i ] [ j ] ) ; } } max = 0 ; sum [ 0 ] [ 0 ] = num [ 0 ] [ 0 ] ; for ( i = 1 ; i < row ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { if ( j == 0 ) { sum [ i ] [ j ] = sum [ i - 1 ] [ j ] + num [ i ] [ j ] ; } else if ( j == i ) { sum [ i ] [ j ] = sum [ i - 1 ] [ j - 1 ] + num [ i ] [ j ] ; } else { if ( sum [ i - 1 ] [ j - 1 ] > sum [ i - 1 ] [ j ] ) { sum [ i ] [ j ] = sum [ i - 1 ] [ j - 1 ] + num [ i ] [ j ] ; } else { sum [ i ] [ j ] = sum [ i - 1 ] [ j ] + num [ i ] [ j ] ; } } } } for ( j = 0 ; j < row ; j ++ ) { if ( max < sum [ row - 1 ] [ j ] ) { max = sum [ row - 1 ] [ j ] ; } } printf ( "%d\n" , max ) ; } return 0 ; }