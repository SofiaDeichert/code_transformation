int main ( void ) { long t = 0 , n = 0 , a [ MAX ] , i = 0 ; long long min ; scanf ( "%ld" , & t ) ; while ( t -- ) { min = 0 ; scanf ( "%ld" , & n ) ; if ( n <= 1 ) { break ; } else { for ( i = 0 ; i < n ; i ++ ) scanf ( "%ld" , & a [ i ] ) ; min = a [ 0 ] ; for ( i = 1 ; i < n - 1 ; i ++ ) { if ( a [ i ] < min ) min = a [ i ] ; } } min *= ( n - 1 ) ; printf ( "%lld\n" , min ) ; } return 0 ; }