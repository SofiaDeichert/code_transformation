int num_lines ; int max ( int a , int b ) { return a >= b ? a : b ; } int find_sum ( int arr [ ] [ num_lines ] , int num_lines ) { int trav1 ; int trav2 ; for ( trav1 = 1 ; trav1 < num_lines ; trav1 ++ ) { arr [ trav1 ] [ 0 ] += arr [ trav1 - 1 ] [ 0 ] ; arr [ trav1 ] [ trav1 ] += arr [ trav1 - 1 ] [ trav1 - 1 ] ; } for ( trav1 = 1 ; trav1 < num_lines ; trav1 ++ ) { for ( trav2 = 1 ; trav2 < trav1 ; trav2 ++ ) { arr [ trav1 ] [ trav2 ] += max ( arr [ trav1 - 1 ] [ trav2 ] , arr [ trav1 - 1 ] [ trav2 - 1 ] ) ; } } int max = 0 ; for ( trav1 = 0 ; trav1 < num_lines ; trav1 ++ ) { if ( arr [ num_lines - 1 ] [ trav1 ] > max ) max = arr [ num_lines - 1 ] [ trav1 ] ; } return max ; } int main ( ) { int num_test ; scanf ( "%d" , & num_test ) ; int trav ; int line ; int data ; for ( trav = 0 ; trav < num_test ; trav ++ ) { scanf ( "%d" , & num_lines ) ; int tot = ( num_lines * ( num_lines - 1 ) ) ; int trav1 ; int tt ; int res [ num_lines ] [ num_lines ] ; for ( line = 0 ; line < num_lines ; line ++ ) { for ( trav1 = 0 ; trav1 <= line ; trav1 ++ ) { scanf ( "%d" , & tt ) ; res [ line ] [ trav1 ] = tt ; } } int result = find_sum ( res , num_lines ) ; printf ( "%d \n" , result ) ; } return 0 ; }