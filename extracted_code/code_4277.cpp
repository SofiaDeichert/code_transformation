int main ( ) { int t , i ; long long int a , b , gcd , lcm , p , q , d , j , c ; scanf ( "%d" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { scanf ( "%d %d" , & a , & b ) ; p = a ; q = b ; if ( a - b > 0 ) { d = a ; a = b ; b = d ; } for ( j = 0 ; ; ) { c = b % a ; if ( c == 0 ) { gcd = a ; break ; } else { b = a ; a = c ; } } lcm = p * ( q / gcd ) ; printf ( "%d %d\n" , gcd , lcm ) ; } return 0 ; }