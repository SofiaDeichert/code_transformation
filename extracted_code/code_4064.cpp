int main ( ) { int i , j , arr [ 101 ] [ 101 ] , temp , result , cases , lines , value ; scanf ( "%d" , & cases ) ; while ( 1 ) { for ( i = 0 ; i < 101 ; i ++ ) for ( j = 0 ; j < 101 ; j ++ ) arr [ i ] [ j ] = 0 ; result = 0 ; scanf ( "%d" , & lines ) ; for ( i = 1 ; i <= lines ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) { scanf ( "%d" , & value ) ; arr [ i ] [ j ] = value + arr [ i - 1 ] [ j - 1 ] ; if ( result < arr [ i ] [ j ] ) result = arr [ i ] [ j ] ; temp = value + arr [ i - 1 ] [ j ] ; if ( temp > arr [ i ] [ j ] ) arr [ i ] [ j ] = temp ; if ( result < temp ) result = temp ; } } printf ( "%d\n" , result ) ; if ( -- cases == 0 ) break ; } return 0 ; }