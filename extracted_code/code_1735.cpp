long long gcd ( long long a , long long b ) { if ( a == 0 ) { return b ; } return ( gcd ( b % a , a ) ) ; } long long lcm ( long long a , long long b ) { return ( a * b ) / gcd ( a , b ) ; } int main ( ) { int t , i ; long long l = 0 , u = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%lld%lld" , & l , & u ) ; printf ( "%lld %lld\n" , gcd ( l , u ) , lcm ( l , u ) ) ; } return 0 ; }