long long a [ 500001 ] ; int main ( void ) { long long t , n , i , min ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%lld" , & a [ i ] ) ; min = a [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) { if ( a [ i ] < min ) min = a [ i ] ; } for ( i = 1 ; i < n - 1 ; i ++ ) min *= min ; printf ( "%lld\n" , min ) ; } return 0 ; }