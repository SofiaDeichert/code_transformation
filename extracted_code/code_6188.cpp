int main ( ) { int t , a , b , lcm , rem ; lcm = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; lcm = a * b ; if ( a < b ) { rem = a ; a = b ; b = rem ; } while ( b ) { rem = a % b ; a = b ; b = rem ; } printf ( "%d %d\n" , a , ( lcm / a ) ) ; } return 0 ; }