void func ( int a , int b ) ; void maxmin ( int a , int b , int c ) ; void merge ( int a , int b ) ; int s = 0 , c = 0 , row ; int b [ 5050 ] ; int a [ 5050 ] ; int main ( ) { int n , t , flag ; scanf ( "%d" , & n ) ; while ( n > 0 ) { scanf ( "%d" , & row ) ; t = ( row * ( row + 1 ) ) / 2 ; for ( flag = 1 ; flag <= t ; flag ++ ) scanf ( "%d" , & a [ flag ] ) ; func ( 1 , 1 ) ; int yu , x ; yu = 1 , x = c ; merge ( yu , x ) ; printf ( "%d" , b [ x ] ) ; n -- ; } return 0 ; } void func ( int i , int r ) { s += a [ i ] ; if ( a [ i + r ] != 0 ) { func ( ( i + r ) , ( r + 1 ) ) ; func ( ( i + r + 1 ) , ( r + 1 ) ) ; } if ( r == row ) { c ++ ; b [ c ] = s ; } s = s - a [ i ] ; } void maxmin ( int p , int q , int r ) { int temp = 0 ; if ( b [ p ] > b [ q + 1 ] ) { temp = b [ p ] ; b [ p ] = b [ q + 1 ] ; b [ q + 1 ] = temp ; } if ( b [ q ] > b [ r ] ) { temp = b [ q ] ; b [ q ] = b [ r ] ; b [ r ] = temp ; } } void merge ( int p , int r ) { int q ; if ( p < r ) { q = ( p + r ) / 2 ; merge ( p , q ) ; merge ( q + 1 , r ) ; maxmin ( p , q , r ) ; } }