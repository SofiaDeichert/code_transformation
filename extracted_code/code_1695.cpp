int main ( ) { int T ; scanf ( "%d" , & T ) ; while ( T -- ) { long long int A , B , GCD , LCM ; scanf ( "%lld %lld" , & A , & B ) ; int i ; for ( i = ( A > B ? B : A ) ; i > 0 ; i -- ) { if ( A % i == 0 && B % i == 0 ) { GCD = i ; break ; } } LCM = ( A * B ) / GCD ; printf ( "%lld %lld\n" , GCD , LCM ) ; } return 0 ; }