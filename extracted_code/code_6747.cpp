int main ( ) { int t , n , i , j , temp , sum , a [ 10 ] ; scanf ( "%d" , & t ) ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d\n" , & a [ i ] ) ; } for ( i = 0 ; i < n ; i ++ ) { for ( j = i + 1 ; j < n ; j ++ ) { if ( a [ i ] > a [ j ] ) { temp = a [ i ] ; a [ i ] = a [ j ] ; a [ j ] = temp ; } } } for ( i = 0 ; i < n ; i ++ ) { printf ( "%d\n" , a [ i ] ) ; } sum = a [ 0 ] * ( n - 1 ) ; printf ( "%d\n" , sum ) ; }