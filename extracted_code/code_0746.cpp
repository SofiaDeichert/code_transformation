int gcd ( int a , int b ) { if ( a == 0 || b == 0 ) return 0 ; if ( a == b ) return a ; if ( a > b ) return gcd ( a - b , b ) ; return gcd ( a , b - a ) ; } int main ( void ) { int a , b , n , i ; unsigned long long int lcm = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d%d" , & a , & b ) ; gcd ( a , b ) ; lcm = ( a * b ) / gcd ( a , b ) ; printf ( "\n%d\t%d" , gcd ( a , b ) , lcm ) ; } return 0 ; }