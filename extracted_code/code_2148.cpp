int maxsum ; void trav ( int * [ ] , int , int , int , int , int ) ; int main ( void ) { int testcases , num , i , j ; scanf ( "%d" , & testcases ) ; while ( testcases -- ) { maxsum = - 1 ; int * arr [ SIZE ] ; scanf ( "%d" , & num ) ; for ( i = 0 ; i < num ; i ++ ) { arr [ i ] = malloc ( sizeof ( int ) * ( i + 1 ) ) ; for ( j = 0 ; j <= i ; j ++ ) { scanf ( "%d" , & arr [ i ] [ j ] ) ; } } trav ( arr , 0 , 0 , 1 , 0 , num ) ; printf ( "%d\n" , maxsum ) ; } return 0 ; } void trav ( int * arr [ ] , int curlevel , int curele , int maxnum , int sum , int maxlevel ) { if ( curlevel < maxlevel ) { sum += arr [ curlevel ] [ curele ] ; if ( curele < maxnum ) { trav ( arr , curlevel + 1 , curele , maxnum + 1 , sum , maxlevel ) ; trav ( arr , curlevel + 1 , curele + 1 , maxnum + 1 , sum , maxlevel ) ; } } else { if ( sum > maxsum ) maxsum = sum ; } }