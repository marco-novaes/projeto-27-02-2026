# Generic Application Packer (Prototype)

This repository is intended as a starting point for a portable Windows application packer similar in concept to **Enigma VirtualBox**. The goal is to produce a single executable that contains an application and all of its dependencies. At runtime the application runs directly from memory with a virtual file system and virtualized registry, never writing files to disk.

> 🔧 _This is a research/proof‑of‑concept project; the real implementation requires deep WinAPI/PE knowledge and careful kernel‑level or API‑hooking code._

---

## Features (planned)

1. **Embedding resources.** Binary files (EXEs, DLLs, OCX, media, documents, etc.) will be packed into a host executable and optionally compressed (using zlib or similar).
2. **Virtual file system.** All requests to `CreateFile`, `ReadFile`, etc. are intercepted and served from an in‑memory archive. No files are extracted to disk.
3. **Registry virtualization.** Necessary registry keys are mapped to a private in‑memory store so the packed app can operate in isolation.
4. **Loader stub.** A small bootstrap loader prepares the environment and then transfers control to the embedded application entry point.
5. **Optional compression.** A generic compressor component is included to compress embedded resources.

## Project structure

```
projeto-27-02-2026/
├── CMakeLists.txt         # build configuration
├── README.md              # this document
└── src/
    ├── main.cpp           # entry point for the packer tool
    ├── GenericPacker.h    # high‑level packing API
    ├── GenericPacker.cpp  # implementation (compression + resource embedding)
    ├── VirtualFS.h        # stub for virtual file system
    ├── VirtualFS.cpp      # API intercepts (to be implemented)
    └── RegistryStub.h     # registry virtualization stub
```

Feel free to adapt the structure to your own build system (Visual Studio project, etc.).

## Building

A simple CMake configuration is provided. On Windows with Visual Studio:

```powershell
mkdir build; cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
```

## Next steps

1. **Design the packed format.** Decide how files and metadata will be stored (e.g. a TOC, offsets, compression flags). Consider using a custom section in the PE file or appending to the end of the host EXE.
2. **Implement the packer tool.** Read files, compress them, and write them into the chosen format.
3. **Write a loader stub.** Create a small PE that at runtime mounts the archive in memory and patches `LoadLibrary`/`CreateFile` etc. Libraries such as Microsoft Detours or manual inline hooking will be useful.
4. **Virtualization of registry/API calls.** This is the trickiest part; you'll need to intercept many WinAPI functions, and possibly use a kernel driver for complete transparency.

---

## Disclaimer

Developing such a tool involves advanced topics and must be done with caution. Many anti­virus engines flag packing/sandboxing technologies as potential malware. Ensure that you have the appropriate legal rights to redistribute any applications you pack.

---

_This README is a starting point for senior C++ developers exploring application virtualization._
