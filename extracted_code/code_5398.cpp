int main ( ) { int t , a , b , gcd ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; gcd = b ; while ( gcd != 1 ) { if ( a % gcd == 0 && b % gcd == 0 ) break ; gcd -- ; } printf ( "%d %d\n" , gcd , a * b / gcd ) ; } return 0 ; }