int main ( ) { int t , count = 1 , i ; unsigned long int a , b , gcd , lcm , min , max , p ; scanf ( "%d" , & t ) ; while ( count <= t ) { scanf ( "%lu%lu" , & a , & b ) ; if ( a < b ) { min = a ; max = b ; } else { min = b ; max = a ; } while ( min != 0 ) { p = min ; min = max % min ; max = p ; } gcd = max ; lcm = ( a * b ) / gcd ; printf ( "%lu %lu" , gcd , lcm ) ; count ++ ; } return 0 ; }