int main ( ) { int a , b , r , lcm ; int x , y ; int t , i ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d%d" , & a , & b ) ; x = a ; y = b ; while ( b != 0 ) { r = a % b ; a = b ; b = r ; } lcm = x * y ; printf ( "%d\t%d" , a , lcm ) ; } return 0 ; }