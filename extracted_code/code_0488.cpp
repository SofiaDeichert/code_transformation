int main ( ) { int test , n , arr [ 100 ] , i , j , max , ans [ 1000 ] , sum = 0 , temp , k ; scanf ( "%d" , & test ) ; for ( i = 0 ; i < test ; i ++ ) { sum = 0 ; scanf ( "%d" , & n ) ; for ( j = 0 ; j < n ; j ++ ) { k = 0 ; max = 0 ; do { scanf ( "%d" , & temp ) ; if ( max < temp ) max = temp ; arr [ j ] = max ; k ++ ; } while ( k <= j ) ; } for ( j = 1 ; j < n ; j ++ ) sum = sum + arr [ j ] ; ans [ i ] = sum ; } for ( i = 0 ; i < test ; i ++ ) printf ( "%d\n" , ans [ i ] ) ; return 0 ; }