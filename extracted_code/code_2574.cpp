int tri ( int num [ ] , int i ) ; int main ( ) { int n , r , num [ size ] , i , j , max = 0 ; scanf ( "%d" , & n ) ; while ( n -- ) { max = 0 ; scanf ( "%d" , & r ) ; for ( i = 0 ; i < r ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & num [ j ] ) ; } if ( i == 0 ) continue ; else max = max + tri ( num , i ) ; } printf ( "%d" , max ) ; } return 0 ; } int tri ( int num [ size ] , int i ) { int k , max ; max = num [ 0 ] ; for ( k = 0 ; k <= i ; k ++ ) { if ( max <= num [ k ] ) max = num [ k ] ; } return max ; }