int main ( ) { int t , i , n , a , min ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; min = 80000 ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & a ) ; if ( a < min ) min = a ; } min = min * ( n - 1 ) ; printf ( "%d\n" , min ) ; } return 0 ; }