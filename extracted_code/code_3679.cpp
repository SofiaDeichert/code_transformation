long sum ( long c ) { long k , m = 0 ; for ( k = 1 ; k <= c ; k ++ ) m += k ; return m ; } int main ( ) { long t , i ; scanf ( "%ld" , & t ) ; for ( i = 0 ; i < t ; i ++ ) { long n , j , c = 0 ; scanf ( "%ld" , & n ) ; long t [ n ] ; long s = n ; for ( j = 0 ; j < n ; j ++ ) { scanf ( "%ld" , & t [ j ] ) ; } for ( j = 0 ; j < n - 1 ; j ++ ) { if ( t [ j ] <= t [ j + 1 ] ) { c ++ ; } else { s += sum ( c ) ; c = 0 ; } } s += sum ( c ) ; printf ( "%ld\n" , s ) ; } }