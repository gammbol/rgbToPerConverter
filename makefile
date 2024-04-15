cc=gcc
cflags=-Wall -Werror -Wextra
output=rtpc

all: build

build:
	$(cc) $(cflags) main.c -o $(output)

install: build 
	sudo mv $(output) /usr/local/bin

uninstall:
	sudo rm -rf /usr/local/bin/$(output)

delete:
	rm -rf $(output)

rebuild: delete build
