int main ( ) { int a , b , t , c ; int num , den , rem ; scanf ( "%d" , & t ) ; while ( t > 0 ) { scanf ( "%d %d" , & a , & b ) ; if ( a > b ) { num = a ; den = b ; } else { den = a ; num = b ; } rem = num % den ; while ( rem != 0 ) { num = den ; den = rem ; rem = num % den ; } printf ( "%d " , den ) ; c = ( a > b ) ? a : b ; while ( 1 ) { if ( c % a == 0 && c % b == 0 ) { printf ( "%d" , c ) ; break ; } c ++ ; } t -- ; } }