void sort ( int a [ ] , int n , int m ) { int p = 0 ; if ( m > n ) { p = partation ( a , n , m ) ; sort ( a , n , p - 1 ) ; sort ( a , p + 1 , m ) ; } } int partation ( int a [ ] , int n , int m ) { int x = a [ m ] , h = n - 1 , k = 0 ; for ( k = n ; k <= m - 1 ; k ++ ) { if ( a [ k ] <= x ) { h = h + 1 ; swap ( & a [ h ] , & a [ k ] ) ; } } swap ( & a [ h + 1 ] , & a [ m ] ) ; return h + 1 ; } void swap ( int * a , int * b ) { int temp = 0 ; temp = * a ; * a = * b ; * b = temp ; } int main ( ) { int i , j , v ; scanf ( "%d" , & v ) ; while ( v > 0 ) { scanf ( "%d" , & i ) ; int a [ i ] ; for ( j = 0 ; j < i ; j ++ ) { scanf ( "%d" , & a [ j ] ) ; } sort ( a , 0 , i - 1 ) ; for ( j = 0 ; j < i ; j ++ ) { printf ( "%d " , a [ j ] ) ; } long long sum = 0 ; sum = a [ 0 ] * ( i - 1 ) ; printf ( "%lld" , sum ) ; v -- ; } return 0 ; }