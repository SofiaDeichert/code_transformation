int Partition ( long int A [ ] , int p , int r ) { long int x = A [ r ] , temp ; int i = p - 1 , j ; for ( j = p ; j < r ; j ++ ) { if ( A [ j ] <= x ) { i = i + 1 ; temp = A [ i ] ; A [ i ] = A [ j ] ; A [ j ] = temp ; } } temp = A [ i + 1 ] ; A [ i + 1 ] = A [ r ] ; A [ r ] = temp ; return ( i + 1 ) ; } void QuickSort ( long int A [ ] , int p , int r ) { if ( p < r ) { int q = Partition ( A , p , r ) ; QuickSort ( A , p , q - 1 ) ; QuickSort ( A , q + 1 , r ) ; } return ; } int main ( ) { int t ; scanf ( "%d" , & t ) ; while ( t -- ) { int n , i ; scanf ( "%d" , & n ) ; long int A [ n ] ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%ld" , & A [ i ] ) ; QuickSort ( A , 0 , n - 1 ) ; printf ( "%ld\n" , ( ( n - 1 ) * A [ 0 ] ) ) ; } }