int GCD ( long int x , long int y ) { if ( x == 0 || y == 0 ) return 0 ; if ( x == y ) return x ; if ( x > y ) return ( GCD ( x - y , y ) ) ; return ( GCD ( x , y - x ) ) ; } int LCM ( long int x , long int y ) { long int temp = GCD ( x , y ) ; long int z = ( x * y ) / temp ; return ( z ) ; } int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long int a , b ; scanf ( "%ld %ld" , & a , & b ) ; long int gcd = GCD ( a , b ) ; long int lcm = LCM ( a , b ) ; printf ( "%ld %ld\n" , gcd , lcm ) ; } return 0 ; }