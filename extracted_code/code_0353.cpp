int main ( void ) { long int i , t , n , a [ 50050 ] ; scanf ( "%ld\n" , & t ) ; while ( t -- ) { scanf ( "%ld\n" , & n ) ; long int m , c = 0 ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%ld" , & a [ i ] ) ; for ( i = 1 ; i < n ; i ++ ) { if ( a [ i ] < a [ 0 ] ) { m = a [ i ] ; a [ i ] = a [ 0 ] ; a [ 0 ] = m ; } } c = a [ 0 ] * ( n - 1 ) ; printf ( "%ld\n" , c ) ; } return 0 ; }