int gcd ( int m , int n ) { int r ; while ( n > 0 ) { r = m % n ; m = n ; n = r ; } return ( m ) ; } int main ( ) { int x , y , j , t , * ans ; scanf ( "%d" , & t ) ; for ( j = 0 ; j < t ; j ++ ) { scanf ( "%d%d" , & x , & y ) ; * ( ans + j * 2 ) = gcd ( x , y ) ; * ( ans + j * 2 + 1 ) = x * y / ( * ( ans + j * 2 ) ) ; } for ( j = 0 ; j < t ; j ++ ) { printf ( "%d  %d\n" , * ( ans + j * 2 ) , * ( ans + j * 2 + 1 ) ) ; } return 0 ; }