int gcd ( int , int ) ; int main ( ) { int a , b , lcm , k , t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; k = gcd ( a , b ) ; lcm = ( a * b ) / k ; printf ( "%d %d" , k , lcm ) ; } } int gcd ( int a , int b ) { if ( b == 0 ) { return a ; } else { return gcd ( b , b % a ) ; } }