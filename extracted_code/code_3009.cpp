int main ( ) { int test ; scanf ( "%d" , & test ) ; while ( test -- ) { long long int a , b ; scanf ( "%lld%lld" , & a , & b ) ; if ( a < b ) { long long int t = a ; a = b ; b = t ; } long long int hcf ; for ( int i = b ; i >= 1 ; i -- ) { if ( b % i == 0 && a % i == 0 ) { hcf = i ; break ; } } long long int lcm = ( a * b ) / hcf ; printf ( "%ld %lld\n" , hcf , lcm ) ; } return 0 ; }