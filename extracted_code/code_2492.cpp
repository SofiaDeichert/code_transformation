int main ( ) { int i , n , p , q , a , b ; scanf ( "%d" , & n ) ; for ( i = 1 ; i <= n ; i ++ ) { scanf ( "%d%d" , & p , & q ) ; a = p ; b = q ; while ( a != b ) { if ( a > b ) a = a - b ; else b = b - a ; } printf ( "%d %d\n" , a , ( p * q ) / a ) ; } return 0 ; }