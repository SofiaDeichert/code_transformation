int main ( ) { int t , n , cost , array [ 100000 ] , count , x , i ; scanf ( "%d" , & t ) ; while ( t -- ) { count = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & array [ i ] ) ; } for ( i = 0 ; i < n ; i ++ ) { if ( array [ i ] > array [ i + 1 ] ) count = count + array [ i + 1 ] ; else { if ( i == ( n - 2 ) ) { count = count + array [ i ] ; break ; } else { count = count + array [ i ] ; x = array [ i ] ; array [ i ] = array [ i + 1 ] ; array [ i + 1 ] = x ; } } } printf ( "\n%d\n" , count ) ; } }