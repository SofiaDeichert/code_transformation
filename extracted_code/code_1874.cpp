int main ( ) { int t , i ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , num , next ; scanf ( "%d" , & n ) ; scanf ( "%d" , & num ) ; long long int s = n , r = 1 , p ; for ( i = 1 ; i < n ; i ++ ) { scanf ( "%d" , & next ) ; if ( next >= num ) { r ++ ; } else { p = ( r * ( r - 1 ) ) >> 1 ; s = s + p ; r = 1 ; } num = next ; } p = ( r * ( r - 1 ) ) >> 1 ; s = s + p ; printf ( "%lld\n" , s ) ; } return 0 ; }