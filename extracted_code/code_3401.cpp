int main ( ) { int t , i , a , b , gcd , lcm , d ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; int n = a , m = b ; for ( i = 1 ; i <= a && i <= b ; i ++ ) { if ( a % i == 0 && b % i == 0 ) { d = i ; } lcm = ( n * m ) / gcd ; } gcd = d ; printf ( "%d %d\n" , gcd , lcm ) ; } return 0 ; }