int min ( int , int ) ; int main ( ) { int i , a [ 100000 ] , t , p , j , sum = 0 ; long n , m ; scanf ( "%d" , & t ) ; while ( t -- ) { sum = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & a [ i ] ) ; for ( i = 0 ; i < n - 1 ; i ++ ) { p = min ( a [ i ] , a [ i + 1 ] ) ; a [ i + 1 ] = p ; sum += p ; } printf ( "%d\n" , sum ) ; } } int min ( int a , int b ) { if ( a > b ) return b ; else return a ; }