main ( ) { int a , b , z , gcd , temp , t , lcm ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d\n" , & a ) ; scanf ( "%d" , & b ) ; z = a * b ; while ( b != 0 ) { temp = b ; b = a % b ; a = temp ; } gcd = a ; lcm = z / gcd ; printf ( "%d %d\n" , gcd , lcm ) ; } return 0 ; }