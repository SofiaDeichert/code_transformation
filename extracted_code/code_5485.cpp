int main ( ) { int t , a , b , temp , lcm , gcd , x , y ; scanf ( "%d" , & t ) ; while ( t > 0 ) { scanf ( "%d %d" , & x , & y ) ; a = x ; b = y ; while ( b != 0 ) { temp = b ; b = a % b ; a = temp ; } gcd = a ; lcm = ( x * y ) / gcd ; printf ( "%d %d\n" , gcd , lcm ) ; t -- ; } return ( 0 ) ; }