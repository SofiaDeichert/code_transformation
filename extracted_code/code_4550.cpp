int main ( ) { int i , t ; int long n , a [ n ] , min ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "ld" , & a [ i ] ) ; min = a [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) { if ( a [ i ] < min ) min = a [ i ] ; } printf ( "%ld\n" , ( min * ( n - 1 ) ) ) ; min = 0 ; } return 0 ; }