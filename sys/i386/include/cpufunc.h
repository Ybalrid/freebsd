/*
 * Functions to provide access to special i386 instructions.
 * XXX - bezillions more are defined in locore.s but are not declared anywhere.
 *
 *	$Id: cpufunc.h,v 1.9 1994/01/31 23:48:23 davidg Exp $
 */

#ifndef _MACHINE_CPUFUNC_H_
#define _MACHINE_CPUFUNC_H_ 1

#include <sys/cdefs.h>
#include <sys/types.h>

#include "machine/spl.h"

#ifdef	__GNUC__

static inline int bdb(void)
{
	extern int bdb_exists;

	if (!bdb_exists)
		return (0);
	__asm("int $3");
	return (1);
}

static inline void
disable_intr(void)
{
	__asm __volatile("cli");
}

static inline void
enable_intr(void)
{
	__asm __volatile("sti");
}

/*
 * This roundabout method of returning a u_char helps stop gcc-1.40 from
 * generating unnecessary movzbl's.
 */
#define	inb(port)	((u_char) u_int_inb(port))

static inline u_int
u_int_inb(u_int port)
{
	u_char	data;
	/*
	 * We use %%dx and not %1 here because i/o is done at %dx and not at
	 * %edx, while gcc-2.2.2 generates inferior code (movw instead of movl)
	 * if we tell it to load (u_short) port.
	 */
	__asm __volatile("inb %%dx,%0" : "=a" (data) : "d" (port));
	return data;
}

static inline void
outb(u_int port, u_char data)
{
	register u_char	al asm("ax");

	al = data;		/* help gcc-1.40's register allocator */
	__asm __volatile("outb %0,%%dx" : : "a" (al), "d" (port));
}

static inline void
tlbflush()
{
	__asm __volatile("movl %%cr3, %%eax; movl %%eax, %%cr3" : : : "ax");
}

#else /* not __GNUC__ */
extern	void insque __P((void *, void *));
extern	void remque __P((void *));

int	bdb		__P((void));
void	disable_intr	__P((void));
void	enable_intr	__P((void));
u_char	inb		__P((u_int port));
void	outb		__P((u_int port, u_int data));	/* XXX - incompat */

#endif	/* __GNUC__ */

void	load_cr0	__P((u_int cr0));
u_int	rcr0	__P((void));
void load_cr3(u_long);
u_long rcr3(void);
u_long rcr2(void);

void	setidt	__P((int, void (*)(), int, int));
extern u_long kvtop(void *);
extern void outw(int /*u_short*/, int /*u_short*/); /* XXX inline!*/
extern void outsb(int /*u_short*/, void *, size_t);
extern void outsw(int /*u_short*/, void *, size_t);
extern void insw(int /*u_short*/, void *, size_t);
extern void fillw(int /*u_short*/, void *, size_t);
extern void filli(int, void *, size_t);

#endif /* _MACHINE_CPUFUNC_H_ */
