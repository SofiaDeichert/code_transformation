int hcf ( int a , int b ) { int i = 1 , p = 1 ; if ( a >= b ) { for ( ; i <= b ; i ++ ) { if ( a % i == 0 && b % i == 0 ) p *= i ; } return p ; } else { for ( ; i <= a ; i ++ ) { if ( a % i == 0 && b % i == 0 ) p *= i ; } return p ; } } int lcm ( int a , int b ) { int l = 1 , i = 2 ; while ( a != 1 || b != 1 ) { while ( a % i == 0 && b % i == 0 ) { a /= i ; b /= i ; l *= i ; } while ( a % i == 0 ) { a /= i ; l *= i ; } while ( b % i == 0 ) { b /= i ; l *= i ; } i ++ ; } return l ; } int main ( ) { int t , a , b ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "\n%d%d" , & a , & b ) ; int l = lcm ( a , b ) ; int h = hcf ( a , b ) ; printf ( "%d\t%d\n" , h , l ) ; } return 0 ; }