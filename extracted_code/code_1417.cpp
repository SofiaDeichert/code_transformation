int gcd ( int a , int b ) { while ( a != b ) { if ( a > b ) return gcd ( a - b , b ) ; else return gcd ( a , b - a ) ; } return a ; } int lcm ( int a , int b ) { return a * b / gcd ( a , b ) ; } int main ( ) { int t , a , b ; scanf ( "%d" , & t ) ; while ( t > 0 ) { scanf ( "%d%d" , & a , & b ) ; printf ( "%d %d\n" , gcd ( a , b ) , lcm ( a , b ) ) ; } return 0 ; }