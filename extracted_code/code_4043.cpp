int main ( ) { int a , b , t , c , d ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; if ( a > b ) { c = a ; d = b ; } else { c = b ; d = a ; } while ( c % a != 0 || c % b != 0 ) c ++ ; while ( a % d != 0 || b % d != 0 ) d -- ; printf ( "%d\n%d\n" , c , d ) ; } }