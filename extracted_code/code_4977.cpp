long gcd ( long a , long b ) { while ( a != 0 && b != 0 ) { if ( a > b ) a %= b ; else b %= a ; } return ( a > b ? a : b ) ; } int main ( ) { long t ; scanf ( "%ld" , & t ) ; while ( t -- ) { long n1 , n2 , c ; scanf ( "%ld %ld" , & n2 , & n1 ) ; c = gcd ( n1 , n2 ) ; printf ( "%ld %ld\n" , c , n1 * n2 / c ) ; } }