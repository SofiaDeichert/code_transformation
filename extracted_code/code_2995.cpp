int GCD ( a , b ) { if ( b == 0 ) return a ; else return GCD ( b , a % b ) ; } int main ( ) { int t , a , b , i , j , gcd , lcm ; scanf ( "%d" , & t ) ; int * * mat = ( int * * ) calloc ( t , sizeof ( int * ) ) ; for ( i = 0 ; i < t ; i ++ ) { mat [ i ] = ( int * ) calloc ( 2 , sizeof ( int ) ) ; } for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d %d" , & a , & b ) ; gcd = GCD ( a , b ) ; lcm = ( a * b ) / gcd ; mat [ i ] [ 0 ] = gcd ; mat [ i ] [ 1 ] = lcm ; } for ( i = 0 ; i < t ; i ++ ) { for ( j = 0 ; j < 2 ; j ++ ) { printf ( "%d " , mat [ i ] [ j ] ) ; } printf ( "\n" ) ; } return 0 ; }