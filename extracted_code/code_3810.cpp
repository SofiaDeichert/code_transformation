long long int gcd ( long long int a , long long int b ) { if ( a == 0 || b == 0 ) return 0 ; if ( a == b ) return a ; if ( a > b ) return gcd ( a - b , b ) ; return gcd ( a , b - a ) ; } int main ( void ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int m , n ; scanf ( "%lld%lld" , & m , & n ) ; printf ( "%lld " , gcd ( m , n ) ) ; printf ( "%lld\n" , ( m * n ) / gcd ( m , n ) ) ; } return 0 ; }