int gcd ( int a , int b ) { while ( a * b > 0 ) { if ( b > a ) b = b % a ; else a = a % b ; } return a + b ; } int main ( ) { int i , j ; scanf ( "%d" , & i ) ; j = i ; int grid [ i ] [ 4 ] ; for ( ; i > 0 ; i -- ) { scanf ( "%d %d" , & grid [ i ] [ 0 ] , & grid [ i ] [ 1 ] ) ; grid [ i ] [ 2 ] = gcd ( grid [ i ] [ 0 ] , grid [ i ] [ 1 ] ) ; grid [ i ] [ 3 ] = ( grid [ i ] [ 0 ] * grid [ i ] [ 1 ] ) / grid [ i ] [ 2 ] ; } for ( ; j > 0 ; j -- ) { printf ( "%d %d\n" , grid [ j ] [ 2 ] , grid [ j ] [ 3 ] ) ; } }