int matrix [ 100 ] [ 100 ] ; int sum [ 100 ] [ 100 ] ; int main ( ) { int t , rows ; int i , j , ans ; scanf ( "%d" , & t ) ; while ( t != 0 ) { scanf ( "%d" , & rows ) ; if ( rows < 100 && rows >= 0 ) { for ( i = 0 ; i < rows ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & matrix [ i ] [ j ] ) ; for ( i = 0 ; i < rows ; i ++ ) { for ( j = 0 ; ( j <= i && ( matrix [ i ] [ j ] >= 0 && matrix [ i ] [ j ] < 100 ) ) ; j ++ ) { if ( i == 0 && j == 0 ) sum [ i ] [ j ] = matrix [ i ] [ j ] ; else if ( j == 0 ) sum [ i ] [ j ] = matrix [ i ] [ j ] + sum [ i - 1 ] [ j ] ; else sum [ i ] [ j ] = matrix [ i ] [ j ] + ( sum [ i - 1 ] [ j ] > sum [ i - 1 ] [ j - 1 ] ? sum [ i - 1 ] [ j ] : sum [ i - 1 ] [ j - 1 ] ) ; } } ans = 0 ; for ( i = 0 ; i < rows ; i ++ ) ans = ( sum [ rows - 1 ] [ i ] > ans ? sum [ rows - 1 ] [ i ] : ans ) ; printf ( "%d" , ans ) ; } t -- ; } }