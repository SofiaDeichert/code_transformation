int main ( ) { int testCase ; scanf ( "%d" , & testCase ) ; int span [ 100 ] [ 100 ] ; while ( testCase -- ) { int n ; scanf ( "%d" , & n ) ; int i ; int j ; for ( i = 0 ; i < n ; i ++ ) for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & span [ i ] [ j ] ) ; for ( i = n - 2 ; i >= 0 ; i -- ) for ( j = 0 ; j <= i ; j ++ ) { if ( span [ i + 1 ] [ j ] > span [ i + 1 ] [ j + 1 ] ) span [ i ] [ j ] = span [ i ] [ j ] + span [ i + 1 ] [ j ] ; else span [ i ] [ j ] = span [ i ] [ j ] + span [ i + 1 ] [ j + 1 ] ; } printf ( "%d\n" , span [ 0 ] [ 0 ] ) ; } return 0 ; }