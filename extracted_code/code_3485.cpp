int gcd ( int a , int b ) { int g = a ; if ( b != 0 ) { g = gcd ( b , a % b ) ; } return ( g ) ; } int main ( int argc , char * * argv ) { int t ; int i ; int res ; int a ; int b ; int g ; int lcm ; res = scanf ( "%u\n" , & t ) ; assert ( res == 1 ) ; for ( i = 0 ; i < t ; i ++ ) { res = scanf ( "%u %u\n" , & a , & b ) ; assert ( res == 2 ) ; g = gcd ( a , b ) ; lcm = a * b / g ; printf ( "%u %u\n" , g , lcm ) ; } return 0 ; }