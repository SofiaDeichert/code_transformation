int main ( int argc , char * argv [ ] ) { int t , i , j , n , max , temp ; scanf ( "%d" , & t ) ; while ( t -- ) { max = 0 ; scanf ( "%d" , & n ) ; int a [ n ] ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a [ i ] ) ; } i = n - 1 ; while ( i > 0 ) { if ( a [ i ] > a [ i - 1 ] ) { max = max + a [ i - 1 ] ; a [ i ] = - 1 ; i -- ; } else if ( a [ i ] < a [ i - 1 ] ) { max = max + a [ i ] ; temp = a [ i ] ; a [ i ] = a [ i - 1 ] ; a [ i - 1 ] = temp ; i -- ; } } printf ( "%d" , max ) ; } return 0 ; }