# gcc security compiler flags

	• -Wall -Wextra
Turn on all warnings to help ensure the underlying code is secure.
	• -Wconversion -Wsign-conversion
 Warn on unsign/sign conversion
 
	• -Wformat­security
 Warn about uses of format functions that represent possible security problems
 
	• -Werror 
Turns all warnings into errors.
 
	• -fstack-protector-all -Wstack-protector --param ssp-buffer-size=4 
Your choice of "-fstack-protector" does not protect all functions (see comments). You need -fstack-protector-all to guarantee guards are applied to all functions, although this will likely incur a performance penalty. Consider -fstack-protector-strong as a middle ground. 
The -Wstack-protector flag here gives warnings for any functions that aren't going to get protected.
 
	• -pie -fPIE 
For ASLR
 
	• -ftrapv 
Generates traps for signed overflow (currently bugged in gcc)
 
	• -D_FORTIFY_SOURCE=2 -O2
 Buffer overflow checks. See also difference between =2 and =1
 
	• ­-Wl,-z,relro,-z,now
 RELRO (read-only relocation). The options relro & now specified together are known as "Full RELRO". You can specify "Partial RELRO" by omitting the now flag. RELRO marks various ELF memory sections read­only (E.g. the GOT)


Behandelt
	• Adress Sanitation
	• Overflow Checks

