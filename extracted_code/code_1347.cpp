int gcd ( int a , int b ) { if ( b ) return gcd ( b , a % b ) ; return a ; } int main ( void ) { int t , n , i , j ; long long int a ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & i , & j ) ; if ( i < j ) { n = j ; j = i ; i = n ; } n = gcd ( i , j ) ; a = i ; a = a * j ; printf ( "%d %lld\n" , n , a / n ) ; } return 0 ; }