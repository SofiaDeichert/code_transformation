int main ( void ) { int cases , i , j , lines , sum , val , count ; scanf ( "%d" , & cases ) ; while ( cases -- ) { sum = 0 ; count = 0 ; scanf ( "%d" , & lines ) ; while ( count != lines ) { for ( j = 0 ; j < count + 1 ; j ++ ) { scanf ( "%d" , & val ) ; sum += val ; } count ++ ; } printf ( "%d\n" , sum / 2 ) ; } return 0 ; }