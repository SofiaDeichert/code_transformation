int main ( ) { int a , b , d , e , GCD , lcm , r ; scanf ( "%d %d" , & a , & b ) ; d = a ; e = b ; while ( b > 0 ) { r = a % b ; a = b ; b = r ; } GCD = a ; lcm = ( d * e ) / GCD ; printf ( "%d %d\n" , GCD , lcm ) ; return 0 ; }