long long int get_gcd ( int , int ) ; long long int get_lcm ( int , int ) ; int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long long int a , b , gcd , lcm , max , min ; scanf ( "%ld%ld" , & a , & b ) ; if ( a < b ) { max = b ; min = a ; } else { max = a ; min = b ; } gcd = get_gcd ( max , min ) ; lcm = get_lcm ( max , min ) ; printf ( "%ld %ld\n" , gcd , lcm ) ; } return 0 ; } long long int get_gcd ( int x , int y ) { long long int div , d , q , r = 0 ; div = x ; d = y ; r = div % d ; if ( r == 0 ) return ( div / d ) ; else { while ( r != 0 ) { div = d ; d = r ; r = div % d ; } return d ; } } long long int get_lcm ( int x , int y ) { long long int i , num ; for ( i = 1 ; i <= y ; i ++ ) { num = i * x ; if ( num % y == 0 ) break ; } return num ; }