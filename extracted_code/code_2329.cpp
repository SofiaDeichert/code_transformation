int main ( ) { long int n1 , n2 , x , y , lcm , t , i , gcd ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d" , & n1 , & n2 ) ; x = n1 ; y = n2 ; while ( n1 != n2 ) { if ( n2 > n1 ) n2 = n2 - n1 ; else n1 = n1 - n2 ; } gcd = n1 ; lcm = ( x * y ) / gcd ; printf ( "%d\t%d\n" , gcd , lcm ) ; } }