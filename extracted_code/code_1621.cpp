int main ( void ) { int t ; int i , n , x , min ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; min = MAX ; for ( i = 0 ; i < n ; ++ i ) { scanf ( "%d" , & x ) ; if ( x < min ) min = x ; } printf ( "%d\n" , min * ( n - 1 ) ) ; } return 0 ; }