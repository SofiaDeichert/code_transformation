int * pt , largest = 0 , max ; int sum ( int n ) { int i , sum = 0 ; for ( i = 1 ; i <= n ; i ++ ) sum = sum + i ; return sum ; } void flar ( int i , int ro , int sum ) { sum = sum + pt [ i ] ; if ( ro < max ) { flar ( i + ro , ro + 1 , sum ) ; flar ( i + ro + 1 , ro + 1 , sum ) ; } else if ( largest < sum ) largest = sum ; } main ( ) { int t , row , i , n ; scanf ( "%d" , & t ) ; while ( t -- ) { scanf ( "%d" , & row ) ; max = row ; pt = ( int * ) malloc ( sizeof ( int ) * row ) ; n = sum ( row ) ; for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , pt + i ) ; flar ( 0 , 1 , 0 ) ; printf ( "\n%d" , largest ) ; } }