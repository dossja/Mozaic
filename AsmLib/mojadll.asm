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

;-------------------------------------------------------------------------; Funkcja u�redniaj�ca warto�ci podane w tablicy i zwracaj�ca ich wynik

Mozaika PROC stdcall uses EAX EBX ECX EDX, tablica: DWORD, ilosc: DWORD

	MOV EAX, tablica	;Adres 1 kom�rki tablicy na stos
	ADD EAX, ilosc		;Przesuni�cie si� w tablicy o ilo�� element�w
	SUB EAX, 1			
	MOV CL, 0			;Zerowanie CL

P:
	MOV BL, [EAX]		;Wpisywanie warto�ci z tablicy do BL
	ADD CL, BL			;Dodawanie zawarto�ci BL do zawarto�ci CL
	CMP EAX, tablica	;Sprawdzanie czy dotarto na pocz�tek tablicy (zako�czono operacje)
	JE K				;Je�li tak, to skok do ko�ca
	SUB EAX, 1			;Je�li nie to przesu� o 1 warto��
	JMP P				;Powt�rz p�tl�

K:
	MOV [EAX], CL		;Wpisanie sumy do pierwszej kom�rki tablicy
	RET					;Wyj�cie z funkcji

Mozaika ENDP

END DllEntry ;-------------------------------------------------------------------------