long long int gcd ( int n , int m ) { if ( n == 0 ) return m ; else if ( m == 0 ) return n ; else return gcd ( m , n % m ) ; } long long int lcm ( int n , int m ) { return n * m / gcd ( n , m ) ; } int main ( ) { int t , n , m ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & n , & m ) ; printf ( "%lld %lld\n" , gcd ( n , m ) , lcm ( n , m ) ) ; } return 0 ; }