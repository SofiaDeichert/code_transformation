int main ( ) { int i , j , T , n , a , b , cost = 0 ; scanf ( "%d\n" , & T ) ; for ( i = 1 ; i <= T ; i ++ ) { scanf ( "%d" , & n ) ; scanf ( "%d" , & a ) ; cost = a ; for ( j = 2 ; j <= n ; j ++ ) { scanf ( "%d" , & b ) ; if ( a > b ) { a = a + b ; b = a - b ; a = a - b ; } cost += a ; } printf ( "%d\n" , cost ) ; } return 0 ; }