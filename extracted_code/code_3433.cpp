int main ( ) { int a , b , hcf , lcm , t , m , n ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & a , & b ) ; m = a ; n = b ; while ( m != n ) { if ( m > n ) m = m - n ; else n = n - m ; } hcf = m ; lcm = ( a * b ) / hcf ; printf ( "%d %d\n" , hcf , lcm ) ; } return 0 ; }