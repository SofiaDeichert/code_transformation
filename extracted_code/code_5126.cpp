int n ; int matrix [ 100 ] [ 100 ] ; int cache [ 100 ] [ 100 ] ; void fillzero ( ) { int i , j ; for ( i = 0 ; i < 100 ; i ++ ) for ( j = 0 ; j < 100 ; j ++ ) cache [ i ] [ j ] = - 1 ; } long int max ( long int a , long int b ) { return a > b ? a : b ; } long int trav ( int i , int j ) { if ( i == n - 1 ) return matrix [ i ] [ j ] ; if ( cache [ i ] [ j ] != - 1 ) return cache [ i ] [ j ] ; cache [ i ] [ j ] = max ( trav ( i + 1 , j ) , trav ( i + 1 , j + 1 ) ) + matrix [ i ] [ j ] ; return cache [ i ] [ j ] ; } void start ( ) { int i , j ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & matrix [ i ] [ j ] ) ; printf ( "%ld\n" , trav ( 0 , 0 ) ) ; } int main ( void ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { fillzero ( ) ; scanf ( "%d" , & n ) ; start ( ) ; } return 0 ; }