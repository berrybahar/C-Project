MAIN: mov @r3, LENGTH
LOOP: jmp L1
    prn -5
    bne LOOP
    sub @r1, @r4
    bne END
    add 5, @r1
    not @r1
    not K
    clr @r7
    clr M
    lea K, @r2
    lea K, M
    dec @r4
    dec K
    red @r6
    red M
    jsr @r5
    jsr K
    bne @r3
    add @r2, @r0
    add @r4, M
    mov @r3, K
    mov 69, @r7
    mov K, @r1
    cmp M, LENGTH
    cmp 770,@r1
    cmp @r1, LOOP
    sub -2, @r6
    sub L2, @r2
    prn @r1
    prn L3
    inc @r3
    jmp @r4
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
cmp M, @r1
cmp M, 69
cmp @r1, 770
cmp @r1, @r6
cmp 69, M
cmp 69, 70
add K, @r1
add K, M
add 5, @r1
add 5, M
sub @r1, M
sub -2, M
sub L2, @r1
.entry L3
.extern L2