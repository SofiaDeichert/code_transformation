int main ( ) { int t ; long n , i ; long a [ NUM ] , min ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld" , & n ) ; min = 100001 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%ld" , & a [ i ] ) ; if ( a [ i ] < min ) { min = a [ i ] ; } } printf ( "%ld\n" , min * ( n - 1 ) ) ; } return 0 ; }