int gcd ( int a , int b ) ; int main ( ) { int t , r , i , a , b , c ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d%d" , & a , & b ) ; c = a * b ; printf ( "%d\t" , gcd ( a , b ) ) ; printf ( "%d\n" , c / gcd ( a , b ) ) ; } } int gcd ( int a , int b ) { if ( b == 0 ) return a ; return gcd ( b , a % b ) ; }