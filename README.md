# miniatureOS
A toy operating system for exploring and learning about OS development.

<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
* [Prerequisites and Installation.](#prerequisites-and-installation)
* [Usage](#usage)
* [Tracker](#tracker)

## About The Project

miniatureOS is a toy OS project that has been started get familiar with parctices in OS development

### File Structure

    ├── boot              # Contains files of booting the OS.
    ├── cpu               # Contains CPU specific code.
    ├── drivers           # Drivers.
    ├── kernel            # Contains code for the kernel.
    ├── libc              # Contains C utility functions.
    ├── Makefile          
    ├── README.md
    ├── .clang-format
    ├── format.sh         # For code formatting.
    └── LICENSE
    
    
## Prerequisites and Installation.

Set up the path for  `crosscompiler` and `binutils`.

```sh
export PREFIX="/usr/local/i386elfgcc"
export TARGET=i386-elf
export PATH="$PREFIX/bin:$PATH"
```

* **nasm**

```sh
sudo apt-get install nasm
```
* **qemu**

```sh
sudo apt-get install qemu-kvm qemu virt-manager virt-viewer libvirt-bin
```


* **binutils**

```sh
mkdir /tmp/src
cd /tmp/src

curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.24.tar.gz
tar xf binutils-2.24.tar.gz

mkdir binutils-build
cd binutils-build

../binutils-2.24/configure --target=$TARGET --enable-interwork --enable-multilib --disable-nls --disable-werror --prefix=$PREFIX 2>&1 | tee configure.log

make all install 2>&1 | tee make.log
```

* **gcc(cross-compiler)**

```sh
cd /tmp/src

curl -O https://ftp.gnu.org/gnu/gcc/gcc-9.4.0/gcc-9.4.0.tar.bz2
tar xf gcc-9.4.0.tar.bz2

mkdir gcc-build
cd gcc-build

../gcc-4.9.1/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-libssp --enable-languages=c --without-headers

make all-gcc 
make all-target-libgcc 
make install-gcc 
make install-target-libgcc 
```
* **gdb**

```sh
cd /tmp/src

curl -O http://ftp.rediris.es/mirror/GNU/gdb/gdb-9.2.tar.gz
tar xf gdb-9.2.tar.gz

mkdir gdb-build
cd gdb-build

export PREFIX="/usr/local/i386elfgcc"
export TARGET=i386-elf

../gdb-9.2/configure --target="$TARGET" --prefix="$PREFIX" --program-prefix=i386-elf-

make
make install
```
<!-- USAGE EXAMPLES -->
## Usage
To build

```
make
```
To run

```
make run
```

To debug using gdb

```
make debug
```

<!-- FUTURE WORK -->
## Tracker
- [x] Bootloader.
- [x] Printers.
- [x] Interrupt handling.
- [ ] Shell.
- [ ] Memory Allocation.
- [ ] Memory management.
