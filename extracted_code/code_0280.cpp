int main ( void ) { int i , j , t ; long long int n , min ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%lld" , & n ) ; long long int arr [ n ] ; for ( j = 0 , min = 100000 ; j < n ; j ++ ) { scanf ( "%lld" , & arr [ j ] ) ; if ( min > arr [ j ] ) min = arr [ j ] ; } printf ( "%lld\n" , min * ( n - 1 ) ) ; } return 0 ; }