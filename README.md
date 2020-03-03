
# Breakout (DOS)

This clone of Breakout is a simple learning project to teach myself some DOS programming.

![Screenshot](breakout.png)

## Setup

This project was developed against the Digital Mars C Compiler. Other compilers may work also.

* Extract the following compiler files into a suitable bin dir
* [Digital Mars C/C++ 8.57](http://ftp.digitalmars.com/Digital_Mars_C++/Patch/dm857c.zip)
* Extract the following lib files into the same dir as the compiler
* [Digital Mars DOS16 Libs](http://ftp.digitalmars.com/Digital_Mars_C++/Patch/dm850dos.zip)
* Update the CC macro at the top of `Makefile` to point to the compiler binary
* Run `make all` to build `breakout.exe`

The resulting binary executable should work in DosBox. It will _not_ work in Windows.

## Fun Technical Deets

DOS has different memory models based on whether your code and/or data segments can be addressed in only 16 bits. Selecting a smaller memory model allows the compiler to skip doing segment with offset address logic.

```
Code        Data        Compiler Flag
under 64KB  under 64KB  Small (-ms) or Tiny (-mt)
over 64KB   under 64KB  Medium (-mm)
under 64KB  over 64KB   Compact (-mc)
over 64KB   over 64KB   Large (-ml)
```

Although this project uses Digital Mars standard C libs and DOS libs, a fun project is to cut dependencies by directly implementing low-level functions against the DOS API (using Interrupt 21 services.) In this way the size of the binary exe produced can be optimized, but it is generally not worth the inconvenience.

## References

* [Wikipedia - DOS API](https://en.wikipedia.org/wiki/DOS_API)
* [Wikipedia - Mode 13h](https://en.wikipedia.org/wiki/Mode_13h)
* [Digital Mars Docs - Memory Model](https://digitalmars.com/ctg/ctgMemoryModel.html)
* [David Brackeen - VGA Programming](http://www.brackeen.com/vga/unchain.html)
