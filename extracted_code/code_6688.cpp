int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , a , min = INT_MAX ; scanf ( "%ld" , & n ) ; for ( int i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a ) ; if ( min > a ) min = a ; } printf ( "%d\n" , min * ( n - 1 ) ) ; } }