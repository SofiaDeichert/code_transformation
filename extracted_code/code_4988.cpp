int GCD ( int a , int b ) { int t ; while ( b != 0 ) { t = b ; b = a % b ; a = t ; } return a ; } int main ( ) { int a , b , c , t , lcm ; scanf ( "%d" , & t ) ; while ( t > 0 ) { scanf ( "%d%d" , & a , & b ) ; c = GCD ( a , b ) ; lcm = a * b / c ; printf ( "%d %d\n" , c , lcm ) ; t -- ; } return 0 ; }