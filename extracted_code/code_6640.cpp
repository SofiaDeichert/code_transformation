int main ( ) { int i , a , b , t , m , gcd , lcm ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; if ( a < b ) m = a ; else m = b ; for ( i = 1 ; i <= m ; i ++ ) { if ( a % i == 0 && b % i == 0 ) gcd = i ; } lcm = ( a * b / gcd ) ; printf ( "%d %d\n" , gcd , lcm ) ; } return 0 ; }