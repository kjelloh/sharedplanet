# Todo: Consider to document my installation of macOS mactex LaTeX document generation platform using the Brew package manager?

```#4a568246``` *As of 2022-06-06 16:57*

[mail plain/text](mail.txt)

{% raw %}
I want to discover if I may be tempted to generate LaTeX files as a cross platform document output (as an alternative to RTF or HTML)?

==&gt; Also see "Todo: Consider to document my installation of Linux Mint pdflatex LaTeX document generation platform using the apt-get package manager?"

1) This seems to be the console output of my successful Brew package manager installation of?

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro clang+llvm-14.0.0-x86_64-apple-darwin % brew install --cask mactex  
> Running \`brew update --preinstall\`...  
> ==&gt; **Auto-updated Homebrew!**  
> Updated 3 taps (helix-editor/helix, homebrew/core and freecad/freecad).  
> ==&gt; **New Formulae**  
> aws-nuke erlang@24 glibc@2.13 helmify mariadb@10.7 naml primecount stencil xkbcomp  
> bore-cli flix glider libabw mbt octosql release-it terramate xpipe  
> cxgo freecad/freecad/pyside2@5.15.3 goctl libapplewm mbw ohdear-cli sdl2_sound tinysearch yorkie  
> dbml-cli freecad/freecad/shiboken2@5.15.3 gokart libxcvt minimap2 opentelemetry-cpp sftpgo tradcpp  
> dotdrop gcc@12 groestlcoin libxfont2 mkfontscale pg_partman sse2neon ttmath  
> dtrx git-workspace hatch lndir monika pget stanc3 xcode-kotlin  
> ==&gt; **Updated Formulae**  
> Updated 1510 formulae.  
> ==&gt; **Deleted Formulae**  
> libzt

> ==&gt; **Tapping homebrew/cask**  
> Cloning into '/usr/local/Homebrew/Library/Taps/homebrew/homebrew-cask'...  
> remote: Enumerating objects: 644171, done.  
> remote: Counting objects: 100% (4/4), done.  
> remote: Compressing objects: 100% (3/3), done.  
> remote: Total 644171 (delta 1), reused 2 (delta 1), pack-reused 644167  
> Receiving objects: 100% (644171/644171), 304.82 MiB | 5.95 MiB/s, done.  
> Resolving deltas: 100% (456143/456143), done.  
> Tapped 4007 casks (4,079 files, 325.4MB).  
> ==&gt; **Caveats**  
> You must restart your terminal window for the installation of MacTex CLI tools to take effect.  
> Alternatively, Bash and Zsh users can run the command:

> eval "$(/usr/libexec/path_helper)"

> ==&gt; **Downloading <https://mirror.ctan.org/systems/mac/mactex/mactex-20220321.pkg>**  
> ==&gt; **Downloading from <https://laotzu.ftp.acc.umu.se/mirror/CTAN/systems/mac/mactex/mactex-20220321.pkg>**  
> ######################################################################## 100.0%  
> ==&gt; **Installing dependencies: jbig2dec, libidn, ghostscript**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/jbig2dec/manifests/0.19>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/jbig2dec/blobs/sha256:e1aed32e74617b0638751e69489b38dbcabd584f23961390a818bb85b412ffcd>**  
> ==&gt; **Downloading from <https://pkg-containers.githubusercontent.com/ghcr1/blobs/sha256:e1aed32e74617b0638751e69489b38dbcabd584f23961390a818bb85b412ffcd?se=2022-06-06T10%3A35%3A00Z&sig=LQYBR%2FeLEu34LmPCAUcPV%2B571w29V54UhjHe%2BDqUJqI%3D&sp=r&spr=https&sr=b&sv=2019-12-12>**  
> ######################################################################## 100.0%  
> ==&gt; **Installing ****jbig2dec**  
> ==&gt; **Pouring jbig2dec--0.19.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/jbig2dec/0.19: 13 files, 373.7KB  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/libidn/manifests/1.38>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/libidn/blobs/sha256:97ae6e40039b1abaa15ea01851a407c6330ece0687f436fcac14f2ed1ed7bfee>**  
> ==&gt; **Downloading from <https://pkg-containers.githubusercontent.com/ghcr1/blobs/sha256:97ae6e40039b1abaa15ea01851a407c6330ece0687f436fcac14f2ed1ed7bfee?se=2022-06-06T10%3A35%3A00Z&sig=1ikmHEHQTuT3vHUvVF51dCQWYYFKryg9MM%2FqPIyIUjc%3D&sp=r&spr=https&sr=b&sv=2019-12-12>**  
> ######################################################################## 100.0%  
> ==&gt; **Installing ****libidn**  
> ==&gt; **Pouring libidn--1.38.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/libidn/1.38: 73 files, 1MB  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/freetype/manifests/2.12.1>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/freetype/blobs/sha256:3d4afd3f040571ea464c7afc010be38faf77665f919a79f557369d2eceee13d1>**  
> ==&gt; **Downloading from <https://pkg-containers.githubusercontent.com/ghcr1/blobs/sha256:3d4afd3f040571ea464c7afc010be38faf77665f919a79f557369d2eceee13d1?se=2022-06-06T10%3A35%3A00Z&sig=8ojHIs%2Fz2DJXj90SLFwOyuzW1DmFukTSdpc3vchvEMw%3D&sp=r&spr=https&sr=b&sv=2019-12-12>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/fontconfig/manifests/2.14.0>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/fontconfig/blobs/sha256:6bd89f45f20c5739ba53348933f843d256383eb30b28723d1a64a23ad565b1bc>**  
> ==&gt; **Downloading from <https://pkg-containers.githubusercontent.com/ghcr1/blobs/sha256:6bd89f45f20c5739ba53348933f843d256383eb30b28723d1a64a23ad565b1bc?se=2022-06-06T10%3A35%3A00Z&sig=CBPc01NeADS8IoYtPCwys7qnTWK64j9xHPS9zNRNg4E%3D&sp=r&spr=https&sr=b&sv=2019-12-12>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/libtiff/manifests/4.4.0>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/libtiff/blobs/sha256:0498f901409378a7900653a581fba3f0779e37bd64337f45816764750ae90aa3>**  
> ==&gt; **Downloading from <https://pkg-containers.githubusercontent.com/ghcr1/blobs/sha256:0498f901409378a7900653a581fba3f0779e37bd64337f45816764750ae90aa3?se=2022-06-06T10%3A35%3A00Z&sig=gkbaMRT5%2Bg5tQgM46%2FDKsFsAP0FA99pnskAcLGxEsQg%3D&sp=r&spr=https&sr=b&sv=2019-12-12>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/little-cms2/manifests/2.13.1>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/little-cms2/blobs/sha256:0c50589e60d1fdc8e8ae52550c1ed0e9bbc68f77d105fa0180192d517cc5a85a>**  
> ==&gt; **Downloading from <https://pkg-containers.githubusercontent.com/ghcr1/blobs/sha256:0c50589e60d1fdc8e8ae52550c1ed0e9bbc68f77d105fa0180192d517cc5a85a?se=2022-06-06T10%3A35%3A00Z&sig=18sl1us3OMEQXvjhoiv2yEDHNmW6Uiy7gXZBUXtaskQ%3D&sp=r&spr=https&sr=b&sv=2019-12-12>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/openjpeg/manifests/2.5.0>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/openjpeg/blobs/sha256:e67b786522a005da2e0588e14b1db6a655ac183b33997e3f74e8020454ed73bf>**  
> ==&gt; **Downloading from <https://pkg-containers.githubusercontent.com/ghcr1/blobs/sha256:e67b786522a005da2e0588e14b1db6a655ac183b33997e3f74e8020454ed73bf?se=2022-06-06T10%3A35%3A00Z&sig=hzVmsjy9NadZvCIAG9%2FbCU1EIR%2FIEUJwu55vYgqjifA%3D&sp=r&spr=https&sr=b&sv=2019-12-12>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/ghostscript/manifests/9.56.1>**  
> ######################################################################## 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/ghostscript/blobs/sha256:3ac4eb5ecab09d810f5a866d6752d18a5cb6bb9ea4ffc2592f4cc77105633fe5>**  
> ==&gt; **Downloading from <https://pkg-containers.githubusercontent.com/ghcr1/blobs/sha256:3ac4eb5ecab09d810f5a866d6752d18a5cb6bb9ea4ffc2592f4cc77105633fe5?se=2022-06-06T10%3A35%3A00Z&sig=o3tf53eQ56zgQMnA4sc2y3%2FdJUesB2rsyui2YOg4kPM%3D&sp=r&spr=https&sr=b&sv=2019-12-12>**  
> ######################################################################## 100.0%  
> ==&gt; **Installing dependencies for ghostscript: ****freetype****, ****fontconfig****, ****libtiff****, ****little-cms2** **and ****openjpeg**  
> ==&gt; **Installing ghostscript dependency: ****freetype**  
> ==&gt; **Pouring freetype--2.12.1.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/freetype/2.12.1: 67 files, 2.3MB  
> ==&gt; **Installing ghostscript dependency: ****fontconfig**  
> ==&gt; **Pouring fontconfig--2.14.0.monterey.bottle.tar.gz**  
> ==&gt; **Regenerating font cache, this may take a while**  
> ==&gt; **/usr/local/Cellar/fontconfig/2.14.0/bin/fc-cache -frv**  
> 🍺 /usr/local/Cellar/fontconfig/2.14.0: 84 files, 2.3MB  
> ==&gt; **Installing ghostscript dependency: ****libtiff**  
> ==&gt; **Pouring libtiff--4.4.0.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/libtiff/4.4.0: 249 files, 4.5MB  
> ==&gt; **Installing ghostscript dependency: ****little-cms2**  
> ==&gt; **Pouring little-cms2--2.13.1.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/little-cms2/2.13.1: 21 files, 1.3MB  
> ==&gt; **Installing ghostscript dependency: ****openjpeg**  
> ==&gt; **Pouring openjpeg--2.5.0.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/openjpeg/2.5.0: 533 files, 13.9MB  
> ==&gt; **Installing ****ghostscript**  
> ==&gt; **Pouring ghostscript--9.56.1.monterey.bottle.tar.gz**  
> Error: The \`brew link\` step did not complete successfully  
> The formula built, but is not symlinked into /usr/local  
> Could not symlink bin/dvipdf  
> Target /usr/local/bin/dvipdf  
> already exists. You may want to remove it:  
> rm '/usr/local/bin/dvipdf'

> To force the link and overwrite all conflicting files:  
> brew link --overwrite ghostscript

> To list all files that would be deleted:  
> brew link --overwrite --dry-run ghostscript

> Possible conflicting files are:  
> /usr/local/bin/dvipdf  
> /usr/local/bin/eps2eps  
> /usr/local/bin/gs -&gt; /usr/local/bin/gs-noX11  
> /usr/local/bin/gsbj  
> /usr/local/bin/gsdj  
> /usr/local/bin/gsdj500  
> /usr/local/bin/gslj  
> /usr/local/bin/gslp  
> /usr/local/bin/gsnd  
> /usr/local/bin/lprsetup.sh  
> /usr/local/bin/pdf2dsc  
> /usr/local/bin/pdf2ps  
> /usr/local/bin/pf2afm  
> /usr/local/bin/pfbtopfa  
> /usr/local/bin/pphs  
> /usr/local/bin/printafm  
> /usr/local/bin/ps2ascii  
> /usr/local/bin/ps2epsi  
> /usr/local/bin/ps2pdf  
> /usr/local/bin/ps2pdf12  
> /usr/local/bin/ps2pdf13  
> /usr/local/bin/ps2pdf14  
> /usr/local/bin/ps2pdfwr  
> /usr/local/bin/ps2ps  
> /usr/local/bin/ps2ps2  
> /usr/local/bin/unix-lpr.sh  
> /usr/local/share/man/man1/dvipdf.1  
> /usr/local/share/man/man1/eps2eps.1 -&gt; /usr/local/share/man/man1/ps2ps.1  
> /usr/local/share/man/man1/gs.1  
> /usr/local/share/man/man1/gsbj.1 -&gt; /usr/local/share/man/man1/gslp.1  
> /usr/local/share/man/man1/gsdj.1 -&gt; /usr/local/share/man/man1/gslp.1  
> /usr/local/share/man/man1/gsdj500.1 -&gt; /usr/local/share/man/man1/gslp.1  
> /usr/local/share/man/man1/gslj.1 -&gt; /usr/local/share/man/man1/gslp.1  
> /usr/local/share/man/man1/gslp.1  
> /usr/local/share/man/man1/gsnd.1  
> /usr/local/share/man/man1/pdf2dsc.1  
> /usr/local/share/man/man1/pdf2ps.1  
> /usr/local/share/man/man1/pf2afm.1  
> /usr/local/share/man/man1/pfbtopfa.1  
> /usr/local/share/man/man1/printafm.1  
> /usr/local/share/man/man1/ps2ascii.1  
> /usr/local/share/man/man1/ps2epsi.1  
> /usr/local/share/man/man1/ps2pdf.1  
> /usr/local/share/man/man1/ps2pdf12.1 -&gt; /usr/local/share/man/man1/ps2pdf.1  
> /usr/local/share/man/man1/ps2pdf13.1 -&gt; /usr/local/share/man/man1/ps2pdf.1  
> /usr/local/share/man/man1/ps2pdf14.1 -&gt; /usr/local/share/man/man1/ps2pdf.1  
> /usr/local/share/man/man1/ps2pdfwr.1  
> /usr/local/share/man/man1/ps2ps.1  
> ==&gt; **Summary**  
> 🍺 /usr/local/Cellar/ghostscript/9.56.1: 679 files, 150.0MB  
> ==&gt; **Installing Cask ****mactex**  
> ==&gt; **Running installer for mactex; your password may be necessary.**  
> Package installers may write to any location; options such as \`--appdir\` are ignored.  
> Password:  
> installer: Package name is MacTeX  
> installer: choices changes file '/private/tmp/choices20220606-1612-e869ib.xml' applied  
> installer: Installing at base path /  
> installer: The install was successful.  
> 🍺 mactex was successfully installed!  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro clang+llvm-14.0.0-x86_64-apple-darwin %

...

{% endraw %}
