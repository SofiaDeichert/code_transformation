int gcd ( int a , int b ) { if ( a == 0 ) return b ; if ( b == 0 ) return a ; else return gcd ( b , a % b ) ; } int main ( ) { int t ; scanf ( "%d" , & t ) ; for ( int i = 0 ; i < t ; i ++ ) { int a , b ; scanf ( "%d%d" , & a , & b ) ; int p = gcd ( a , b ) ; printf ( "%d " , p ) ; printf ( "%d\n" , ( a * b ) / p ) ; } return 0 ; }