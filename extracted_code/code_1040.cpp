int main ( ) { int m , n , p , q , r , s , t ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d" , & m , & n ) ; p = m ; q = n ; r = m % n ; while ( r != 0 ) { r = m % n ; m = n ; n = r ; } s = ( p * q ) / m ; printf ( "%d %d\n" , m , s ) ; } return 0 ; }