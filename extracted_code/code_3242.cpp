long long int gcd ( long long int , long long int ) ; int main ( ) { long long int a , b , result , lcm , t ; scanf ( "%lld" , & t ) ; while ( t -- ) { scanf ( "%lld %lld" , & a , & b ) ; result = gcd ( a , b ) ; lcm = ( a * b ) / result ; printf ( "%lld %lld\n" , result , lcm ) ; } } long long int gcd ( long long int a , long long int b ) { while ( a != b ) { if ( a > b ) { return gcd ( a - b , b ) ; } else { return gcd ( a , b - a ) ; } } return a ; }