int main ( ) { int tcase ; scanf ( "%d" , & tcase ) ; while ( tcase -- ) { int n , i , cost = 0 ; scanf ( "%d" , & n ) ; long int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%ld" , & a [ i ] ) ; } for ( i = 1 ; i < n ; i ++ ) { if ( a [ i - 1 ] > a [ i ] ) cost += a [ i ] ; else cost += a [ i - 1 ] ; } printf ( "%d\n" , cost ) ; } return 0 ; }