int main ( ) { int t , a , b , num , den , rem , gcd , lcm ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & a ) ; scanf ( "%d" , & b ) ; if ( a > b ) { num = a ; den = b ; } else { num = b ; den = a ; } rem = num % den ; while ( rem != 0 ) { num = den ; den = rem ; rem = num % den ; } gcd = den ; lcm = a * b / gcd ; printf ( "%d %d \n" , gcd , lcm ) ; } return 0 ; }