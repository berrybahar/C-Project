MAIN: mov @r3, LENGTH
LOOP: jmp L1
 a:   prn -5
  b:  bne LOOP
    c:sub @r1, @r4
    d:bne END
    e:add 5, @r1
    f:not @r1
    g:not K
    h:clr @r7
    j:clr M
    i:lea K, @r2
    l:lea K, M
    m:dec @r4
    n:dec K
    a1:red @r6
    a2:red M
    a3:jsr @r5
    a4:jsr K
    a5:bne @r3
    add @r2, @r0
    add @r4, M
    mov @r3, K
    mov 69, @r7
    mov K, @r1
    cmp M, LENGTH
   a6: cmp 770,@r0
   a7: cmp @r0, LOOP
    a8:sub -2, @r6
    a9:sub L2, @r2
    a10:prn @r1
    a11:prn L3
    a12:inc @r3
    a13:jmp @r4
L1: inc K
    bne LOOP
END: stop
    rts
STR: .string "abcdef"
LENGTH: .data 6,-9,15
K:  .data 22
M: .data -5
L3: .data -5
mov @r0, @r1
mov 69, K
mov K, M
cmp M, @r0
cmp M, 69
cmp @r0, 770
cmp @r0, @r6
cmp 69, M
cmp 69, 70
add K, @r0
add K, M
add 5, @r0
add 5, M
sub @r0, M
sub -2, M
sub L2, @r0
.entry L3
.extern L2