int a [ 50000 ] ; int main ( int argc , char const * argv [ ] ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , i , min = INT_MAX ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; ++ i ) { scanf ( "%d" , & a [ i ] ) ; if ( a [ i ] < min ) min = a [ i ] ; } printf ( "%d\n" , min * ( n - 1 ) ) ; } return 0 ; }