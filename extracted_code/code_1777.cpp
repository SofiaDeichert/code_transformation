int main ( void ) { int big , no ; int k = 0 ; long long int a , b ; scanf ( "%d" , & no ) ; while ( k < no ) { scanf ( "%d %d" , & a , & b ) ; int gcd , i = 1 ; if ( a > b ) big = a ; else big = b ; while ( i <= big ) { if ( ( a % i == 0 ) && ( b % i == 0 ) ) { gcd = i ; } i ++ ; } printf ( "%d" , gcd ) ; int j = 2 , lcm = 1 ; while ( j <= big ) { if ( ( a % j == 0 ) && ( b % j == 0 ) ) { lcm = lcm * j ; a = a / j , b = b / j ; j ++ ; } else { lcm = lcm * a * b ; break ; } } printf ( " %d" , lcm ) ; k ++ ; } return 0 ; }