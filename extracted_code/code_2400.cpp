void initialize ( int lines ) ; int findSum ( int matrix [ 100 ] [ 100 ] , int lines ) ; int max ( int a , int b ) ; int max ( int a , int b ) { if ( a > b ) return a ; return b ; } int findSum ( int matrix [ 100 ] [ 100 ] , int lines ) { int i = 0 ; while ( lines > 1 ) { for ( i = 0 ; i < lines - 2 ; i ++ ) { matrix [ lines - 2 ] [ i ] = matrix [ lines - 2 ] [ i ] + max ( matrix [ lines - 1 ] [ i ] , matrix [ lines - 1 ] [ i + 1 ] ) ; } lines -- ; } return matrix [ lines ] [ lines ] ; } void initialize ( int lines ) { int matrix [ 100 ] [ 100 ] ; int i = 0 ; int a = 0 ; int val = 0 ; for ( ; i < lines ; i ++ ) { for ( ; a < lines ; a ++ ) { if ( a > i ) matrix [ i ] [ a ] = 0 ; else { scanf ( "%d" , & matrix [ i ] [ a ] ) ; if ( matrix [ i ] [ a ] > 99 || matrix [ i ] [ a ] < 0 ) return ; } } a = 0 ; } val = findSum ( matrix , lines ) ; printf ( "%d" , val ) ; } int main ( ) { int cases = 0 ; int lines = 0 ; int i = 0 ; scanf ( "%d" , & cases ) ; if ( lines < 0 || lines > 100 ) { return - 1 ; } for ( ; i < cases ; i ++ ) { scanf ( "%d" , & lines ) ; initialize ( lines ) ; } return 0 ; }