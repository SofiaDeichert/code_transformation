void fun ( long * , long * , long * ) ; int main ( ) { int t , i = 0 ; long n , a [ 50000 ] , j = 0 , k , cost = 0 , g = 0 ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%ld" , & n ) ; for ( j = 0 ; j < n ; j ++ ) scanf ( "%ld" , & a [ j ] ) ; for ( j = 0 , k = 1 ; j < n && k < n ; ) { if ( a [ j ] > a [ k ] ) { fun ( & a , & n , & j ) ; g = a [ k ] ; } else { fun ( & a , & n , & k ) ; g = a [ j ] ; } cost = cost + g ; } printf ( "%ld" , cost ) ; printf ( "\n" ) ; cost = 0 ; } return 0 ; } void fun ( long * p , long * q , long * r ) { long i = 0 ; for ( i = * r ; i < * q - 1 ; i ++ ) * ( p + i ) = * ( p + i + 1 ) ; * q = * q - 1 ; }