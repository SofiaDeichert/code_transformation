int main ( ) { int t , i ; long a , b , u , v , x , lcm , gcd ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%ld%ld" , & a , & b ) ; u = a ; v = b ; while ( 1 ) { x = a % b ; a = b ; b = x ; if ( x == 0 ) { gcd = a ; break ; } } lcm = ( u * v ) / gcd ; printf ( "%ld %ld\n" , gcd , lcm ) ; } return 0 ; }