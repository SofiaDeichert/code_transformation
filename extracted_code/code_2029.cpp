struct node { int wt ; int row ; } tri [ SZ ] ; int main ( void ) { int n ; int num_rows , num_elem , last_row_index ; int i , row , j ; int max_sum , sum , chosen , chosen1 , chosen2 ; int input ; scanf ( "%d" , & n ) ; while ( n > 0 ) { scanf ( "%d" , & num_rows ) ; num_elem = ( num_rows * ( num_rows + 1 ) ) / 2 ; last_row_index = ( ( num_rows - 1 ) * num_rows ) / 2 ; for ( i = 0 , row = 1 , j = row ; i < num_elem ; i ++ ) { scanf ( "%d" , & input ) ; tri [ i ] . wt = input ; tri [ i ] . row = row ; j -- ; if ( j < 1 ) { row ++ ; j = row ; } } row -= 1 ; max_sum = - 1 ; for ( i = num_elem - 1 ; i >= last_row_index ; i -- ) { sum = tri [ i ] . wt ; chosen = i ; for ( j = row ; j > 1 ; j -- ) { chosen1 = chosen - j + 1 ; chosen2 = chosen - j ; chosen = chosen1 ; if ( ( tri [ chosen1 ] . row != j - 1 ) || ( ( chosen2 > - 1 ) && ( tri [ chosen2 ] . row == j - 1 ) && ( tri [ chosen ] . wt < tri [ chosen2 ] . wt ) ) ) { chosen = chosen2 ; } sum += tri [ chosen ] . wt ; } if ( sum > max_sum ) { max_sum = sum ; } } printf ( "%d\n" , max_sum ) ; n -- ; } }