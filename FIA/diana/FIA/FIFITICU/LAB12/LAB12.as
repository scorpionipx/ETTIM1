opt subtitle "HI-TECH Software Omniscient Code Generator (Lite mode) build 7503"

opt pagewidth 120

	opt lm

	processor	16F887
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
pc	equ	2
pcl	equ	2
status	equ	3
fsr	equ	4
fsr0	equ	4
c	equ	1
z	equ	0
pclath	equ	10
	FNROOT	_main
	FNCALL	intlevel1,_my_isr
	global	intlevel1
	FNROOT	intlevel1
	global	_INTCON
psect	text60,local,class=CODE,delta=2
global __ptext60
__ptext60:
_INTCON	set	11
	global	_PORTD
_PORTD	set	8
	global	_INTE
_INTE	set	92
	global	_INTF
_INTF	set	89
	global	_RB4
_RB4	set	52
	global	_RB5
_RB5	set	53
	global	_RB6
_RB6	set	54
	global	_RB7
_RB7	set	55
	global	_RBIE
_RBIE	set	91
	global	_RBIF
_RBIF	set	88
	global	_RD4
_RD4	set	68
	global	_RD5
_RD5	set	69
	global	_RD6
_RD6	set	70
	global	_RD7
_RD7	set	71
	global	_IOCB
_IOCB	set	150
	global	_TRISB
_TRISB	set	134
	global	_TRISD
_TRISD	set	136
	global	_WPUB
_WPUB	set	149
	global	_INTEDG
_INTEDG	set	1038
	global	_ANSEL
_ANSEL	set	392
	global	_ANSELH
_ANSELH	set	393
	file	"LAB12.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	?_my_isr
?_my_isr:	; 0 bytes @ 0x0
	global	??_my_isr
??_my_isr:	; 0 bytes @ 0x0
	ds	4
	global	??_main
??_main:	; 0 bytes @ 0x4
;;Data sizes: Strings 0, constant 0, data 0, bss 0, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      4       4
;; BANK0           80      0       0
;; BANK1           80      0       0
;; BANK3           96      0       0
;; BANK2           96      0       0

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   None.
;;
;; Critical Paths under _my_isr in COMMON
;;
;;   None.
;;
;; Critical Paths under _main in BANK0
;;
;;   None.
;;
;; Critical Paths under _my_isr in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _my_isr in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK3
;;
;;   None.
;;
;; Critical Paths under _my_isr in BANK3
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.
;;
;; Critical Paths under _my_isr in BANK2
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 0
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (1) _my_isr                                               4     4      0       0
;;                                              0 COMMON     4     4      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 1
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;
;; _my_isr (ROOT)
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      4       4       1       28.6%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       0       2        0.0%
;;ABS                  0      0       0       3        0.0%
;;BITBANK0            50      0       0       4        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;BANK0               50      0       0       5        0.0%
;;BITSFR2              0      0       0       5        0.0%
;;SFR2                 0      0       0       5        0.0%
;;BITBANK1            50      0       0       6        0.0%
;;BANK1               50      0       0       7        0.0%
;;BITBANK3            60      0       0       8        0.0%
;;BANK3               60      0       0       9        0.0%
;;BITBANK2            60      0       0      10        0.0%
;;BANK2               60      0       0      11        0.0%
;;DATA                 0      0       0      12        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 4 in file "C:\Users\student\Desktop\LAB12\lab12.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"C:\Users\student\Desktop\LAB12\lab12.c"
	line	4
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 7
; Regs used in _main: [wreg+status,2]
	line	5
	
l1412:	
;lab12.c: 5: TRISB=0xFF;
	movlw	(0FFh)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(134)^080h	;volatile
	line	6
	
l1414:	
;lab12.c: 6: ANSEL=0;
	bsf	status, 5	;RP0=1, select bank3
	bsf	status, 6	;RP1=1, select bank3
	clrf	(392)^0180h	;volatile
	line	7
	
l1416:	
;lab12.c: 7: ANSELH=0;
	clrf	(393)^0180h	;volatile
	line	8
	
l1418:	
;lab12.c: 8: TRISD=0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	clrf	(136)^080h	;volatile
	line	9
	
l1420:	
;lab12.c: 9: INTCON=0b10011000;
	movlw	(098h)
	movwf	(11)	;volatile
	line	10
	
l1422:	
;lab12.c: 10: IOCB=0b11110000;
	movlw	(0F0h)
	movwf	(150)^080h	;volatile
	line	11
	
l1424:	
;lab12.c: 11: WPUB=0;
	clrf	(149)^080h	;volatile
	goto	l1026
	line	13
;lab12.c: 13: while(1)
	
l1025:	
	line	15
;lab12.c: 14: {
	
l1026:	
	line	13
	goto	l1026
	
l1027:	
	line	16
	
l1028:	
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_my_isr
psect	text61,local,class=CODE,delta=2
global __ptext61
__ptext61:

;; *************** function _my_isr *****************
;; Defined at:
;;		line 18 in file "C:\Users\student\Desktop\LAB12\lab12.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          4       0       0       0       0
;;      Totals:         4       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text61
	file	"C:\Users\student\Desktop\LAB12\lab12.c"
	line	18
	global	__size_of_my_isr
	__size_of_my_isr	equ	__end_of_my_isr-_my_isr
	
_my_isr:	
	opt	stack 7
; Regs used in _my_isr: [wreg+status,2]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_my_isr+0)
	movf	fsr0,w
	movwf	(??_my_isr+1)
	movf	pclath,w
	movwf	(??_my_isr+2)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	btemp+1,w
	movwf	(??_my_isr+3)
	ljmp	_my_isr
psect	text61
	line	19
	
i1l1426:	
;lab12.c: 19: if(INTF==1 && INTE==1)
	btfss	(89/8),(89)&7
	goto	u1_21
	goto	u1_20
u1_21:
	goto	i1l1438
u1_20:
	
i1l1428:	
	btfss	(92/8),(92)&7
	goto	u2_21
	goto	u2_20
u2_21:
	goto	i1l1438
u2_20:
	line	20
	
i1l1430:	
;lab12.c: 20: { INTF=0;
	bcf	(89/8),(89)&7
	line	21
;lab12.c: 21: if(INTEDG==1)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	btfss	(1038/8)^080h,(1038)&7
	goto	u3_21
	goto	u3_20
u3_21:
	goto	i1l1032
u3_20:
	line	22
	
i1l1432:	
;lab12.c: 22: {INTEDG=0;PORTD=0xFF;}
	bcf	(1038/8)^080h,(1038)&7
	
i1l1434:	
	movlw	(0FFh)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(8)	;volatile
	goto	i1l1438
	line	23
	
i1l1032:	
	line	24
;lab12.c: 23: else
;lab12.c: 24: {INTEDG=1;PORTD=0;}
	bsf	(1038/8)^080h,(1038)&7
	
i1l1436:	
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(8)	;volatile
	goto	i1l1438
	
i1l1033:	
	goto	i1l1438
	line	26
	
i1l1031:	
	line	28
	
i1l1438:	
;lab12.c: 26: }
;lab12.c: 28: if(RBIF==1&& RBIE==1)
	btfss	(88/8),(88)&7
	goto	u4_21
	goto	u4_20
u4_21:
	goto	i1l1043
u4_20:
	
i1l1440:	
	btfss	(91/8),(91)&7
	goto	u5_21
	goto	u5_20
u5_21:
	goto	i1l1043
u5_20:
	line	30
	
i1l1442:	
;lab12.c: 30: {if(RB4==1) RD4=1;
	btfss	(52/8),(52)&7
	goto	u6_21
	goto	u6_20
u6_21:
	goto	i1l1035
u6_20:
	
i1l1444:	
	bsf	(68/8),(68)&7
	goto	i1l1036
	line	31
	
i1l1035:	
;lab12.c: 31: else RD4=0;
	bcf	(68/8),(68)&7
	
i1l1036:	
	line	33
;lab12.c: 33: if(RB5==1) RD5=1;
	btfss	(53/8),(53)&7
	goto	u7_21
	goto	u7_20
u7_21:
	goto	i1l1037
u7_20:
	
i1l1446:	
	bsf	(69/8),(69)&7
	goto	i1l1038
	line	34
	
i1l1037:	
;lab12.c: 34: else RD5=0;
	bcf	(69/8),(69)&7
	
i1l1038:	
	line	36
;lab12.c: 36: if(RB6==1) RD6=1;
	btfss	(54/8),(54)&7
	goto	u8_21
	goto	u8_20
u8_21:
	goto	i1l1039
u8_20:
	
i1l1448:	
	bsf	(70/8),(70)&7
	goto	i1l1040
	line	37
	
i1l1039:	
;lab12.c: 37: else RD6=0;
	bcf	(70/8),(70)&7
	
i1l1040:	
	line	39
;lab12.c: 39: if(RB7==1) RD7=1;
	btfss	(55/8),(55)&7
	goto	u9_21
	goto	u9_20
u9_21:
	goto	i1l1041
u9_20:
	
i1l1450:	
	bsf	(71/8),(71)&7
	goto	i1l1042
	line	40
	
i1l1041:	
;lab12.c: 40: else RD7=0;
	bcf	(71/8),(71)&7
	
i1l1042:	
	line	42
;lab12.c: 42: RBIF=0;
	bcf	(88/8),(88)&7
	goto	i1l1043
	line	43
	
i1l1034:	
	line	44
	
i1l1043:	
	movf	(??_my_isr+3),w
	movwf	btemp+1
	movf	(??_my_isr+2),w
	movwf	pclath
	movf	(??_my_isr+1),w
	movwf	fsr0
	swapf	(??_my_isr+0)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_my_isr
	__end_of_my_isr:
;; =============== function _my_isr ends ============

	signat	_my_isr,88
psect	text62,local,class=CODE,delta=2
global __ptext62
__ptext62:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
