long long int gcd ( long long int a , long long int b ) { if ( b == 0 ) return a ; else return gcd ( b , a % b ) ; } int main ( ) { int t ; long long int a , b ; long long ans1 , ans2 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%lld%lld" , & a , & b ) ; ans1 = gcd ( a , b ) ; ans2 = ( a * b ) / ans1 ; printf ( "%lld %lld\n" , ans1 , ans2 ) ; } }