int main ( void ) { int n ; scanf ( "%d" , & n ) ; while ( n ) { int a [ n ] ; for ( int i = 1 ; i <= n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } for ( int i = 1 ; i <= n ; i ++ ) { if ( a [ a [ i ] ] != i ) { printf ( "not ambiguous\n" ) ; break ; } if ( i == n ) { printf ( "ambiguous\n" ) ; } } scanf ( "%d" , & n ) ; } return 0 ; }