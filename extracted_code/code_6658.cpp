main ( ) { int t ; long int n , i ; long long int min ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld" , & n ) ; long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%ld" , & a [ i ] ) ; } min = a [ 0 ] ; for ( i = 0 ; i < n ; i ++ ) { if ( a [ i ] < min ) min = a [ i ] ; } min = min * ( n - 1 ) ; printf ( "%lld\n" , min ) ; } }