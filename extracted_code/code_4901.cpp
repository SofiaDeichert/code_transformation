int gcd ( int , int ) ; int main ( ) { int a [ 1000 ] , b [ 1000 ] ; int t , i , m , n ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d %d" , & a [ i ] , & b [ i ] ) ; } for ( i = 0 ; i < t ; i ++ ) { m = gcd ( a [ i ] , b [ i ] ) ; n = ( a [ i ] * b [ i ] ) / m ; printf ( "%d %d\n" , m , n ) ; } return 0 ; } int gcd ( int a , int b ) { while ( a % b != 0 ) { int x = a % b ; a = b ; b = x ; } return b ; }