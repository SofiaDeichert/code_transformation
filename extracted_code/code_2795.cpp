int main ( ) { int a , b , c , l , s , r ; scanf ( "%d" , & a ) ; for ( int i = 1 ; i <= a ; i ++ ) { scanf ( "%d %d" , & b , & c ) ; if ( b > c ) { l = b ; s = c ; } else { l = c ; s = b ; } while ( l != 0 ) { r = l % s ; s = l ; l = r ; } printf ( "%d %d" , s , ( b * c ) / s ) ; printf ( "\n" ) ; } }