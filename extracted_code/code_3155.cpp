int main ( void ) { int t ; int i , temp , count , n , k ; long int num ; long long int sum = 0 ; scanf ( "%d" , & t ) ; for ( i = 1 ; i <= t ; i ++ ) { temp = 0 ; count = 0 ; sum = 0 ; scanf ( "%d" , & n ) ; for ( k = 0 ; k < n ; k ++ ) { scanf ( "%ld " , & num ) ; if ( num >= temp ) { count ++ ; } else { sum = sum + ( count * ( count + 1 ) / 2 ) ; count = 1 ; } temp = num ; } sum = sum + ( count * ( count + 1 ) / 2 ) ; printf ( "%lld\n" , sum ) ; } return 0 ; }