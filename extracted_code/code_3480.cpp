int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , i , a , min = INT_MAX ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a ) ; if ( a < min ) min = a ; } printf ( "%d\n" , min * ( n - 1 ) ) ; } return 0 ; }