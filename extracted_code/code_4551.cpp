void Qsort ( int data [ ] , int left , int right ) ; int main ( ) { int t , n , i , j ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & n ) ; int a [ n ] , sum [ n ] ; for ( i = 0 ; i < n ; i ++ ) { for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & a [ j ] ) ; } if ( i == 0 ) sum [ 0 ] = a [ 0 ] ; else { sum [ i ] = a [ i ] + sum [ i - 1 ] ; for ( j = i - 1 ; j > 0 ; j -- ) { if ( sum [ j ] > sum [ j - 1 ] ) sum [ j ] = sum [ j ] + a [ j ] ; else sum [ j ] = sum [ j - 1 ] + a [ j ] ; } sum [ 0 ] = sum [ 0 ] + a [ 0 ] ; } } Qsort ( sum , 0 , n - 1 ) ; printf ( "%d\n" , sum [ n - 1 ] ) ; } return 0 ; } void Qsort ( int data [ ] , int left , int right ) { int mid , temp , i , j ; i = left ; j = right ; mid = data [ ( left + right ) / 2 ] ; while ( i <= j ) { while ( data [ i ] < mid ) i ++ ; while ( mid < data [ j ] ) j -- ; if ( i <= j ) { temp = data [ i ] ; data [ i ] = data [ j ] ; data [ j ] = temp ; i ++ ; j -- ; } } if ( left < j ) Qsort ( data , left , j ) ; if ( i < right ) Qsort ( data , i , right ) ; }