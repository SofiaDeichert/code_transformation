int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b , c , d ; scanf ( "%d %d" , & a , & b ) ; c = a ; d = b ; while ( d != 0 ) { c = c % d ; c = c ^ d ; d = d ^ c ; c = c ^ d ; } a = ( a * b ) / c ; printf ( "%d\t%d" , c , a ) ; } return 0 ; }