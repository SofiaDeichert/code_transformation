int main ( ) { int k , t , a , count ; scanf ( "%d" , & t ) ; while ( t -- ) { count = 0 ; scanf ( "%d" , & k ) ; while ( k -- ) { scanf ( "%d" , & a ) ; count += a ; } printf ( "%d\n" , count ) ; } return 0 ; }