int main ( void ) { int t ; scanf ( "%d\n" , & t ) ; long long int n ; for ( int i = 0 ; i < t ; i ++ ) { scanf ( "%lld\n" , & n ) ; int a [ n ] ; for ( int i = 0 ; i < n ; i ++ ) { scanf ( "%lld\n" , & a [ i ] ) ; } long long int min = a [ 0 ] ; for ( int j = 0 ; j < n ; j ++ ) { if ( min > a [ j ] ) { min = a [ j ] ; } } printf ( "%lld\n" , min * ( n - 1 ) ) ; } return 0 ; }