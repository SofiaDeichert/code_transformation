int gcd ( int a , int b ) { if ( a % b == 0 ) return b ; return gcd ( b , a % b ) ; } int main ( ) { int T , A , B , GCD , LCM ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d%d" , & A , & B ) ; GCD = gcd ( A , B ) ; printf ( "%d " , GCD ) ; LCM = ( A * B ) / GCD ; printf ( "%d\n" , LCM ) ; } return 0 ; }