int main ( ) { int n , i , j , m , p , hcf , lar , s , k ; long lcm ; scanf ( "%d\n" , & n ) ; if ( n <= 1000 ) { for ( i = 1 ; i <= n ; i ++ ) { hcf = 0 ; lcm = 0 ; scanf ( "%d %d\n" , & m , & p ) ; if ( ( m <= 1000000 && m >= 1 ) && ( p < 1000000 && p >= 1 ) ) { lar = m ; s = p ; if ( p > lar ) { lar = p ; s = m ; } for ( j = lar ; 1 ; j += lar ) { if ( j % m == 0 && j % p == 0 ) { lcm = j ; break ; } } for ( k = s ; k > 0 ; k -- ) { if ( m % k == 0 && p % k == 0 ) { hcf = k ; break ; } } printf ( "%d %ld\n" , hcf , lcm ) ; } } } return 0 ; }