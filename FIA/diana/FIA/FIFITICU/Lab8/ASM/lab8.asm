#include p16f887.inc	
i equ 0x20
j equ 0x21

main:
	BSF STATUS, RP0
	MOVLW B'11111101'
	MOVWF TRISB
	BCF STATUS,RP0
	MOVLW D'10'
delay_1ms
	MOVLW D'198'
	MOVWF j

delay_100ms
	MOVLW D'198'
	MOVWF j
loopj:
	MOVLW D'249'
	MOVWF i

	loopi:
		NOP
		DECFSZ i,1
		GOTO loopi
		DECFSZ j,1
		GOTO loopj
		RETURN


buton_apasat:
	BSF PORTD,5
	CALL delay_100ms
	BCF PORTD,5
	CALL delay_100ms
	CALL delay_100ms
	CALL delay_100ms
	DECFSZ i,1
	GOTO loopi
	NOP
buton_end

end



