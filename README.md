# Making a rougelite game in c++ using raylib engine.

An ambitious rougelite game using [Raylib](https://www.raylib.com/).  


## Requirements
- Linux, (will work on windows if you figure out how to install raylib there) 
- C++17 compatible compiler (`g++`)
- Raylib library installed

---

## Build and Run

### Build the game

```bash
make
```

### Run the game

```bash
make run
```

### Clean build files

```bash
make clean
```


## Notes

* The Makefile automatically detects Raylib using `pkg-config`.
* You can extend the game by adding more `.cpp` and `.h` files in `src/` and including them in the Makefile.


---
