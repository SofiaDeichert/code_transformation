int gcd ( int , int ) ; int main ( ) { int t , a , b ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; if ( a * b != 0 ) { int c = gcd ( a , b ) ; int LCM = ( a * b ) / c ; printf ( "%d %d\n" , c , LCM ) ; } } } int gcd ( int a , int b ) { if ( b == 0 ) return a ; gcd ( b , a % b ) ; }