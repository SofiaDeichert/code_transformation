int m , a [ 101 ] [ 101 ] ; int max ( int j , int k ) { if ( j > k ) return ( j ) ; else return ( k ) ; } int f ( int n , int j ) { if ( n == ( m + 1 ) ) return ( 0 ) ; else if ( j == ( n + 1 ) ) return 0 ; else return ( a [ n ] [ j ] + max ( f ( n + 1 , j + 1 ) , f ( n + 1 , j ) ) ) ; } int main ( ) { int t , s = 0 , i , j ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & m ) ; for ( i = 1 ; i <= m ; i ++ ) { for ( j = 1 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; } s = f ( 1 , 1 ) ; printf ( "%d\n" , s ) ; } return 0 ; }