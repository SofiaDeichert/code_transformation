int main ( ) { int t , a , b , min , i , hcf , lcm ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; if ( a < b ) min = a ; else min = b ; for ( i = min ; i >= 1 ; i -- ) { if ( a % i == 0 && b % i == 0 ) { hcf = i ; break ; } } lcm = ( a / hcf ) * b ; printf ( "%d %d\n" , hcf , lcm ) ; } return 0 ; }