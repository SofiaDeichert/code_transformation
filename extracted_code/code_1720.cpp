int main ( ) { int a , b , t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; int x = gcd ( a , b ) ; printf ( "%d %d\n" , x , a * b / x ) ; } return 0 ; } int gcd ( int m , int n ) { if ( m % n == 0 ) return n ; else gcd ( n , m % n ) ; }