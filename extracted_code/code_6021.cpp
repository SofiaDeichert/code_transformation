int main ( void ) { int tcs , m , i , j ; scanf ( "%d" , & tcs ) ; int mat [ 100 ] [ 100 ] ; while ( tcs > 0 ) { scanf ( "%d" , & m ) ; for ( i = 0 ; i < m ; i ++ ) { for ( j = 0 ; j <= i + 1 ; j ++ ) if ( j != i ) mat [ i ] [ j ] = - 1 ; } for ( i = 0 ; i < m ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , mat [ i ] [ j ] ) ; } int largest = - 1 ; int temp1 , temp2 = 0 ; for ( i = 0 ; i < m - 1 ; i ++ ) { for ( j = 0 ; mat [ i ] [ j ] != - 1 ; j ++ ) { if ( j == 0 ) temp1 = mat [ i + 1 ] [ j ] ; else temp1 = temp2 ; mat [ i + 1 ] [ j ] = mat [ i ] [ j ] + temp1 ; if ( mat [ i + 1 ] [ j ] > largest ) largest = mat [ i + 1 ] [ j ] ; temp2 = mat [ i + 1 ] [ j + 1 ] ; mat [ i + 1 ] [ j + 1 ] = mat [ i ] [ j ] + temp2 ; if ( mat [ i + 1 ] [ j + 1 ] > largest ) largest = mat [ i + 1 ] [ j + 1 ] ; } } printf ( "%d" , largest ) ; tcs -- ; } return 0 ; }