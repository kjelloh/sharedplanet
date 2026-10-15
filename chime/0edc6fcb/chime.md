# Todo: Consider to try if I can build freecad from scratch using the nix package manager?

```#0edc6fcb``` *As of 2025-03-10 14:02*

[mail plain/text](mail.txt)

{% raw %}
I am tempted to fix bugs in freecad myself and wonder if I can use freecad from the nix package manager to get a functioning build environment?

==&gt; Also see "[Consider to document my nix package manager installation on macOS apple silicone?](../d69dfb9b/chime.md)"

1) Consider to try the nix package manager provided freecad 1.0 (<https://search.nixos.org/packages?channel=24.11&show=freecad&from=0&size=50&sort=relevance&type=packages&query=freecad> )?

==&gt; It seems the nix package manager fails to provide a freecad package for 'my system' (only available for linux)?

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/freecad-playground % nix-shell -p freecad  
> **error:**  
> … while calling the '**derivationStrict**' builtin  
> **at ****&lt;nix/derivation-internal.nix&gt;:37:12**:  
> 36|  
> 37| strict = derivationStrict drvAttrs;  
> | **^**  
> 38|

> … while evaluating derivation '**shell**'  
> whose name attribute is located at **/nix/store/ldwapm29wjwan94c9nqjv57jssqrs0rh-nixpkgs/nixpkgs/pkgs/stdenv/generic/make-derivation.nix:375:7**

> … while evaluating attribute '**buildInputs**' of derivation '**shell**'  
> **at ****/nix/store/ldwapm29wjwan94c9nqjv57jssqrs0rh-nixpkgs/nixpkgs/pkgs/stdenv/generic/make-derivation.nix:422:7**:  
> 421| depsHostHost = elemAt (elemAt dependencies 1) 0;  
> 422| buildInputs = elemAt (elemAt dependencies 1) 1;  
> | **^**  
> 423| depsTargetTarget = elemAt (elemAt dependencies 2) 0;

> **(stack trace truncated; use '--show-trace' to show the full, detailed trace)**

> **error:** Package ‘freecad-1.0.0’ in /nix/store/ldwapm29wjwan94c9nqjv57jssqrs0rh-nixpkgs/nixpkgs/pkgs/by-name/fr/freecad/package.nix:187 is not available on the requested hostPlatform:  
> hostPlatform.config = "aarch64-apple-darwin"  
> package.meta.platforms = &#91;  
> "aarch64-linux"  
> "armv5tel-linux"  
> "armv6l-linux"  
> "armv7a-linux"  
> "armv7l-linux"  
> "i686-linux"  
> "loongarch64-linux"  
> "m68k-linux"  
> "microblaze-linux"  
> "microblazeel-linux"  
> "mips-linux"  
> "mips64-linux"  
> "mips64el-linux"  
> "mipsel-linux"  
> "powerpc64-linux"  
> "powerpc64le-linux"  
> "riscv32-linux"  
> "riscv64-linux"  
> "s390-linux"  
> "s390x-linux"  
> "x86_64-linux"  
> &#93;  
> package.meta.badPlatforms = &#91; &#93;  
> , refusing to evaluate.

> a) To temporarily allow packages that are unsupported for this system, you can use an environment variable  
> for a single invocation of the nix tools.

> $ export NIXPKGS_ALLOW_UNSUPPORTED_SYSTEM=1

> Note: When using \`nix shell\`, \`nix build\`, \`nix develop\`, etc with a flake,  
> then pass \`--impure\` in order to allow use of environment variables.

> b) For \`nixos-rebuild\` you can set  
> { nixpkgs.config.allowUnsupportedSystem = true; }  
> in configuration.nix to override this.

> c) For \`nix-env\`, \`nix-build\`, \`nix-shell\` or any other Nix command you can add  
> { allowUnsupportedSystem = true; }  
> to ~/.config/nixpkgs/config.nix.  
> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/freecad-playground %

...

{% endraw %}
