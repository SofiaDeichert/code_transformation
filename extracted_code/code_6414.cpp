int max_sum ( int * triangle [ ] , int row ) { int temp , temp1 ; int i , j , prev_row ; int * curr_row_ptr ; int * prev_row_ptr ; for ( i = 1 , prev_row = 0 ; i < row ; i ++ , prev_row ++ ) { curr_row_ptr = triangle [ i ] ; prev_row_ptr = triangle [ prev_row ] ; * curr_row_ptr += * prev_row_ptr ; for ( j = 1 ; j <= i ; j ++ ) { temp = * ( prev_row_ptr + j ) ; temp1 = * ( prev_row_ptr + j - 1 ) ; if ( temp1 > temp ) temp = temp1 ; * ( curr_row_ptr + j ) += temp ; } } temp = * prev_row_ptr ; ; for ( j = 1 ; j <= i ; j ++ ) { if ( * ( prev_row_ptr + j ) > temp ) temp = * ( prev_row_ptr + j ) ; } return temp ; } int main ( ) { int test_cases ; int rows ; char str [ 300 ] ; char * temp ; int i , j , num ; int * triangle [ 100 ] = { NULL } ; int * row_ptr ; scanf ( "%d" , & test_cases ) ; while ( test_cases -- ) { scanf ( "%d" , & rows ) ; fflush ( stdin ) ; for ( i = 0 ; i < rows ; i ++ ) { gets ( str ) ; if ( triangle [ i ] == NULL ) triangle [ i ] = ( int * ) malloc ( sizeof ( int ) * ( i + 1 ) ) ; row_ptr = triangle [ i ] ; temp = strtok ( str , " " ) ; while ( temp ) { sscanf ( temp , "%d" , row_ptr ++ ) ; temp = strtok ( NULL , " " ) ; } } printf ( "%d\n" , max_sum ( triangle , rows ) ) ; } return 0 ; }