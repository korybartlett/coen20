		rseg CODE:CODE(2)
		THUMB
      
; ------------------------------------------------------------------------------------------
; uint32_t isqrt(uint32_t x)
; ------------------------------------------------------------------------------------------

		EXPORT  isqrt
isqrt

	; The one parameter (x) is passed to this function in R0.
	; The function should return the result in R0

	; Registers R0 through R3 may be modified without 
	; preserving their original content. However, the
	; value of all other registers must be preserved!

	; Insert your code here....
        
        LDR R1,=0 ;Y STORAGE
        LDR R2, =0x4000000 ;M STORAGE 
top:    CMP R2,#0; COMPARES M TO 0 BEGINS FOR LOOP
        BEQ done;WHHEN EQUAL BREAK THE LOOP
        ORR R3, R1, R2; CREATES B 
        LSR R1, R1, #1; SHIFTS Y OVER BY 1
        CMP R3, R0; COMPARES B AND X
        ITT LE;BEGINS IF STATEMENT FOR IF LESS THAN OR EQUAL TO
        SUBLE R0,R0,R3; SUBTRACTS X BY B
        ORRLE R1, R1, R2; ORS Y BY M
        LSR R2,R2,#2; SHIFTS M BY 2 TO THE RIGH
        B top; BRINGS LOOP BACK TO THE TOP
done:   MOV R0,R1;MOVES Y INTO RETURNABLE REGISTER
	
	BX	LR	; return

        END
