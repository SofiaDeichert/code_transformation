int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long int n , i , min = 100000000000 ; scanf ( "%ld" , & n ) ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%ld" , & a [ i ] ) ; for ( i = 0 ; i < n ; i ++ ) if ( a [ i ] < min ) min = a [ i ] ; printf ( "%ld\n" , ( min * ( n - 1 ) ) ) ; } }