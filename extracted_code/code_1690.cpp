main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int a , b , hcf = 1 ; long long int lcm ; scanf ( "%lld%lld" , & a , & b ) ; lcm = a * b ; while ( b ) { long long int k = b % a ; if ( k == 0 ) { hcf = a ; break ; } b = a ; a = k ; } printf ( "%lld %lld\n" , hcf , lcm / hcf ) ; } }