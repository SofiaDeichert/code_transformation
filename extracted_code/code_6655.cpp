int main ( ) { int t ; long int x , y , a , b , g , l , r ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%ld%ld" , & x , & y ) ; a = x ; b = y ; while ( b != 0 ) { r = a % b ; a = b ; b = r ; } g = a ; l = ( x * y ) / g ; printf ( "%ld%ld" , g , l ) ; printf ( "\n" ) ; } return 0 ; }