int main ( ) { int t ; scanf ( "%d" , & t ) ; int gcd , lcm , a , b , i ; while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; for ( i = 1 ; i <= a && i <= b ; i ++ ) if ( a % i == 0 && b % i == 0 ) gcd = i ; for ( i = 1 ; ; i ++ ) if ( a * i % b == 0 ) { lcm = a * i ; break ; } printf ( "%d %d\n" , gcd , lcm ) ; } }