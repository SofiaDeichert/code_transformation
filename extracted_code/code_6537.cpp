main ( ) { int t , n , a [ 50000 ] ; scanf ( "%d\n" , & t ) ; while ( t -- > 0 ) { int i , min = 100000 ; scanf ( "%d\n" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; if ( min > a [ i ] ) min = a [ i ] ; } printf ( "%d\n" , min * ( n - 1 ) ) ; } }