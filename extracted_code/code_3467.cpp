int main ( ) { long int i , t , n1 , n2 , x , y , lcm ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d%d" , & n1 , & n2 ) ; x = n1 ; y = n2 ; while ( x != y ) { if ( x > y ) x = x - y ; else y = y - x ; } lcm = ( n1 * n2 ) / x ; printf ( "%d\t%d\n" , x , lcm ) ; } }