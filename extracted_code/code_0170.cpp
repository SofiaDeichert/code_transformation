int main ( ) { int t , a , b , s , x , y , l , g ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d %d" , & x , & y ) ; a = x ; b = y ; while ( b != 0 ) { s = b ; b = a % b ; a = s ; } g = a ; l = ( x * y ) / g ; printf ( "%d %d \n" , g , l ) ; } return 0 ; }