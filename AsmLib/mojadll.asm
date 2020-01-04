;------------------------------------------------------------------------- 
.386 

.MODEL FLAT, STDCALL

OPTION CASEMAP:NONE

INCLUDE C:\masm32\include\windows.inc

.CODE

DllEntry PROC hInstDLL:HINSTANCE, reason:DWORD, reserved1:DWORD

	mov eax, TRUE
	ret

DllEntry ENDP

;------------------------------------------------------------------------- ; To jest przyk³adowa funkcja. Jest tutaj, aby pokazaæ, ; gdzie nale¿y umieszczaæ w³asne funkcje w bibliotece DLL ;-------------------------------------------------------------------------

MyProc1 proc x: DWORD, y: DWORD

	xor eax,eax 
	mov eax,x 
	mov ecx,y 
	ror ecx,1 
	shld eax,ecx,2 
	jnc ET1
	mul y
	ret 
	ET1: 
	Mul x
	Neg y
	ret

MyProc1 endp

;-------------------------------------------------------------------------; Funkcja uœredniaj¹ca wartoœci podane w tablicy i zwracaj¹ca ich wynik

Mozaika PROC stdcall uses EAX EBX ECX EDX, tablica: DWORD, ilosc: DWORD

	MOV EAX, tablica
	ADD EAX, ilosc
	SUB EAX, 1
	MOV CL, 0

P:
	MOV BL, [EAX]
	ADD CL, BL
	CMP EAX, tablica
	JE K
	SUB EAX, 1
	JMP P

K:
;	DIV [CL], ilosc
	MOV [EAX], CL
	RET

Mozaika ENDP

END DllEntry ;-------------------------------------------------------------------------