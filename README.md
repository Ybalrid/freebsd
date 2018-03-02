FreeHugsBSD Source:
---------------

**This is a fork of the FreeBSD Operating System. All the same, but we do accept virtual hugs**

This is the top level of the FreeHugsBSD source directory.  This file
was last revised on:
$FreeHugsBSD$

For copyright information, please see the file COPYRIGHT in this
directory (additional copyright information also exists for some
sources in this tree - please see the specific source directories for
more information).

The Makefile in this directory supports a number of targets for
building components (or all) of the FreeHugsBSD source tree.  See build(7)
and https://www.freebsd.org/doc/en_US.ISO8859-1/books/handbook/makeworld.html
for more information, including setting make(1) variables.

The `buildkernel` and `installkernel` targets build and install
the kernel and the modules (see below).  Please see the top of
the Makefile in this directory for more information on the
standard build targets and compile-time flags.

Building a kernel is a somewhat more involved process.  See build(7), config(8),
and https://www.freebsd.org/doc/en_US.ISO8859-1/books/handbook/kernelconfig.html
for more information.

Note: If you want to build and install the kernel with the
`buildkernel` and `installkernel` targets, you might need to build
world before.  More information is available in the handbook.

The kernel configuration files reside in the `sys/<arch>/conf`
sub-directory.  GENERIC is the default configuration used in release builds.
NOTES contains entries and documentation for all possible
devices, not just those commonly used.


Source Roadmap:
---------------
```
bin		System/user commands.

cddl		Various commands and libraries under the Common Development
		and Distribution License.

contrib		Packages contributed by 3rd parties.

crypto		Cryptography stuff (see crypto/README).

etc		Template files for /etc.

gnu		Various commands and libraries under the GNU Public License.
		Please see gnu/COPYING* for more information.

include		System include files.

kerberos5	Kerberos5 (Heimdal) package.

lib		System libraries.

libexec		System daemons.

release		Release building Makefile & associated tools.

rescue		Build system for statically linked /rescue utilities.

sbin		System commands.

secure		Cryptographic libraries and commands.

share		Shared resources.

stand		Boot loader sources.

sys		Kernel sources.

tests		Regression tests which can be run by Kyua.  See tests/README
		for additional information.

tools		Utilities for regression testing and miscellaneous tasks.

usr.bin		User commands.

usr.sbin	System administration commands.
```

For information on synchronizing your source tree with one or more of
the FreeBSD Project's development branches, please see:

  https://www.freebsd.org/doc/en_US.ISO8859-1/books/handbook/current-stable.html
