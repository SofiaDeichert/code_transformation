int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b , temp , l ; scanf ( "%d %d" , & a , & b ) ; int lcm = a * b ; if ( a < b ) { a = a + b ; b = a - b ; a = a - b ; } while ( a % b != 0 ) { temp = b ; b = a % b ; a = temp ; } temp = b ; lcm = lcm / temp ; printf ( "%d %d\n" , temp , ( int ) lcm ) ; } return 0 ; }