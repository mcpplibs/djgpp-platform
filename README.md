# djgpp-platform

The platform package (mcpp SPEC-013) of 32-bit DOS programs built by DJGPP: the row `i586-dos-djgpp`
as data, its GCC payload, and DOSBox Staging as its runner.

```toml
[target.i586-dos-djgpp]
platform = "djgpp-platform@0.1.0"
```

```sh
mcpp build --target i586-dos-djgpp     # hello.exe: MZ with a COFF image (go32)
mcpp run   --target i586-dos-djgpp     # run under DOSBox Staging; its output and status come back
```

| Part | Where |
|---|---|
| the row: COFF, `.exe`, 32-bit data model, the execution system `dos` | `[[platform.define]]` |
| the compiler: DJGPP's GCC 12.2.0, named by the row's GCC target `i586-pc-msdosdjgpp` (xim `i586-pc-msdosdjgpp-gcc`) | `gcc-triple`, `[platform] toolchain` |
| the C library: DJGPP 2.05, the toolchain's own | `[platform.layers]` |
| the runner: dirun places the program and CWSDPMI (the DPMI host) in the directory DOSBox mounts as `C:` and reads the program's output and status back from files a launcher writes (xim `dosbox-staging`, `dirun`) | `[platform.runner]` |

The engine knows no DOS: the row, its payload and its runner are this package's. The GCC target a
row states is the engine's general mechanism for a cross GCC (mcpp 2026.11.13.1).

**C only.** mcpp compiles C++ as modules, which needs a GCC with module dependency scanning (14 and
later); DJGPP's GCC is 12.2.0, and a C++ target is refused naming that.

**Verified.** `examples/hello`, built with mcpp and run under DOSBox Staging 0.83.0 through dirun
0.3.0: its arguments, a file written and read back, status 42 (0.6 s).

Apache-2.0.
