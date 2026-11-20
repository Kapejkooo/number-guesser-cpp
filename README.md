# 1 to 100 — Number Guesser

A tiny console game in C++. The program picks a secret number between 1 and 100
and tells you whether each guess is too high or too low until you find it.

## Features

- Random secret number every round
- "Too high" / "Too low" hints
- Counts how many guesses you needed
- Rejects letters and out-of-range numbers instead of crashing
- Play again without restarting

## Build

**Windows** — double-click `build.bat` (needs [MinGW-w64](https://winlibs.com/);
`winget install BrechtSanders.WinLibs.POSIX.UCRT` works too). You get `NumberGuesser.exe`.

**Any platform** — one command:

```
g++ -std=c++17 -O2 -o guesser main.cpp
```

## Run

```
NumberGuesser.exe        (Windows)
./guesser                (Linux / macOS)
```

## Example

```
   1 to 100 - Number Guesser

I picked a number between 1 and 100.
Guess #1 (1-100): 50
  Too high.
Guess #2 (1-100): 25
  Too low.
Guess #3 (1-100): 37

Correct! The number was 37. You found it in 3 guesses.
```

## Files

| File | What it is |
|---|---|
| `main.cpp` | The whole game |
| `build.bat` | One-click Windows build |
