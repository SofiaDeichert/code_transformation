int main ( ) { int i , j , k , n ; scanf ( "%d" , & n ) ; while ( n -- ) { int s ; scanf ( "%d" , & s ) ; int arr [ s ] ; int arr1 [ s ] ; long long total = 0 ; for ( i = 0 ; i < s ; i ++ ) { scanf ( "%d" , & arr [ i ] ) ; if ( i > 0 ) { if ( arr [ i ] >= arr [ i - 1 ] ) { arr1 [ i - 1 ] = 1 ; } else { arr1 [ i - 1 ] = 0 ; } } } arr1 [ s - 1 ] = 0 ; for ( i = s - 2 ; i >= 0 ; i -- ) { if ( arr1 [ i ] == 1 && arr1 [ i + 1 ] > 0 ) { arr1 [ i ] = arr1 [ i ] + arr1 [ i + 1 ] ; } total = total + arr1 [ i ] ; } total = total + s ; printf ( "%lli\n" , total ) ; } }