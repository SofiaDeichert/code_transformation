long int euclid ( long int m , long int n ) { if ( m % n == 0 ) return n ; else return euclid ( n , m % n ) ; } int main ( ) { int i , j ; long int n ; long int gcd , lcm ; scanf ( " %ld" , & n ) ; long int arr [ n ] [ 3 ] ; for ( i = 1 ; i <= n ; i ++ ) { for ( j = 1 ; j <= 2 ; j ++ ) { scanf ( " %ld" , & arr [ i ] [ j ] ) ; } } printf ( "\n" ) ; for ( i = 1 ; i <= n ; i ++ ) { gcd = euclid ( arr [ i ] [ 1 ] , arr [ i ] [ 2 ] ) ; lcm = ( arr [ i ] [ 1 ] * arr [ i ] [ 2 ] ) / gcd ; printf ( "%ld" , gcd ) ; printf ( " %ld\n" , lcm ) ; } return 0 ; }