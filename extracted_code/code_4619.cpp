int main ( ) { int t , i ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , min = 0 ; scanf ( "%d" , & n ) ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; if ( i == 0 ) min = a [ i ] ; if ( a [ i ] < min ) min = a [ i ] ; } printf ( "%d\n" , min * ( n - 1 ) ) ; } return 0 ; }