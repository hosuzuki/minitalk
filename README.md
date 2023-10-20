# minitalk
<br>

## 🌕 What is minitalk ?

minitalk is an individual project at [42 Tokyo][1].

<br>

The purpose of this project is to code a small data exchange program using UNIX signals.

<br>

The goal of this project is to create two executables: a server and a client.

- The server must correctly receive and interpret this information, then display it.
  
- The client will send information (a string) to the server using UNIX signals.

<br>

The versatility of the printf function in C allows us to discover a feature of the C language – variadic functions – and to practice detailed management of the printing options.

<br><br>

## 🌕 Usage

### 🌖 Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.
<br><br>

### 🌖 Instructions

#### 🌗 1. Clone the repository

```shell
git clone --recursive git@github.com:hosuzuki/minitalk.git
```

The ``--recursive`` flag helps you initialize submodules in the clone.

<br>

And them, move to the cloned directory.
```shell
cd minitalk
```

#### 🌗 2. Run make

run the ``make`` command.
```shell
make
```

The Makefile compiles all files from the ``srcs/`` folders and saves the object files to the ``objs/`` folder. 

<br>

It then generates the executable files ``server`` and ``client`` in the root directory.


#### 🌗 3. Run server

```C
./server
```

Alter the execution, you will see the PID number (5 digits such as `20175`) whch will be used in the next step.

#### 🌗 4. Run client

Open another terminal and move to the cloned directory(minitalk/).

And then, run the command blew.
```C
./client [PID] [String to send] 
```

For instance:
```C
./client 20175 "Hello, world!"
```

After the execution, you should see "Hello, world!" in the server terminal.

[1]: https://42tokyo.jp/
