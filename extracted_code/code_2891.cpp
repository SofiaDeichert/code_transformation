int gcd ( int m , int n ) ; int fastInput ( ) { long int val = 0 ; char c = getchar_unlocked ( ) ; while ( c < '0' || c > '9' ) c = getchar_unlocked ( ) ; while ( c >= '0' && c <= '9' ) { val = ( val << 1 ) + ( val << 3 ) + ( c - '0' ) ; c = getchar_unlocked ( ) ; } return val ; } int gcd ( int m , int n ) { if ( n == 0 ) return m ; else return gcd ( n , m % n ) ; } int main ( ) { int t , a , b , h , l ; t = fastInput ( ) ; while ( t -- ) { a = fastInput ( ) ; b = fastInput ( ) ; h = gcd ( a , b ) ; l = ( a * b ) / h ; printf ( "%d %d\n" , h , l ) ; } return 0 ; }