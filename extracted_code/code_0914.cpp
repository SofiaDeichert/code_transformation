int main ( void ) { int t ; long a , b , c ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld %ld" , & a , & b ) ; c = a * b ; while ( a != b ) { if ( a > b ) a = a - b ; else b = b - a ; } printf ( "%ld %ld\n" , a , c / a ) ; } return 0 ; }