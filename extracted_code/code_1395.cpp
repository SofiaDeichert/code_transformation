int main ( ) { int t ; scanf ( " %d" , & t ) ; while ( t -- ) { int n , min , i , * arr ; long long int ans ; scanf ( " %d" , & n ) ; arr = ( int * ) malloc ( n * sizeof ( int ) ) ; scanf ( " %d" , & arr [ 0 ] ) ; min = arr [ 0 ] ; for ( i = 1 ; i < n ; i ++ ) { scanf ( " %d" , & arr [ i ] ) ; if ( min > arr [ i ] ) { min = arr [ i ] ; } } ans = min * ( n - 1 ) ; printf ( "%lld\n" , ans ) ; free ( arr ) ; } return 0 ; }