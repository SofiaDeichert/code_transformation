int max ( int x , int y ) { return x >= y ? x : y ; } int main ( ) { int t ; int curr [ MAX ] = { 0 } ; int next [ MAX ] ; int n ; int i , j , c ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) scanf ( "%d" , & next [ j ] ) ; for ( j = i ; j >= 1 ; j -- ) curr [ j ] = next [ j ] + max ( curr [ j ] , curr [ j - 1 ] ) ; curr [ 0 ] += next [ 0 ] ; } c = 0 ; for ( i = 0 ; i < n ; i ++ ) if ( curr [ c ] < curr [ i ] ) c = i ; printf ( "%d\n" , curr [ c ] ) ; } return 0 ; }