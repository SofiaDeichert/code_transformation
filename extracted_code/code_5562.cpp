int gcd ( int a , int b ) { if ( a == b ) return b ; if ( a == 0 || b == 0 ) return 0 ; if ( a > b ) return ( gcd ( a - b , b ) ) ; return ( gcd ( a , b - a ) ) ; } int lcm ( int a , int b ) { int l ; for ( l = ( a > b ? a : b ) ; l < a * b ; l = l + ( a > b ? a : b ) ) if ( l % a == 0 && l % b == 0 ) break ; return ( l ) ; } main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int a , b ; scanf ( "%d%d" , & a , & b ) ; printf ( "%d " , gcd ( a , b ) ) ; printf ( "%d\n" , lcm ( a , b ) ) ; } }