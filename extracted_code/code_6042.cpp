int mul ( int * a , int n , int m ) { int t = 0 , x , i = 0 ; while ( t || ( i < m ) ) { x = a [ i ] * n + t ; a [ i ] = x ; t = x / 10 ; i ++ ; } return i ; } int main ( ) { int t , n , m , i ; scanf ( "%d" , & t ) ; while ( t -- ) { int a [ 200 ] = { 0 } ; scanf ( "%d" , & n ) ; a [ 0 ] = n ; m = 1 ; while ( -- n ) { m = mul ( a , n , m ) ; } for ( i = m - 1 ; i >= 0 ; i -- ) { printf ( "%d" , a [ i ] ) ; } printf ( "\n" ) ; } return 0 ; }