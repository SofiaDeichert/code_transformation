int main ( ) { int a , b , num , den , rem , lcm , gcd ; printf ( "enter the two numbers:" ) ; scanf ( "%d%d" , & a , & b ) ; if ( a > b ) { num = a ; den = b ; } else { num = b ; den = a ; } rem = num % den ; while ( rem != 0 ) { num = den ; den = rem ; rem = num % den ; } gcd = den ; lcm = ( a * b ) / gcd ; printf ( "gcd of the numbers %d and %d" , a , b , gcd ) ; printf ( "lcm of the numbers %d and %d" , a , b , lcm ) ; return 0 ; }