void main ( ) { int n , i , t , arr [ 50001 ] ; long long int min = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & arr [ i ] ) ; min = arr [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) if ( min > arr [ i ] ) min = arr [ i ] ; printf ( "%lld" , ( n - 1 ) * min ) ; } }