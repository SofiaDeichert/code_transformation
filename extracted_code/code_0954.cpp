int main ( ) { int t , s = 0 ; long int n ; scanf ( "%d" , & t ) ; while ( t -- > 0 ) { scanf ( "%ld" , & n ) ; int a [ n + 1 ] ; for ( int i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; a [ n ] = 0 ; for ( int i = 0 ; i < n ; i ++ ) { if ( a [ i ] < a [ i + 1 ] ) { a [ i + 1 ] = 0 ; s += a [ i ] ; } else { a [ i ] = 0 ; s += a [ i + 1 ] ; } } printf ( "%d\n" , s ) ; s = 0 ; } return 0 ; }