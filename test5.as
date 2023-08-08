X:.extern X
Y:.entry Y 
 
 mov @r1,@r2 
 mov @r1,X
 mov X,@r1
 mov X,Y
 mov 5,@r1
 mov 5,X

 cmp 5,5
 cmp 5,@r1
 cmp 5,x 
 cmp @r1,5
 cmp @r1,X
 cmp @r1,@r2 
 cmp X,5
 cmp X,@r1 
 cmp X,Y