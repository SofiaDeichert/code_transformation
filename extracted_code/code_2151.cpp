int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t != 0 ) { int n , i , count = 0 ; scanf ( "%d" , & n ) ; int arr [ 100001 ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , & arr [ i ] ) ; for ( i = 0 ; i < n - 1 ; i ++ ) { if ( arr [ i ] <= arr [ i + 1 ] ) count ++ ; } count = count + n ; printf ( "%d\n" , count ) ; t -- ; } }