int gcdlcm ( long int , long int ) ; int main ( void ) { long n , k , l , a ; scanf ( "%ld" , & n ) ; while ( n -- ) { scanf ( "%ld %ld" , & k , & l ) ; a = gcdlcm ( k , l ) ; printf ( "%ld" , a ) ; printf ( "%ld" , ( k * l ) / a ) ; } return 0 ; } int gcdlcm ( long int x , long int y ) { if ( x == y ) return x ; if ( x % y == 0 ) return y ; if ( x % y == 0 ) return x ; if ( x > y ) return gcdlcm ( x % y , y ) ; else return gcdlcm ( x , y % x ) ; }