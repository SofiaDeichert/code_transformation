int main ( int argc , char * argv [ ] ) { int t ; scanf ( "%d" , & t ) ; int i ; for ( i = 0 ; i < t ; i ++ ) { int n , min = 100001 ; scanf ( "%d" , & n ) ; int j , arr [ n ] ; for ( j = 0 ; j < n ; j ++ ) { scanf ( "%d" , & arr [ j ] ) ; if ( min > arr [ j ] ) min = arr [ j ] ; } printf ( "%d \n" , ( n - 1 ) * min ) ; } return 0 ; }