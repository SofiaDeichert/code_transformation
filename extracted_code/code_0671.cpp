int hcf ( int , int ) ; int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b , gcd , lcm ; scanf ( "%d%d" , & a , & b ) ; gcd = hcf ( a , b ) ; if ( gcd != 0 ) lcm = ( a * b ) / gcd ; else lcm = 0 ; printf ( "\n%d %d" , gcd , lcm ) ; } return 0 ; } int hcf ( int a , int b ) { int i , gcd ; if ( a == 0 || b == 0 ) return 0 ; else { for ( i = 1 ; i <= a && i <= b ; i ++ ) { if ( a == b ) return a ; else if ( ( ( a % i ) == 0 ) && ( ( b % i ) == 0 ) ) gcd = i ; } } return gcd ; }