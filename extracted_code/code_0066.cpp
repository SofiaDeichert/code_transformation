int main ( void ) { int t ; long long i , n , arr [ 100000 ] , min ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%lld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & arr [ i ] ) ; } min = arr [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) if ( min > arr [ i ] ) min = arr [ i ] ; printf ( "%lld\n" , ( n - 1 ) * min ) ; } }