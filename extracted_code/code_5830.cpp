int findmax ( int n , int tri [ ] , int loc , int c_row ) { if ( c_row == n ) return tri [ loc ] ; int v1 , v2 ; v1 = findmax ( n , tri , loc + c_row , c_row + 1 ) ; v2 = findmax ( n , tri , loc + c_row + 1 , c_row + 1 ) ; if ( v1 > v2 ) return v1 + tri [ loc ] ; else return v2 + tri [ loc ] ; } int main ( ) { int t ; scanf ( "%d" , & t ) ; for ( int i = 0 ; i < t ; i ++ ) { int n , tot_n ; scanf ( "%d" , & n ) ; tot_n = n * ( n + 1 ) / 2 ; int tri [ tot_n ] ; for ( int j = 0 ; j < tot_n ; j ++ ) { scanf ( "%d" , & tri [ j ] ) ; } printf ( "%d\n" , findmax ( n , tri , 0 , 1 ) ) ; } return 0 ; }