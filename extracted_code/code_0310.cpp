long long gcd ( long long a , long long b ) { long long c ; if ( a == 0 ) return b ; else return ( gcd ( b % a , a ) ) ; return b ; } int main ( ) { long long x , y , a , b ; int T ; scanf ( "%d" , & T ) ; while ( T -- ) { scanf ( "%lld %lld" , & a , & b ) ; x = gcd ( a , b ) ; y = a * b / x ; printf ( "%lld %lld\n" , x , y ) ; } return 0 ; }