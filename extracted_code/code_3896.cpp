long long int gcd ( long long int a , long long int b ) { if ( b == 0 ) return a ; return gcd ( b , a % b ) ; } long long int lcm ( long long int a , long long int b ) { return ( a * b ) / gcd ( a , b ) ; } int main ( ) { int t = 0 ; long long int a = 0 , b = 0 ; long long int x = 0 , y = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%lld %lld" , & a , & b ) ; x = gcd ( a , b ) ; y = lcm ( a , b ) ; printf ( "%lld %lld\n" , x , y ) ; } return 0 ; }