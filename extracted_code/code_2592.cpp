int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n ; scanf ( "%d" , & n ) ; int a [ n ] ; for ( int i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } int min = 32767 ; for ( int j = 0 ; j < n ; j ++ ) { if ( a [ j ] < min ) min = a [ j ] ; } printf ( "%d\n" , ( min * ( n - 1 ) ) ) ; } return 0 ; }