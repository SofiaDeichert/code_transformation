int main ( ) { int i , j , t , a , min1 , p ; double y ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d %d" , & a , & min1 ) ; for ( j = 1 ; j < a ; j ++ ) { scanf ( "%d" , & p ) ; if ( min1 > p ) { min1 = p ; } } y = min1 * ( a - 1 ) ; printf ( "%lf\n" , y ) ; } return 0 ; }