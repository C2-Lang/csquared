This is the plan that I will follow to develop Raven:

## Phase 1: first version of Raven
Following [the roadmap](https://git.ddoichita.dev/nykenik24/raven#roadmap) located in `README.md`, the first version of Raven focuses purely on:
- **Iteration**: iterating over and over and over until design is as good as it can get + has been demonstrated to be overall **good** and the compiler is fast and battle-tested.
- **Optimization**: 1) write something until it's finished 2) optimize 3) test, benchmark 4) repeat from step 2.

---
## Phase 2: further improvments
> **Not everything here is confirmed. Don't get excited, as I am not sure if everything here will be totally true. Although I CAN promise the standard library and maybe some of the tooling, like the LSP.**

After version 1 Raven will basically be done, although there will still be things to do:
- **Standard library**: the earliest after-v1 versions will be dedicated solely to standard library. I want to make Raven a batteries-included language (without too much bloat, I don't want to make Raven programs a RAM killer, specially with today's RAM prices cough cough <small>AI</small>. cough).
- **Tooling**: Raven obviously needs more than just the compiler for users to love it, because who would write an application in 2026 without LSP (Language Server Protocol, basically live errors, warnings and autocompletion), proper syntax highlighting and debugging/REPL tools? Some people (example: me), yes, but it's necessary that I do at least LSP.
- **Modules, dependencies, configuration**: as any mature language, I have planned adding a package system and module-based projects to Raven. What I mean exactly with a package system is the ability to download packages directly from the internet with a CLI, which can then be used inside the project. Module-based projects is basically a change in the structure of projects, with "modules" being present, and each module containing members of various files instead of each file being it's own module with it's own members. The auxiliary name is Aviary, but it will be confirmed when I get there.
- **Further optimization and enhancements**: Phase 1 *seems* enough to settle Raven's design, until you notice that the only way Raven is ever going to be used seriously is if it has already developed a community (even if small) that can give their honest feedback to improve Raven. A lot of languages are currently built by their community (Rust, Zig, Python...), once there is a community the developer(s) are basically forced to resolve as many issues and PRs (Pull Requests) as possible. I am not saying that I expect a community forming around Raven (although I would love that, not gonna lie).

---
## Phase 3: the stage 2 compiler
Once I consider Raven is ready to be ported to itself like other mature languages, I will do exactly that.

For those that didn't understand, up until this phase the pipeline is:\
Your `.rvn` files -> Compiler -> x86/ARM NASM executable (Linux, Windows or MacOS).

"Porting raven to itself", normally called self-hosting, converts the pipeline to:
1. Raven's source written in Raven -> Stage 1 compiler (most recent stable release of the C-written compiler) -> Stage-2 compiler
2. Your `.rvn` files -> Stage-2 compiler -> x86/ARM NASM executable (Linux, Windows or MacOS).

So, instead of building new Raven versions in the painful and not memory managed C, which I chose because it's the best option I know for Raven (would have written it in Rust, but I don't know how to use it and Raven is too ambitious for a first Rust project.), I just write it in Raven, compile that into a binary using the "old" compiler and then give you that binary so you can compile your Raven code.
