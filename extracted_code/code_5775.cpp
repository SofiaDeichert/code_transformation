int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b , gcd , lcm ; scanf ( "%d %d" , & a , & b ) ; if ( a > b ) { int temp = a ; a = b ; b = temp ; } for ( int i = a ; i > 0 ; i -- ) { if ( a % i == 0 && b % i == 0 ) { gcd = i ; break ; } } lcm = ( a * b ) / gcd ; printf ( "%d\n" , gcd ) ; printf ( "%d\n" , lcm ) ; } }