int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { long int n , i = 0 , j = 0 ; scanf ( "%d" , & n ) ; long long int ar [ n ] ; long long int ns = n ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%lld" , & ar [ i ] ) ; int counter = 0 ; long int pos = 0 ; for ( i = 0 ; i < n ; i ++ ) { if ( counter == 1 ) { counter = 0 ; j = pos + 1 ; } else j = i ; for ( ; j < n ; j ++ ) { if ( ar [ j ] >= ar [ pos ] ) { counter = 1 ; pos = j ; } else break ; } if ( counter == 1 ) { int temp = pos - i ; ns += ( temp * temp + 1 ) / 2 ; } } printf ( "%lld\n" , ns ) ; } return 0 ; }