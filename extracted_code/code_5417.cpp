long long int gcd ( long long int a , long long int b ) { if ( a == 0 || b == 0 ) return 0 ; if ( a == b ) return a ; if ( a > b ) return gcd ( a - b , b ) ; return gcd ( a , b - a ) ; } long long int lcm ( long long int a , long long int b ) { return ( a * b ) / gcd ( a , b ) ; } int main ( ) { long long int t , a , b ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld%lld" , & a , & b ) ; printf ( "%lld %lld\n" , gcd ( a , b ) , lcm ( a , b ) ) ; } return 0 ; }