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
    cmp 770, @r0
    cmp @r0, LOOP
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
.extern L2
L2: .data 3
.entry M
.entry K
.entry LENGTH
.entry STR
.entry END
.entry L1
.entry LOOP
.entry MAIN
L3: .data -5
.entry L3

