int main ( ) { int t , a , b , x , y , hcf ; long long int lcm ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & a ) ; scanf ( "%d" , & b ) ; x = a ; y = b ; while ( a != b ) { if ( a > b ) a -= b ; else b -= a ; } hcf = a ; lcm = ( x * y ) / hcf ; printf ( "%d %lld\n" , hcf , lcm ) ; } }