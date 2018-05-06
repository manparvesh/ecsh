# ecsh [![Build status](https://travis-ci.com/manparvesh/ecsh.svg?token=PLTqe9xbTbHzLpzsUbc5&branch=master)](https://travis-ci.com/manparvesh/ecsh)

Elementary shell written in C

![Demo](https://raw.githubusercontent.com/manparvesh/ecsh/master/screencasts/demo1.gif)

## Features

- Can run all commands present in the `PATH` env variable.
- Shows status of the command previously run as `OK` or `NG` (Not good).
- Shows basic but necessary things like `username`, `PC name` and `current directory`.

## How to run

- Create a `build` directory inside this repository.
- Run `cmake ..` in the `build` directory.
- Run `make`
- *[optional]* Run `make test` to run the tests.
- `ecsh` is created, you can use it like this: `./ecsh`

## Global installation

- Create a `build` directory inside this repository.
- Run `cmake ..` in the `build` directory.
- Run `sudo make install`

## Notes

- Commands must on a single line.
- No piping or redirection
- builtins:
  - cd
  - help
  - exit
  - all things added in the `PATH` variable

## TODO

- Piping and redirection
- Multi-line commands
- Simple C interpreter

---

## References

- [Write a shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
- [Making your own Linux Shell in C](https://www.geeksforgeeks.org/making-linux-shell-c/)
- [simple-c-shell](https://github.com/jmreyes/simple-c-shell)
- [write-a-C-interpreter](https://github.com/lotabout/write-a-C-interpreter)
