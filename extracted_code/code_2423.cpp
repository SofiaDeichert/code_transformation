int main ( void ) { int t , c , a , b ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d%d" , & a , & b , & c ) ; if ( a == b && a == c && b == c ) { printf ( "0" ) ; } if ( a == b && c > a ) printf ( "%d" , a ) ; if ( b == c && a > b ) printf ( "%d" , b ) ; if ( a == c && b > a ) printf ( "%d" , a ) ; if ( a == b && c < a ) printf ( "%d" , c ) ; if ( b == c && a < b ) printf ( "%d" , a ) ; if ( a == c && b < a ) printf ( "%d" , b ) ; if ( a > b && a < c || a > c && a < b ) printf ( "%d\n" , a ) ; if ( b > a && b < c || b < a && b > c ) printf ( "%d\n" , b ) ; if ( c > a && c < b || c < a && c > b ) printf ( "%d" , & c ) ; printf ( "\n" ) ; } return 0 ; }