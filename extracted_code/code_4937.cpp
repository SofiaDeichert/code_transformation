main ( ) { long int i , n , min , min_sum ; int t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld" , & n ) ; long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%ld" , & a [ i ] ) ; min = 1000001 ; for ( i = 0 ; i < n ; i ++ ) if ( min > a [ i ] ) min = a [ i ] ; min_sum = min * ( n - 1 ) ; printf ( "%ld\n" , min_sum ) ; } }