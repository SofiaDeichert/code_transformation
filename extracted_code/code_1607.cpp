void binary ( int * num , int count ) { int carry = 0 ; int sum , sum_temp ; count -= 1 ; sum = * num + 1 + carry ; if ( sum == 1 ) { * num = 1 ; } if ( sum == 2 ) { while ( sum >= 2 ) { * num = 0 ; carry = 1 ; count -= 1 ; num -- ; sum = * num + carry ; sum_temp = sum ; } * num = sum ; } } int binsum ( int * n , int count ) { int sum = 0 , i ; count -- ; for ( i = 0 ; i <= count ; i ++ ) { sum = sum + * n ; } return sum ; } int main ( void ) { int test ; unsigned int n ; int triangle [ 100 ] [ 100 ] ; int i , j , k , bin_count ; int sum [ 1000 ] , temp ; int bin [ 100 ] ; int row , col ; for ( i = 0 ; i < 100 ; i ++ ) bin [ i ] = 0 ; scanf ( "%d" , & test ) ; if ( test > 1000 ) exit ( 0 ) ; for ( i = 0 ; i < test ; i ++ ) { bin [ 100 ] = 0 ; scanf ( "%d" , & n ) ; for ( j = 0 ; j < n ; j ++ ) { for ( k = 0 ; k <= j ; k ++ ) { scanf ( "%d" , & triangle [ j ] [ k ] ) ; } } while ( binsum ( & bin [ 0 ] , n - 1 ) != n - 1 ) { row = 0 ; col = 0 ; temp = triangle [ row ] [ col ] ; for ( k = 1 ; k <= n - 1 ; k ++ ) { if ( bin [ k - 1 ] == 0 ) { row ++ ; } else { row ++ ; col ++ ; } temp = temp + triangle [ row ] [ col ] ; } if ( temp > sum [ i ] ) sum [ i ] = temp ; binary ( & bin [ n - 2 ] , n - 1 ) ; } } for ( i = 0 ; i < test ; i ++ ) { printf ( "%d\n" , sum [ i ] ) ; } return 0 ; }