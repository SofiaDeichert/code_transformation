int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int arr [ 100000 ] ; int n ; int i , j ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%lld" , & arr [ i ] ) ; } long long int cnt = 0 , flag = 0 ; for ( i = 1 ; i <= n ; i ++ ) { if ( arr [ i ] >= arr [ i - 1 ] ) cnt ++ ; } cnt = cnt + n ; printf ( "%lld" , cnt ) ; } return 0 ; }