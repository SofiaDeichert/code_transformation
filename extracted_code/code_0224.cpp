int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long int n1 , n2 , n3 , tmp , l , x1 , x2 ; scanf ( "%ld %ld" , & n1 , & n2 ) ; x1 = n1 ; x2 = n2 ; if ( n1 > n2 ) { tmp = n1 ; n1 = n2 ; n2 = tmp ; } while ( n2 % n1 != 0 ) { n3 = n1 ; n1 = n2 % n1 ; n2 = n3 ; } l = ( x1 * x2 ) / n1 ; printf ( "%ld %ld\n" , n1 , l ) ; } return 0 ; }