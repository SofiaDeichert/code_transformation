int main ( ) { long int a [ 50000 ] , n , mr , m1 , sum [ 50000 ] = { } , t , b ; scanf ( "%ld" , & t ) ; for ( b = 0 ; b < t ; b ++ ) { scanf ( "%ld" , & n ) ; if ( n >= 2 && n <= 50000 ) { for ( mr = 0 ; mr <= n - 1 ; mr ++ ) { scanf ( "%ld" , & a [ mr ] ) ; } while ( n != 1 ) { if ( a [ 0 ] > a [ 1 ] ) { sum [ b ] += a [ 1 ] ; for ( m1 = 0 ; m1 < n - 1 ; m1 ++ ) { a [ m1 ] = a [ m1 + 1 ] ; } n -- ; } else if ( a [ 0 ] < a [ 1 ] ) { sum [ b ] += a [ 0 ] ; for ( m1 = 1 ; m1 < n - 1 ; m1 ++ ) { a [ m1 ] = a [ m1 + 1 ] ; } n -- ; } } printf ( "\n%ld" , sum ) ; } } return 0 ; }