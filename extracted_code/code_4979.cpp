int T , i , n , j , k , max , sum , carry ; int check ( int b [ ] , int n ) { for ( i = 0 ; i < n - 1 ; i ++ ) if ( b [ i ] == 0 ) return 1 ; return 0 ; } int main ( ) { scanf ( "%d" , & T ) ; int a [ 100 ] [ 100 ] ; int b [ 100 ] ; for ( k = 0 ; k < T ; k ++ ) { max = - 1 ; sum = carry = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & a [ i ] [ j ] ) ; b [ i ] = 0 ; } b [ n - 2 ] = - 1 ; do { carry = b [ n - 2 ] + 1 ; b [ n - 2 ] = carry ; carry /= 10 ; for ( i = n - 3 ; i >= 0 ; i -- ) { carry += b [ i ] ; b [ i ] = carry ; carry /= 10 ; } sum = a [ 0 ] [ 0 ] ; j = 0 ; for ( i = 1 ; i < n ; i ++ ) sum += ( ( b [ i - 1 ] == 0 ) ? a [ i ] [ j ] : a [ i ] [ ++ j ] ) ; if ( max < sum ) max = sum ; } while ( check ( b , n ) ) ; printf ( "%d\n" , max ) ; system ( "pause" ) ; } }