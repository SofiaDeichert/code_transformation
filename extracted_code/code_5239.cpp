int main ( void ) { int t , a , b , prod , gcd , lcm ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; prod = a * b ; while ( a != b ) { if ( a > b ) a = a - b ; gcd = a ; if ( b > a ) b = b - a ; gcd = b ; } lcm = prod / gcd ; printf ( "%d %d\n" , gcd , lcm ) ; } return 0 ; }