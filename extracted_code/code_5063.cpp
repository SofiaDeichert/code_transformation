int main ( ) { unsigned int t , m , e , n , i ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; m = MAX_AI ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & e ) ; if ( m > e ) m = e ; } printf ( "%d\n" , m * ( n - 1 ) ) ; } return 0 ; }