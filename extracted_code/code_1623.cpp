int main ( ) { int t , a , b , r , a1 , b1 ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; a1 = a ; b1 = b ; while ( b1 != 0 ) { r = a1 % b1 ; a1 = b1 ; b1 = r ; } printf ( "%d " , a1 ) ; printf ( "%d" , ( a * b ) / a1 ) ; printf ( "\n" ) ; } }