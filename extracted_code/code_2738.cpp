int main ( ) { int t ; long a , b , c ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld%ld" , & a , & b ) ; c = a * b ; while ( a != b ) ( a > b ) ? ( a = a - b ) : ( b = b - a ) ; printf ( "%ld %ld\n" , a , c / a ) ; } return 0 ; }