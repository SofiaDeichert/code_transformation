long long int gcd ( long long int a , long long int b ) { if ( a == 0 ) return b ; if ( b == 0 ) return a ; if ( a == b ) return a ; if ( a > b ) return ( gcd ( a - b , b ) ) ; return ( gcd ( a , b - a ) ) ; } long long int lcm ( long long int a , long long int b ) { return ( ( a * b ) / gcd ( a , b ) ) ; } int main ( ) { int t ; long long int g , l ; long long int A , B ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%lld %lld" , & A , & B ) ; g = gcd ( A , B ) ; l = lcm ( A , B ) ; printf ( "%lld %lld\n" , g , l ) ; } return 0 ; }