int main ( ) { long int z , i , n , a , b , max , min , hcf , lcm ; scanf ( "%ld" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%ld %ld" , & a , & b ) ; if ( a > b ) { max = a ; min = b ; } else { max = b ; min = a ; } z = max % min ; if ( z == 0 ) { hcf = min ; } else { while ( z != 0 ) { max = min ; min = z ; z = max % min ; } hcf = min ; } lcm = ( a * b ) / hcf ; printf ( "%ld %ld" , hcf , lcm ) ; } return 0 ; }