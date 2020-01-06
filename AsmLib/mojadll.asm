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

;-------------------------------------------------------------------------; Funkcja uœredniaj¹ca wartoœci podane w tablicy i zwracaj¹ca ich wynik

Mozaika PROC stdcall uses EAX EBX ECX EDX, tablica: DWORD, ilosc: DWORD

	MOV EAX, tablica	;Adres 1 komórki tablicy na stos
	ADD EAX, ilosc		;Przesuniêcie siê w tablicy o iloœæ elementów
	SUB EAX, 1			
	MOV CL, 0			;Zerowanie CL

P:
	MOV BL, [EAX]		;Wpisywanie wartoœci z tablicy do BL
	ADD CL, BL			;Dodawanie zawartoœci BL do zawartoœci CL
	CMP EAX, tablica	;Sprawdzanie czy dotarto na pocz¹tek tablicy (zakoñczono operacje)
	JE K				;Jeœli tak, to skok do koñca
	SUB EAX, 1			;Jeœli nie to przesuñ o 1 wartoœæ
	JMP P				;Powtórz pêtlê

K:
	MOV [EAX], CL		;Wpisanie sumy do pierwszej komórki tablicy
	RET					;Wyjœcie z funkcji

Mozaika ENDP

END DllEntry ;-------------------------------------------------------------------------