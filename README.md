# czipbomb

Zipbomb using C.

Inspired by my Python package [zipbomb](https://github.com/donno2048/zipbomb).

```diff
- Only works on Linux.
```

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
./zipbomb number_of_files size_in_kilobytes > output_file
```
