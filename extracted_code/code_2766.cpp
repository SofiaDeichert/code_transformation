int main ( ) { int i , a , b , t ; int gcd = 0 , lcm = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; for ( i = 1 ; i <= a , i <= b ; ++ i ) { if ( a % i == 0 && b % i == 0 ) { gcd = i ; } } lcm = ( a * b ) / gcd ; printf ( "%d %d\n" , gcd , lcm ) ; } }