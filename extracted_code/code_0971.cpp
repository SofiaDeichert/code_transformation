int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n ; long long min = INT_MAX ; scanf ( "%d" , & n ) ; long long a ; for ( int i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & a ) ; if ( a < min ) min = a ; } printf ( "%lld\n" , min * ( n - 1 ) ) ; } }