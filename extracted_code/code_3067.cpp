int main ( ) { int test_cases , rows , i , j , k , no [ 5050 ] , sum1 = 0 , row_no , sum = 0 , a = 0 , ps [ 99 ] , l ; short int ns ; scanf ( "%d" , & test_cases ) ; for ( k = 1 ; k <= test_cases ; k ++ ) { ns = - 1 ; scanf ( "%d" , & rows ) ; for ( i = 1 ; i <= rows * ( rows + 1 ) / 2 ; i ++ ) { ns ++ ; scanf ( "%d" , & no [ ns ] ) ; } a = 0 ; for ( i = rows - 1 ; i >= 2 ; i -- ) { row_no = i * ( i - 1 ) / 2 ; a = 0 ; for ( j = row_no ; j < row_no + i ; j ++ ) { if ( no [ row_no + i + a ] >= no [ row_no + i + 1 + a ] ) sum1 = no [ row_no + a ] + no [ row_no + i + a ] ; else sum1 = no [ row_no + a ] + no [ row_no + i + 1 + a ] ; ps [ a ] = sum1 ; a ++ ; } a = 0 ; for ( l = row_no ; l < row_no + i ; l ++ ) { no [ l ] = ps [ a ] ; a ++ ; } } if ( rows != 0 ) { if ( no [ 1 ] >= no [ 2 ] ) sum = no [ 0 ] + no [ 1 ] ; else sum = no [ 0 ] + no [ 2 ] ; printf ( "%d\n" , sum ) ; } else printf ( "0\n" ) ; } return 0 ; }