int main ( ) { int t , a , b , hcf = 1 , lcm = 1 , n ; scanf ( "%d" , & t ) ; while ( t -- ) { hcf = 1 ; lcm = 1 ; scanf ( "%d %d" , & a , & b ) ; n = ( a > b ) ? a : b ; for ( int i = ( n / 2 ) ; i > 1 ; i -- ) { if ( a % i == 0 && b % i == 0 ) { hcf *= i ; a /= i ; b /= i ; } } for ( int i = ( n / 2 ) ; i > 1 ; i -- ) { if ( a % i == 0 ) { lcm *= i ; a /= i ; } if ( b % i == 0 ) { lcm *= i ; b /= i ; } } lcm = lcm * hcf * a * b ; printf ( "%d %d\n" , hcf , lcm ) ; } }