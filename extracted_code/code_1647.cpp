int gcd ( int m , int n ) { if ( n == 0 ) return m ; if ( n > m ) return gcd ( m , n ) ; return gcd ( n , m % n ) ; } int main ( ) { int m , n , N ; scanf ( "%d" , & N ) ; while ( N -- ) { scanf ( "%d %d" , & m , & n ) ; printf ( "%d" , gcd ( m , n ) ) ; } return 0 ; }