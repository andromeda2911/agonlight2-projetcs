;
; Title:	clreol.asm
; Author:	Badre
; Created:	23/12/2023
;

include '../../lib/libc/mos_api.inc'
	
	section	.text,"ax",@progbits
	assume adl = 1        

	public	_clreol

_MAX_X      EQU 80

_clreol:
	push ix
    push af
    push bc
    push hl
    push de

    call _get_cursor_position
    call _cursorX
	ld b, a
    call _get_cursor_position
    call _cursorY
	ld h, a
    call  _gotoxy

sendcar:
    ld a, _MAX_X
    sub b
    ld b, a

sendcarloop:
    ld a, (_blank)
    call putc
    djnz sendcarloop

    pop de
    pop hl
    pop bc
    pop af
	pop ix
	ret				; return l as h:keyascii

putc:
	rst.lil $10
	ret

_gotoxy:
    ld  a, 31
    call putc
    ld  a, b
    call putc
    ld  a, h
    call putc
    ret

_cursorX:
	push	ix
	ld		a, mos_sysvars			; MOS Call for mos_sysvars
	rst.lil	08h					; returns pointer to sysvars in ixu
	ld		a, (ix+sysvar_cursorX)
	pop		ix
	ret

_cursorY:
	push 	ix
	ld		a, mos_sysvars			; MOS Call for mos_sysvars
	rst.lil	08h					; returns pointer to sysvars in ixu
	ld		a, (ix+sysvar_cursorY)
	pop		ix
	ret

_get_cursor_position:
    call _set0_sysvar_vpd_pflags    
    ld  a, 23
    call putc
    ld  a, 0
    call putc
    ld  a, $82
    call putc    

wait_set_flag:
    call _get_sysvar_vpd_pflags
    and  01h
    jr  z,  wait_set_flag 
    ret

; Set pflahgs to 0
_set0_sysvar_vpd_pflags:
	push	ix
	ld		a, mos_sysvars
	rst.lil	08h
    ld      a, 00h
	ld	    (ix+sysvar_vpd_pflags), a 
	pop		ix
	ret

;Get sysvar pFlags
_get_sysvar_vpd_pflags:
	push	ix
	ld		a, mos_sysvars
	rst.lil	08h
	ld		a, (ix+sysvar_vpd_pflags)
	pop		ix
	ret

_blank db ' '    
_vdu_cursor_tab:
	db	31
	db	0
	db	0

        
