int main ( ) { int t , i = 0 , j ; scanf ( "%d" , & t ) ; int a [ t ] , b [ t ] ; for ( ; i < t ; i ++ ) { scanf ( "%d %d" , & a [ i ] , & b [ i ] ) ; } for ( i = 0 ; i < t ; i ++ ) { for ( j = ( a [ i ] > b [ i ] ? b [ i ] : a [ i ] ) ; j >= 1 ; j -- ) { if ( a [ i ] % j == 0 && b [ i ] % j == 0 ) { printf ( "%d %ld\n" , j , a [ i ] * b [ i ] / j ) ; break ; } } } return 0 ; }