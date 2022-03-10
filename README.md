# czipbomb

Zipbomb using C.

Inspired by my Python package [zipbomb](https://github.com/donno2048/zipbomb).

## Compile

```sh
gcc -o zipbomb main.c
```

### Without cloning

```sh
wget https://raw.githubusercontent.com/donno2048/czipbomb/master/main.c -O- | gcc -xc - -o zipbomb
```

## Usage

```sh
./zipbomb -h # show help
./zipbomb name.zip number_of_files size_in_kilobytes # create a zipbomb, Windows sucks and its long is bad so we have to use big values... (more than 100 would be fine)
./zipbomb name.zip number_of_files # run with default size (1MB)
./zipbomb name.zip # run with default values (1000 files, 1MB)
./zipbomb # run with default argumets (output.zip, 1000 files, 1MB)
```
