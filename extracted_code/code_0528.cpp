int main ( ) { int i , j , n , max , sum , t , A [ 100 ] ; scanf ( "%d" , & t ) ; for ( ; t > 0 ; t -- , sum = 0 ) { scanf ( "%d" , & n ) ; scanf ( "%d" , & A [ 0 ] ) ; for ( i = 1 ; i < n ; i ++ , max = 0 ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & A [ j ] ) ; if ( A [ j ] > max ) max = A [ j ] ; } sum += max ; } printf ( "%d\n" , sum ) ; } return 0 ; }