int main ( void ) { int t = 0 ; long long int a = 0 , b = 0 , temp = 0 ; long long int lcm = 0 , gcd = 0 , i = 0 , j = 0 ; scanf ( "%d" , & t ) ; while ( t -- ) { lcm = gcd = 0 ; temp = 0 ; scanf ( "%lld %lld" , & a , & b ) ; i = a ; j = b ; if ( b > a ) { temp = b ; b = a ; a = temp ; } temp = 0 ; while ( b != 0 && a != 0 ) { temp = b ; a %= b ; b = a ; a = temp ; } gcd = a == 0 ? b : a ; lcm = gcd * ( i / gcd ) * ( j / gcd ) ; printf ( "%lld %lld\n" , gcd , lcm ) ; } return 0 ; }