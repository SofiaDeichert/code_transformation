int sum [ 100 ] [ 100 ] , num ; int max_sum ( int arr [ ] [ 100 ] , int row , int col ) { int r1 , r2 ; if ( row == ( num - 1 ) ) sum [ row ] [ col ] = arr [ row ] [ col ] ; else if ( col != 0 ) { r1 = max_sum ( arr , row + 1 , col + 1 ) ; if ( r1 > sum [ row + 1 ] [ col ] ) sum [ row ] [ col ] = r1 + arr [ row ] [ col ] ; else sum [ row ] [ col ] = sum [ row + 1 ] [ col ] + arr [ row ] [ col ] ; } else { r1 = max_sum ( arr , row + 1 , col ) ; r2 = max_sum ( arr , row + 1 , col + 1 ) ; sum [ row ] [ col ] = r1 > r2 ? ( r1 + arr [ row ] [ col ] ) : ( r2 + arr [ row ] [ col ] ) ; } return sum [ row ] [ col ] ; } int main ( ) { int n , i , r , c , arr [ 100 ] [ 100 ] ; scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { scanf ( "%d" , & num ) ; for ( r = 0 ; r < num ; r ++ ) for ( c = 0 ; c <= r ; c ++ ) scanf ( "%d" , & arr [ r ] [ c ] ) ; printf ( "%d\n" , max_sum ( arr , 0 , 0 ) ) ; } }