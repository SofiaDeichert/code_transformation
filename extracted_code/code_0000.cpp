int lcm ( int a , int b ) { int max = ( a > b ) ? a : b ; while ( 1 ) { if ( max % a == 0 && max % b == 0 ) { return max ; } max ++ ; } } int gcd ( int a , int b ) { int t ; int max = ( a > b ) ? a : b ; while ( 1 ) { if ( max % a == 0 && max % b == 0 ) { t = ( a * b ) / max ; return t ; } max ++ ; } } int main ( ) { int x , i ; scanf ( "%d" , & x ) ; int g [ x ] , h [ x ] , t = 0 ; while ( x -- ) { int a , b ; scanf ( "%d %d" , & a , & b ) ; g [ t ] = lcm ( a , b ) ; h [ t ] = gcd ( a , b ) ; t ++ ; } for ( i = 0 ; i < t ; i ++ ) printf ( "%d %d\n" , h [ i ] , g [ i ] ) ; return 0 ; }