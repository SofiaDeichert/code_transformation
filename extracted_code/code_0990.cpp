int gcd ( int a , int b ) { while ( a != b ) { if ( a > b ) { return gcd ( a - b , b ) ; } else { return gcd ( a , b - a ) ; } } return a ; } int main ( ) { int T , M , N ; long long ans ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%d %d" , & M , & N ) ; ans = gcd ( M , N ) ; printf ( "%lld %lld\n" , ans , M * N / ans ) ; } return 0 ; }