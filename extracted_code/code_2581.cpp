int gcd ( long int a , long int b ) ; int main ( void ) { int i = 0 ; int n ; scanf ( "%d" , & n ) ; while ( i < n ) { long int a , b ; scanf ( "%ld%ld" , & a , & b ) ; long int g = gcd ( MAX ( a , b ) , SMALL ( a , b ) ) ; printf ( "%ld " , g ) ; printf ( "%ld\n" , ( a * b ) / ( g ) ) ; i ++ ; } return 0 ; } int gcd ( long int a , long int b ) { if ( a % b == 0 ) { return b ; } while ( a > b ) { a = a - b ; } return gcd ( b , a ) ; }