int sums [ 100 ] [ 100 ] = { - 1 } ; int main ( ) { int n , i , j , k , limit , max ; int array [ 100 ] [ 100 ] = { - 1 } ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { memset ( sums , - 1 , 10000 ) ; scanf ( "%d" , & limit ) ; for ( j = 0 ; j < limit ; j ++ ) for ( k = 0 ; k <= j ; k ++ ) scanf ( "%d" , & array [ j ] [ k ] ) ; printf ( "%d\n" , sum ( array , limit , 0 , 0 ) ) ; } return 0 ; } int sum ( int array [ 100 ] [ 100 ] , int limit , int cur_row , int pos ) { if ( cur_row == limit ) return 0 ; int sum1 , sum2 ; if ( sums [ cur_row ] [ pos ] != - 1 ) return sums [ cur_row ] [ pos ] ; sum1 = array [ cur_row ] [ pos ] + sum ( array , limit , cur_row + 1 , pos ) ; sum2 = array [ cur_row ] [ pos ] + sum ( array , limit , cur_row + 1 , pos + 1 ) ; if ( sum1 > sum2 ) { sums [ cur_row ] [ pos ] = sum1 ; return sum1 ; } else { sums [ cur_row ] [ pos ] = sum2 ; return sum2 ; } }