int main ( void ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n ; scanf ( "%d" , & n ) ; int a [ n ] , i , min = 100000 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; if ( a [ i ] < min ) min = a [ i ] ; } min = min * ( n - 1 ) ; printf ( "%d\n" , min ) ; } return 0 ; }