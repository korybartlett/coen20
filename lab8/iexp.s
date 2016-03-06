		rseg CODE:CODE(2)
		THUMB
      
; ------------------------------------------------------------------------------------------
; int32_t iexp(int32_t x, uint32_t n)
; ------------------------------------------------------------------------------------------

		EXPORT  iexp
iexp

	; The first parameter (x) is passed to this function in R0.
	; The second parameter (n) is passed to this function in R1.
	; The function should return the result in R0.

	; Registers R0 through R3 may be modified without 
	; preserving their original content. However, the
	; value of all other registers must be preserved!

	; Insert your code here ...
        
        PUSH{R4}; MAKES R4 USEABLE
        LDR R2, =1; CREATES Y
        MOV R3, R0; CREATES P
        
TOP:    AND R4, R1, #1;SAVES N AND 1 INTO R4 FOR COMPARISSON
        CMP R4,#0
        BEQ L1;BRANCHES TO SKIP MULTIPLICATION IF EQ
        MUL R2,R2,R3; MULTIPLIES P AND Y
L1:     LSR R1,R1,#1;SHIFTS N BY 1 TO THE RIGHT
        
        CMP R1,#0; COMPARES N WITH ZERO
        BEQ DONE; IF EQUAL ESCAPE LOOP
        MUL R3,R3,R3; MULTIPLIES P BY P
        B TOP; LOOPS BACK TO START
        
DONE:   MOV R0,R2; MOVES Y INTO RETURNABLE REGISTER
        POP{R4}
        BX	LR		; return
        END


