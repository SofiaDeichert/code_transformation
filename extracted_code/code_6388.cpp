int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n ; scanf ( "%d" , & n ) ; int min = INT_MAX ; for ( int i = 0 ; i < n ; i ++ ) { int a ; scanf ( "%d" , & a ) ; if ( min > a ) min = a ; } printf ( "%d\n" , ( min * ( n - 1 ) ) ) ; } return 0 ; }