int main ( ) { unsigned i , n , small ; int t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%u" , & n ) ; int a [ 49999 ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; small = a [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) { if ( a [ i ] < small ) small = a [ i ] ; } printf ( "%u\n" , ( ( n - 1 ) * small ) ) ; } return 0 ; }