int gcd ( int , int ) ; int lcm ( int , int ) ; int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b ; scanf ( "%d %d" , & a , & b ) ; printf ( "%d %d\n" , gcd ( a , b ) , lcm ( a , b ) ) ; } return 0 ; } int gcd ( int a , int b ) { int i ; while ( b ) { i = a ; a = b % a ; b = i ; if ( a == 0 ) return i ; } } int lcm ( int a , int b ) { int i ; int p = ( a > b ) ? a : b ; i = p ; int q = ( a < b ) ? a : b ; while ( p > 0 ) { if ( p % q == 0 ) return p ; p = p + i ; } }