int main ( void ) { long long int n , A [ 100001 ] , i ; int t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & A [ i ] ) ; } long long int k = 0 ; for ( i = 0 ; i < n ; i ++ ) { if ( A [ i ] <= A [ k ] ) k = i ; } printf ( "%d\n" , ( n - 1 ) * A [ k ] ) ; } return 0 ; }