unsigned long long int find_gcm ( unsigned long long int , unsigned long long int ) ; int main ( ) { unsigned int T , i ; T = i = 0 ; scanf ( "%u" , & T ) ; for ( i = 0 ; i < T ; i ++ ) { unsigned long long int A , B , O ; A = B = O = 0 ; scanf ( "%llu %llu" , & A , & B ) ; O = find_gcm ( A , B ) ; printf ( "%llu " , O ) ; printf ( "%llu\n" , ( A * B / O ) ) ; } return 0 ; } unsigned long long int find_gcm ( unsigned long long int A , unsigned long long int B ) { while ( A != B ) { if ( A > B ) A = A - B ; else B = B - A ; } return A ; }