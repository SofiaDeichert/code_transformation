int maxCal ( int * , int , int , int ) ; int sum_M [ 100 ] = { 0 } ; int main ( ) { int a [ 100 ] ; int n , i = 0 , row , j = 0 , tot = 0 ; scanf ( "%d" , & n ) ; for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , & row ) ; tot = row * ( row + 1 ) / 2 ; for ( j = 0 ; j < tot ; j ++ ) { scanf ( "%d" , & a [ j ] ) ; } printf ( "%d" , maxCal ( a , row , 0 , 1 ) ) ; } return 0 ; } int maxCal ( int * a , int n , int in , int nl ) { int sum = 0 , sum1 = 0 , temp = 0 ; if ( nl == n ) return a [ in ] ; temp = in + nl ; nl = nl + 1 ; if ( sum_M [ in ] == 0 ) { sum1 = a [ in ] + maxCal ( a , n , temp , nl ) ; sum = a [ in ] + maxCal ( a , n , temp + 1 , nl ) ; if ( sum > sum1 ) { sum_M [ in ] = sum ; return sum ; } sum_M [ in ] = sum1 ; return sum1 ; } else { return sum_M [ in ] ; } }