int main ( ) { int m , r , tc , a , b , hcf ; scanf ( "%d" , & tc ) ; while ( tc -- ) { scanf ( "%d%d" , & a , & b ) ; m = a * b ; while ( b > 0 ) { r = a % b ; a = b ; b = r ; } hcf = m / a ; printf ( "%d %d\n" , a , hcf ) ; } return 0 ; }