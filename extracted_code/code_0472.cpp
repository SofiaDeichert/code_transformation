int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b , x , y , t , gcd , lcm ; scanf ( "%d %d" , & x , & y ) ; a = x ; b = y ; while ( b != 0 ) { t = b ; b = a % b ; a = t ; } gcd = a ; lcm = ( x * y ) / gcd ; printf ( "%d %d" , gcd , lcm ) ; } return 0 ; }