int gcd ( int a , int b ) { if ( b == 0 ) return a ; else return gcd ( b , a % b ) ; } int main ( ) { int t , a , b , j , m , n ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; j = gcd ( a , b ) ; printf ( "%d %d\n" , j , a * b / j ) ; } return 0 ; }