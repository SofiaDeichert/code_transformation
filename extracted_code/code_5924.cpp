int main ( void ) { int t ; long long int n ; long long int i , min , j ; scanf ( "%d" , & t ) ; printf ( "\n" ) ; while ( t -- ) { min = 1 ; scanf ( "%lld" , & n ) ; printf ( "\n" ) ; for ( i = 1 ; i < n ; i ++ ) { scanf ( "%lld" , & j ) ; printf ( "%lld " , j ) ; if ( i ) { if ( min < j ) min = j ; } else min = j ; } printf ( "\n%lld\n" , ( min * ( n - 1 ) ) ) ; } }